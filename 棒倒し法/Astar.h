#pragma once
#include"MakeMaze.h"
class Astar: public MakeMaze
{
	std::vector<Cell> FindPath(const std::vector<std::vector<int>>& maze, int startX, int startY, int goalX, int goalY);
};

