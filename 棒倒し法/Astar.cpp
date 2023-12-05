#include "Astar.h"
#include <list>

std::vector<Cell> Astar::FindPath(const std::vector<std::vector<int>>& maze, int startX, int startY, int goalX, int goalY)
{
    std::list<Cell>startlist;
    std::list<Cell>goallist;

    startlist.push_back(maze[startX][startY]);
}
