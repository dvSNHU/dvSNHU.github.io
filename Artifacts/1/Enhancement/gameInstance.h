#pragma once

#include "Circle.h"
#include <vector>
#include <GLFW\glfw3.h>

using namespace std;

class gameInstance
{
public:

	gameInstance(int windowHeight, int windowWidth);

	~gameInstance();

	void launchInstance();





//private:
	GLFWwindow* window;

	int winHeight;
	int winWidth;

	float currentTime;
	float lastTime;
	float deltaTime;

	float xShift;

	vector<Circle*> world;
	vector<Brick*> Bricks;
	Brick* playerPlatform;

	int levelAchieved;
	bool inMenu;
	int menuOption;
	int maxOption;
	bool makeSelection;

	//cooldown for spawning a ball
	float pressCooldown;
	float cooldown;

	void generateBricks(levelLayout level);

	void handleCooldown();

	void mainMenu();

	void levelSelect();

	void gameLoop(int levelToPlay = 0);

	void processInput(GLFWwindow* window);

	void loadProgress();

	void saveProgress();

	void tickTheClock();




};

