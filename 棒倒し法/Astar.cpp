#include "Astar.h"
#include <list>

bool Astar::IsVaild(int x, int y, const std::vector<std::vector<int>>& maze, int StartX, int startY, int goalX, int goalY)
{
	return x >= 0 && x < maze.size() && y >= 0 && y < maze[0].size() && maze[x][y] != Wall;
}

int Astar::Heuristic(int x1, int Y1, int x2, int y2)
{
	return std::abs(x1 - x2) + std::abs(Y1 - y2);
}

std::vector<Cell> Astar::GetNeighbors(const Cell& cell, const std::vector<std::vector<int>>& maze)
{
	std::vector<Cell>Neighbors;

	int dx[] = { 0,1,0,-1 };
	int dy[] = { -1,0,1,0 };

	for (int i = 0; i < 4; ++i)
	{

	}
}

std::vector<Cell> Astar::FindPath(const std::vector<std::vector<int>>& maze, int startX, int startY, int goalX, int goalY)
{
	
}
