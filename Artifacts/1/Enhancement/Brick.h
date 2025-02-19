#pragma once

#include "entityEnumStrucs.h"

class Brick
{
public:
	

	Brick(float xx, float yy, float xw, float yw, int health);

	void drawBrick();

	bool takeHit();

	int getHP();

	float getX();

	float getY();

	float getxWidth();

	float getyWidth();

	void setX(float X);

private:
	color BrickColor();
	float x, y, xWidth, yWidth;
	int hp;
};
