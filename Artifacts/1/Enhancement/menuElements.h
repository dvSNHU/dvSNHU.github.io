#pragma once

#include <GLFW\glfw3.h>

void drawI(float x, float y, float r, float g, float b)
{
	//I
	glColor3d(r, g, b);
	glBegin(GL_POLYGON);
	glVertex2d(0 - x, 0 - y);
	glVertex2d(0.1 - x, 0 - y);
	glVertex2d(0.1 - x, 0.5 - y);
	glVertex2d(0 - x, 0.5 - y);
	glEnd();
}

void drawV(float x, float y, float r, float g, float b)
{
	//V
	glColor3d(r, g, b);
	glBegin(GL_POLYGON);
	glVertex2d(0.1 - x, 0 - y);
	glVertex2d(0 - x, 0.5 - y);
	glVertex2d(0.1 - x, 0.5 - y);
	glVertex2d(0.2 - x, 0 - y);
	glEnd();

	glColor3d(r, g, b);
	glBegin(GL_POLYGON);
	glVertex2d(0.1 - x, 0 - y);
	glVertex2d(0.2 - x, 0.5 - y);
	glVertex2d(0.3 - x, 0.5 - y);
	glVertex2d(0.2 - x, 0 - y);
	glEnd();
}

void drawPlay(float x, float y, float r, float g, float b)
{
	//P
	glColor3d(r, g, b);
	glBegin(GL_POLYGON);
	glVertex2d(0-x, 0 - y);
	glVertex2d(0-x, 0.5 - y);
	glVertex2d(0.1-x, 0.5 - y);
	glVertex2d(0.1-x, 0 - y);
	glEnd();
	
	glBegin(GL_POLYGON);
	glVertex2d(0.1-x, 0.4 - y);
	glVertex2d(0.1-x, 0.5 - y);
	glVertex2d(0.3-x, 0.5 - y);
	glVertex2d(0.3-x, 0.4 - y);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2d(0.1-x, 0.2 - y);
	glVertex2d(0.1-x, 0.3 - y);
	glVertex2d(0.3-x, 0.3 - y);
	glVertex2d(0.3-x, 0.2 - y);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2d(0.2-x, 0.3 - y);
	glVertex2d(0.2-x, 0.4 - y);
	glVertex2d(0.3-x, 0.4 - y);
	glVertex2d(0.3-x, 0.3 - y);
	glEnd();

	//L
	glColor3d(r, g, b);
	glBegin(GL_POLYGON);
	glVertex2d(0.4-x, 0 - y);
	glVertex2d(0.4-x, 0.5 - y);
	glVertex2d(0.5-x, 0.5 - y);
	glVertex2d(0.5-x, 0 - y);
	glEnd();

	//A
	glColor3d(r, g, b);
	glBegin(GL_POLYGON);
	glVertex2d(0.6 - x, 0 - y);
	glVertex2d(0.7 - x, 0.5 - y);
	glVertex2d(0.8 - x, 0.5 - y);
	glVertex2d(0.7 - x, 0 - y);
	glEnd();

	glColor3d(r, g, b);
	glBegin(GL_POLYGON);
	glVertex2d(0.8 - x, 0 - y);
	glVertex2d(0.7 - x, 0.5 - y);
	glVertex2d(0.8 - x, 0.5 - y);
	glVertex2d(0.9 - x, 0 - y);
	glEnd();

	//Y
	glColor3d(r, g, b);
	glBegin(GL_POLYGON);
	glVertex2d(1 - x, 0.25 - y);
	glVertex2d(0.9 - x, 0.5 - y);
	glVertex2d(1 - x, 0.5 - y);
	glVertex2d(1.1 - x, 0.25 - y);
	glEnd();

	glColor3d(r, g, b);
	glBegin(GL_POLYGON);
	glVertex2d(1 - x, 0.25 - y);
	glVertex2d(1.1 - x, 0.5 - y);
	glVertex2d(1.2 - x, 0.5 - y);
	glVertex2d(1.1 - x, 0.25 - y);
	glEnd();

	glColor3d(r, g, b);
	glBegin(GL_POLYGON);
	glVertex2d(1.0 - x, 0 - y);
	glVertex2d(1.0 - x, 0.25 - y);
	glVertex2d(1.1 - x, 0.25 - y);
	glVertex2d(1.1 - x, 0 - y);
	glEnd();
}

