#include "gameInstance.h"
#include <vector>
#include "Circle.h"
#include "entityEnumStrucs.h"
#include <GLFW\glfw3.h>
#include <iostream>
#include <fstream>
#include <string>
#include "levels.h"
#include "menuElements.h"

using namespace std;

string PROGRESSFILENAME = "levelsAchieved.txt";



gameInstance::gameInstance(int windowHeight, int windowWidth)
{
	cooldown = 1.0f;
	pressCooldown = 0.0f;

	currentTime = glfwGetTime();
	lastTime = currentTime;
	inMenu = true;
	makeSelection = false;
	maxOption = 0;
	menuOption = 0;

	srand(currentTime);

	winWidth = windowWidth;
	winHeight = windowHeight;

	xShift = 0.0f;
	levelAchieved = 0;

	loadProgress();
}

gameInstance::~gameInstance()
{
	saveProgress();
}

void gameInstance::launchInstance()
{
	if (!glfwInit()) {
		exit(EXIT_FAILURE);
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	window = glfwCreateWindow(winWidth, winHeight, "Random World of Block Breaker", NULL, NULL);
	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);

	mainMenu();
}




//generate brick layout
void gameInstance::generateBricks(levelLayout level)
{

	int lines = level.lines;
	int seperation = level.seperation;
	int bricks = level.bricks;

	int hp = level.hp;

	bool alternate = level.alternate;




	float topBorder = 1.0f;
	float width = 0.2f;
	float height = 0.1f;
	float xPosition = 0.0f;
	float yPosition = 0.0f;
	Brick* brk;

	yPosition = topBorder - height * 2.0f;

	for (int i = 0; i < lines; i++)
	{
		xPosition = -((float)bricks * (float)width) / 2.0f;
		for (int j = 0; j < bricks; j++)
		{
			if (alternate)
			{
				if ((i + j) % 2)
				{
					brk = new Brick(xPosition, yPosition, width, height, hp);
					Bricks.push_back(brk);
					
				}
				xPosition += width * 1.1f;
			}
			else
			{
				brk = new Brick(xPosition, yPosition, width, height, hp);
				Bricks.push_back(brk);
				xPosition += width * 1.1f;
			}
		}
		yPosition -= height * (1.0f + seperation);
	}
}

void gameInstance::handleCooldown()
{
	if (pressCooldown != 0.0f)
	{
		pressCooldown -= deltaTime;

		if (pressCooldown < 0.0f)
			pressCooldown = 0.0f;
	}

}

