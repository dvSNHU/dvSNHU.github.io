#include "Circle.h"
#include <GLFW\glfw3.h>
#include "linmath.h"
#include <cmath>
#include "entityEnumStrucs.h"
#include "Brick.h"



Circle::Circle(double xx, double yy, double rr, int dir, float rad)
{
	x = xx;
	y = yy;
	radius = rr;
	radius = rad;
	direction = dir;
}





bool Circle::CheckCollision(Brick * brk)
{
	float xB = brk->getX();
	float yB = brk->getY();
	float xHalfWidth = brk->getxWidth();
	float yHalfWidth = brk->getyWidth();
	float leftValue = xB - xHalfWidth;
	float rightValue = xB + xHalfWidth;
	float topValue = yB + yHalfWidth;
	float bottomValue = yB - yHalfWidth;

	if ((x > leftValue && x < rightValue) && (y < topValue && y > bottomValue) && (brk->getHP() != 0))
	{

		if (x - xB < 0)
		{
			xFlip = -0.5f;

			if (y - yB < 0)
			{
				yFlip = -0.5f;
			}
			else
			{
				yFlip = 0.5f;
			}

		}
		else
		{
			xFlip = 0.5f;


			if (y - yB < 0)
			{
				yFlip = -0.5f;
			}
			else
			{
				yFlip = 0.5f;
			}
		}

		switch (brk->getHP())
		{
		case -42:
			break;
		default:
			brk->takeHit();
			hp -= 1;
			break;
		}





		return true;
	}
	return false;

}

bool Circle::CheckCollision(Circle* Cir)
{
	float width = Cir->radius;
	float xC = Cir->x;
	float yC = Cir->y;

	float leftValue = xC - width;
	float rightValue = xC + width;
	float topValue = yC + width;
	float bottomValue = yC - width;


	if ((x > leftValue && x < rightValue) && (y < topValue && y > bottomValue))
	{
		if (xFlip == Cir->xFlip)
		{
			if (yFlip != Cir->yFlip)
			{
				yFlip += -2 * yFlip;
				Cir->yFlip += -2 * yFlip;
			}
		}
		else
		{
			xFlip += -2 * xFlip;
			Cir->xFlip += -2 * xFlip;

			if (yFlip != Cir->yFlip)
			{
				yFlip += -2 * yFlip;
				Cir->yFlip += -2 * yFlip;
			}
		}
		return true;
	}

	return false;
}

void Circle::MoveOneStep()
{
	x += (speed * xFlip);
	y += (speed * yFlip);

	if (x > 1 - radius || x < -1 + radius)
	{
		xFlip = -xFlip;
	}

	if (y > 1 - radius || y < -1 + radius)
	{
		yFlip = -yFlip;
	}

}

void Circle::DrawCircle()
{
	color C;
	C = ballColor();
	glColor3f(C.rr, C.gg, C.bb);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++) {
		float degInRad = i * (3.14159 / 180);
		glVertex2f((cos(degInRad) * radius) + x, (sin(degInRad) * radius) + y);
	}
	glEnd();
}

color Circle::ballColor()
{
	color C;
	switch (hp)
	{
	case 0:



		break;
	case 1:
		C.rr = 1.0f;
		C.gg = 0.0f;
		C.bb = 0.0f;

		break;
	case 2:
		C.rr = 0.0f;
		C.gg = 0.0f;
		C.bb = 1.0f;

		break;
	case 3:
		C.rr = 0.0f;
		C.gg = 1.0f;
		C.bb = 0.0f;

		break;
	default:
		C.rr = 0.0f;
		C.gg = 0.0f;
		C.bb = 0.0f;

		break;
	}
	return C;
}

int Circle::getHP()
{
	return hp;
}