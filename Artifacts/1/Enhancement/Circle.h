#pragma once

#include "Brick.h"

class Circle
{
public:

	float radius;
	int hp = 3;
	float x;
	float y;
	float speed = 0.01;
	float xFlip = 0.5f;
	float yFlip = 0.5f;
	int direction; // 1=up 2=right 3=down 4=left 5 = up right   6 = up left  7 = down right  8= down left

	Circle(double xx, double yy, double rr, int dir, float rad);

	//check collisions with bricks
	bool CheckCollision(Brick* brk);

	//check colissions with other circles
	bool CheckCollision(Circle* Cir);

	//changed to more realistic bounces off wall
	void MoveOneStep();

	void DrawCircle();

	color ballColor();

	int getHP();
};