void drawLevelSelect(float x, float y, float r, float g, float b)
{
	//L
	glColor3d(r, g, b);
	glBegin(GL_POLYGON);
	glVertex2d(0 - x, 0 - y);
	glVertex2d(0 - x, 0.5 - y);
	glVertex2d(0.1 - x, 0.5 - y);
	glVertex2d(0.1 - x, 0 - y);
	glEnd();

	//E
	glColor3d(r, g, b);
	glBegin(GL_POLYGON);
	glVertex2d(0.2 - x, 0 - y);
	glVertex2d(0.2 - x, 0.5 - y);
	glVertex2d(0.3 - x, 0.5 - y);
	glVertex2d(0.3 - x, 0 - y);
	glEnd();

	glColor3d(r, g, b);
	glBegin(GL_POLYGON);
	glVertex2d(0.3 - x, 0.5 - y);
	glVertex2d(0.3 - x, 0.4 - y);
	glVertex2d(0.4 - x, 0.4 - y);
	glVertex2d(0.4 - x, 0.5 - y);
	glEnd();

	glColor3d(r, g, b);
	glBegin(GL_POLYGON);
	glVertex2d(0.3 - x, 0.2 - y);
	glVertex2d(0.3 - x, 0.3 - y);
	glVertex2d(0.4 - x, 0.3 - y);
	glVertex2d(0.4 - x, 0.2 - y);
	glEnd();

	glColor3d(r, g, b);
	glBegin(GL_POLYGON);
	glVertex2d(0.3 - x, 0 - y);
	glVertex2d(0.3 - x, 0.1 - y);
	glVertex2d(0.4 - x, 0.1 - y);
	glVertex2d(0.4 - x, 0 - y);
	glEnd();

	//V
	glColor3d(r, g, b);
	glBegin(GL_POLYGON);
	glVertex2d(0.6 - x, 0 - y);
	glVertex2d(0.5 - x, 0.5 - y);
	glVertex2d(0.6 - x, 0.5 - y);
	glVertex2d(0.7 - x, 0 - y);
	glEnd();

	glColor3d(r, g, b);
	glBegin(GL_POLYGON);
	glVertex2d(0.6 - x, 0 - y);
	glVertex2d(0.7 - x, 0.5 - y);
	glVertex2d(0.8 - x, 0.5 - y);
	glVertex2d(0.7 - x, 0 - y);
	glEnd();

	
	//E
	glColor3d(r, g, b);
	glBegin(GL_POLYGON);
	glVertex2d(0.9 - x, 0 - y);
	glVertex2d(0.9 - x, 0.5 - y);
	glVertex2d(1 - x, 0.5 - y);
	glVertex2d(1 - x, 0 - y);
	glEnd();

	glColor3d(r, g, b);
	glBegin(GL_POLYGON);
	glVertex2d(1 - x, 0.5 - y);
	glVertex2d(1 - x, 0.4 - y);
	glVertex2d(1.1 - x, 0.4 - y);
	glVertex2d(1.1 - x, 0.5 - y);
	glEnd();

	glColor3d(r, g, b);
	glBegin(GL_POLYGON);
	glVertex2d(1 - x, 0.2 - y);
	glVertex2d(1 - x, 0.3 - y);
	glVertex2d(1.1 - x, 0.3 - y);
	glVertex2d(1.1 - x, 0.2 - y);
	glEnd();

	glColor3d(r, g, b);
	glBegin(GL_POLYGON);
	glVertex2d(1 - x, 0 - y);
	glVertex2d(1 - x, 0.1 - y);
	glVertex2d(1.1 - x, 0.1 - y);
	glVertex2d(1.1 - x, 0 - y);
	glEnd();
	 
	//L
	glColor3d(r, g, b);
	glBegin(GL_POLYGON);
	glVertex2d(1.2 - x, 0 - y);
	glVertex2d(1.2 - x, 0.5 - y);
	glVertex2d(1.3 - x, 0.5 - y);
	glVertex2d(1.3 - x, 0 - y);
	glEnd();

	//S
	glColor3d(r, g, b);
	glBegin(GL_POLYGON);
	glVertex2d(1.4 - x, 0 - y);
	glVertex2d(1.4 - x, 0.1 - y);
	glVertex2d(1.6 - x, 0.1 - y);
	glVertex2d(1.6 - x, 0 - y);
	glEnd();

	glColor3d(r, g, b);
	glBegin(GL_POLYGON);
	glVertex2d(1.5 - x, 0.1 - y);
	glVertex2d(1.5 - x, 0.3 - y);
	glVertex2d(1.6 - x, 0.3 - y);
	glVertex2d(1.6 - x, 0.1 - y);
	glEnd();

	glColor3d(r, g, b);
	glBegin(GL_POLYGON);
	glVertex2d(1.4 - x, 0.2 - y);
	glVertex2d(1.4 - x, 0.4 - y);
	glVertex2d(1.5 - x, 0.4 - y);
	glVertex2d(1.5 - x, 0.2 - y);
	glEnd();

	glColor3d(r, g, b);
	glBegin(GL_POLYGON);
	glVertex2d(1.4 - x, 0.4 - y);
	glVertex2d(1.4 - x, 0.5 - y);
	glVertex2d(1.6 - x, 0.5 - y);
	glVertex2d(1.6 - x, 0.4 - y);
	glEnd();

}

