#pragma once

#include <string>
struct color
{
	float rr;
	float gg;
	float bb;
};


struct levelLayout
{
	int lines;
	int seperation;
	int bricks;

	int hp;

	bool alternate;

	std::string printOutput()
	{
		return std::to_string(lines) + ":" + std::to_string(seperation) + ":" + std::to_string(bricks)
			+ ":" + std::to_string(hp) + ":" + std::to_string(alternate);
	}
};