void gameInstance::mainMenu()
{

	menuOption = 1;
	maxOption = 2;

	//Setup View
	float ratio;
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	ratio = width / (float)height;
	glViewport(0, 0, width, height);
	glClear(GL_COLOR_BUFFER_BIT);


	while (!makeSelection && !glfwWindowShouldClose(window))
	{

		tickTheClock();

		processInput(window);
		switch (menuOption)
		{
		case 1:
			drawPlay(0.6, -0.4, 1.0f, 0.0f, 0.0f);
			drawLevelSelect(0.8, 0.2, 1.0f, 1.0f, 1.0f);
			break;
		case 2:
			drawPlay(0.6, -0.4, 1.0f, 1.0f, 1.0f);
			drawLevelSelect(0.8, 0.2, 1.0f, 0.0f, 0.0f);
			break;
		default:
			cout << "default case triggerted! HOW!" << endl;
		}


		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	int levelToStart = 0;

	switch (menuOption)
	{
	case 1:
		inMenu = false;
		gameLoop();
		break;
	case 2:
		levelSelect();
		break;
	default:
		break;
	}




}

void gameInstance::levelSelect()
{
	makeSelection = false;

	menuOption = 1;
	maxOption = levelAchieved;

	//Setup View
	float ratio;
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	ratio = width / (float)height;
	glViewport(0, 0, width, height);
	glClear(GL_COLOR_BUFFER_BIT);

	glfwSwapBuffers(window);

	glfwGetFramebufferSize(window, &width, &height);
	ratio = width / (float)height;
	glViewport(0, 0, width, height);
	glClear(GL_COLOR_BUFFER_BIT);


	while (!makeSelection && !glfwWindowShouldClose(window))
	{

		tickTheClock();

		processInput(window);
		drawLevelLabels(menuOption, maxOption);


		//cout << menuOption << endl;


		
		glfwSwapBuffers(window);
		glfwPollEvents();

	}

	inMenu = false;


	cout << menuOption << endl;
	gameLoop(menuOption);





}

void gameInstance::gameLoop(int levelToPlay)
{

	//platform dimentions
	float platformWidth = 0.3f;
	float platformHeight = 0.05f;

	//add platform as first item 
	playerPlatform = new Brick(00.0, -0.75, platformWidth, platformHeight, -42);

	//make bricks call
	int currentLevel = levelToPlay - 1;
	int finalLevel = levels.size();


	while (!glfwWindowShouldClose(window)) {

		tickTheClock();

		//if there are no bricks load level and set next level to load
		if (Bricks.size() == 0)
		{
			world.clear();
			generateBricks(levels[currentLevel]);
			if (currentLevel > levelAchieved)
			{
				levelAchieved = currentLevel;
			}
			currentLevel++;
		}

		//Setup View
		float ratio;
		int width, height;
		glfwGetFramebufferSize(window, &width, &height);
		ratio = width / (float)height;
		glViewport(0, 0, width, height);
		glClear(GL_COLOR_BUFFER_BIT);

		processInput(window);

		//Movement
		for (int i = 0; i < world.size(); i++)
		{
			for (int j = 0; j < Bricks.size(); j++)
			{
				//check collision with player
				if (world[i]->CheckCollision(playerPlatform))
				{
					break;
				}

				//check collision with bricks
				if (world[i]->CheckCollision(Bricks[j]))
				{
					if (Bricks[j]->getHP() == 0)
					{
						Bricks.erase(Bricks.begin() + j);
					}
					
					break;
				}
			}
			if (world[i]->getHP() == 0)
			{
				world.erase(world.begin() + i);
				break;
			}

			//ball collisions
			for (int j = 0; j < world.size(); j++)
			{
				//skip if checking collision with self
				if (i == j)
				{
					continue;
				}

				world[i]->CheckCollision(world[j]);


			}

			world[i]->MoveOneStep();
			world[i]->DrawCircle();
		}


		//move platform and reset shift
		playerPlatform->setX(playerPlatform->getX() + xShift);
		xShift = 0.0f;

		//restrain platform to screen
		if (playerPlatform->getX() < -1.0f + (platformWidth / 2.0f))
		{
			playerPlatform->setX(-1.0f + (platformWidth / 2.0f));
		}
		else if (playerPlatform->getX() > 1.0f - (platformWidth / 2.0f))
		{
			playerPlatform->setX(1.0f - (platformWidth / 2.0f));
		}


		playerPlatform->drawBrick();

		//draw bricks
		for (int f = 0; f < Bricks.size(); f++)
		{
			if (Bricks[f]->getHP() != 0)
			{
				Bricks[f]->drawBrick();
			}
		}

		//cout << world.size() << endl;

		glfwSwapBuffers(window);
		glfwPollEvents();

	}

	glfwDestroyWindow(window);
	glfwTerminate;
}

void gameInstance::processInput(GLFWwindow* window)
{

	cout << pressCooldown << endl;

	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
		

	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS && pressCooldown == 0.0f)
	{

			Circle* B = new Circle(0.0, -0.75, 02, 2, 0.05);
			world.push_back(B);

			pressCooldown = cooldown;

		
	}

	if (glfwGetKey(window, GLFW_KEY_ENTER) == GLFW_PRESS)
	{
		if (inMenu && pressCooldown == 0.0f)
		{
			makeSelection = true;

			pressCooldown = 1.0f;
		}
	}

	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{

			xShift = -0.01f;

	}

	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	{

			xShift = 0.01f;

	}

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	{
		if (inMenu && (menuOption > 1) && (pressCooldown == 0.0f))
		{
			menuOption--;
			pressCooldown = 0.25f;
		}

	}

	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	{
		if (inMenu && (menuOption < maxOption) && (pressCooldown == 0.0f))
		{
			menuOption++;
			pressCooldown = 0.25f;
		}

	}

	if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS)
	{
		if (inMenu && (maxOption >= 1))
		{
			menuOption = 1;
		}

	}

	if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS)
	{
		if (inMenu && (maxOption >= 2))
		{
			menuOption = 2;
		}

	}

	if (glfwGetKey(window, GLFW_KEY_3) == GLFW_PRESS)
	{
		if (inMenu && (maxOption >= 3))
		{
			menuOption = 3;
		}

	}

	if (glfwGetKey(window, GLFW_KEY_4) == GLFW_PRESS)
	{
		if (inMenu && (maxOption >= 4))
		{
			menuOption = 4;
		}

	}

	if (glfwGetKey(window, GLFW_KEY_5) == GLFW_PRESS)
	{
		if (inMenu && (maxOption >= 5))
		{
			menuOption = 5;
		}

	}

}

void gameInstance::loadProgress()
{

	ifstream ifile(PROGRESSFILENAME);

	if (ifile.is_open())
	{
		string line;
		getline(ifile, line);

		int level = atoi(line.c_str());

		levelAchieved = level;



		ifile.close();
	}
	else
	{
		ofstream ofile(PROGRESSFILENAME);
		ofile << 1;
		ofile.close();
	}

}

void gameInstance::saveProgress()
{
	ofstream ofile(PROGRESSFILENAME);

	if (ofile.is_open())
	{
		ofile << levelAchieved;
	}
	else
	{
		cerr << "Couldnt open " << PROGRESSFILENAME << " to save progress!";
	}
}

void gameInstance::tickTheClock()
{
	currentTime = glfwGetTime();
	deltaTime = currentTime - lastTime;
	lastTime = currentTime;

	handleCooldown();
}
