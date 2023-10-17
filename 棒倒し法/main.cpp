#include"MakeMaze.h"

int main()
{
	MakeMaze mazeGenerator;
	int width = 15;
	int height = 15;
	std::vector<std::vector<int>> maze = mazeGenerator.GenerativeMaze(width, height);
	mazeGenerator.DebugMaze(maze);
	return 0;
}