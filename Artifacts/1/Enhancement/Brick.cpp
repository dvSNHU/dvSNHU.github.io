#include "Brick.h"
#include "entityEnumStrucs.h"
#include <GLFW\glfw3.h>

Brick::Brick(float xx, float yy, float xw, float yw, int health)
{
	x = xx; y = yy, xWidth = xw; yWidth = yw;
	hp = health;
};

color Brick::BrickColor()
{

	color C;
	switch (hp) {
	case 3:
		C.rr = 0.0f;
		C.gg = 1.0f;
		C.bb = 0.0f;

		break;
	case 2:
		C.rr = 0.0f;
		C.gg = 0.0f;
		C.bb = 1.0f;

		break;
	case 1:
		C.rr = 1.0f;
		C.gg = 0.0f;
		C.bb = 0.0f;

		break;
	case -42:
		C.rr = 1.0f;
		C.gg = 1.0f;
		C.bb = 1.0f;
		break;
	default:
		C.rr = 0.0f;
		C.gg = 0.0f;
		C.bb = 0.0f;
	}
	return C;
}

void Brick::drawBrick()
{

	float xhalfside = xWidth / 2;
	float yhalfside = yWidth / 2;
	color C = BrickColor();

	glColor3d(C.rr, C.gg, C.bb);
	glBegin(GL_POLYGON);

	glVertex2d(x + xhalfside, y + yhalfside);
	glVertex2d(x + xhalfside, y - yhalfside);
	glVertex2d(x - xhalfside, y - yhalfside);
	glVertex2d(x - xhalfside, y + yhalfside);

	glEnd();
}

//returns true if health hits zero
bool Brick::takeHit()
{
	hp -= 1;

	if (hp == 0)
	{
		return true;
	}
	return false;
}
int Brick::getHP(){return hp;}

float Brick::getX(){return x;}

float Brick::getY(){return y;}

float Brick::getxWidth(){return xWidth;}

float Brick::getyWidth(){return yWidth;}

void Brick::setX(float X)
{
	x = X;
}
