#include"MakeMaze.h"

int main()
{
	int width = 15;
	int height = 15;
	std::vector<std::vector<int>> maze = MakeMaze::GenerativeMaze(width, height);
	DebugMaze(maze);
	return 0;
}