void drawLevelLabels(int option, int max) {
	float r = 1.0f;
	float g = 1.0f;
	float b = 1.0f;

	if (option == 1) {
		r = 1;
		g = 0;
		b = 0;
	}
	else
	{
		r = 1;
		g = 1;
		b = 1;
	}

	//1
	drawI(0.5, -0.5, r, g, b);

	if (option == 2) {
		r = 1;
		g = 0;
		b = 0;
	}
	else if (max < 2)
	{
		r = 0.25;
		g = 0.25;
		b = 0.25;
	}
	else
	{
		r = 1;
		g = 1;
		b = 1;
	}

	//2
	drawI(-0.4, -0.5, r, g, b);
	drawI(-0.6, -0.5, r, g, b);

	if (option == 3) {
		r = 1;
		g = 0;
		b = 0;
	}
	else if (max < 3)
	{
		r = 0.25;
		g = 0.25;
		b = 0.25;
	}
	else
	{
		r = 1;
		g = 1;
		b = 1;
	}

	//3
	drawI(0.7, 0.25, r, g, b);
	drawI(0.5, 0.25, r, g, b);
	drawI(0.3, 0.25, r, g, b);

	if (option == 4) {
		r = 1;
		g = 0;
		b = 0;
	}
	else if (max < 4)
	{
		r = 0.25;
		g = 0.25;
		b = 0.25;
	}
	else
	{
		r = 1;
		g = 1;
		b = 1;
	}

	//4
	drawI(-0.3, 0.25, r, g, b);
	drawV(-0.5, 0.25, r, g, b);

	if (option == 5) {
		r = 1;
		g = 0;
		b = 0;
	}
	else if (max < 5)
	{
		r = 0.25;
		g = 0.25;
		b = 0.25;
	}
	else
	{
		r = 1;
		g = 1;
		b = 1;
	}

	//5
	drawV(0.15, 1, r, g, b);
	

}



void drawExit(float x, float y, float r, float g, float b) {

}

void waitS(int sec)
{
	int timer = sec;
	int startTime = glfwGetTime();
	int newTime = 0;


	while (true)
	{

		newTime = glfwGetTime();

		if ((newTime - startTime) > sec)
		{
			break;
		}

	};
}