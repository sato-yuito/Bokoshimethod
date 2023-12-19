#include "Astar.h"
#include <list>

bool Astar::IsVaild(int x, int y, const std::vector<std::vector<int>>& maze)
{
	return x >= 0 && x < maze.size() && y >= 0 && y < maze[0].size() && maze[x][y] != Wall;
}

int Astar::Heuristic(int x1, int Y1, int x2, int y2)
{
	return std::abs(x1 - x2) + std::abs(Y1 - y2);
}

std::vector< AStarCell> Astar::GetNeighbors(const  AStarCell& currentCell, const std::vector<std::vector<int>>& maze)
{
	std::vector< AStarCell> neighbors;

	int dx[] = { 0,1,0,-1 };
	int dy[] = { -1,0,1,0 };

	for (int i = 0; i < 4; ++i)
	{
		int ix = currentCell.x + dx[i];
		int iY = currentCell.y + dx[i];
		if (IsVaild(ix, iY, maze))
		{
			neighbors.emplace_back(ix, iY);
		}
	}
	return neighbors;
}


std::vector< AStarCell> Astar::FindPath(const std::vector<std::vector<int>>& maze, int startX, int startY, int goalX, int goalY)
{
	std::priority_queue< AStarCell> openSet;
	std::vector<std::vector<bool>> closeSet(maze.size(),std::vector<bool>(maze[0].size(), false));

	AStarCell start(startX, startY);
	AStarCell goal(goalX, goalY);
	openSet.push(start);
	

	while (!openSet.empty())
	{
		AStarCell current = openSet.top();
		openSet.pop();
		if (current.x == goalX && current.y == goalY)
		{

		}
		closeSet[current.x][current.y] = true;



		auto neighbors = GetNeighbors(current, maze);
		for (auto& neighbor : neighbors)
		{
			if (closeSet[neighbor.x][neighbor.y])
			{
				continue;
			}


			int tetativeG = current.g + 1;
			if (!IsVaild(neighbor.x, neighbor.y, maze) || tetativeG >= neighbor.g)
			{
				continue;
			}
			neighbor.g = tetativeG;
			neighbor.h = Heuristic(neighbor.x, neighbor.y, goal.x, goal.y);
			neighbor.f = neighbor.g + neighbor.h;
			neighbor.parent = &current;

			openSet.push(neighbor);
		}

	}
	return std::vector< AStarCell>();
}


std::vector< AStarCell> Astar::ReconstructPath(const  AStarCell& goal) {
	std::vector< AStarCell> path;
	for (const  AStarCell* current = &goal; current != nullptr; current = current->parent) {
		path.push_back(*current);
	}
	std::reverse(path.begin(), path.end());
	return path;
}