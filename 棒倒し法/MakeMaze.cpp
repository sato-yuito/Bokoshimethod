#include "MakeMaze.h"

vector<vector<int>> MakeMaze::GenerativeMaze(int width, int height)
{
	const int sizeMaze = 5;//5より小さかったら生成しない
	if (height < sizeMaze || width < sizeMaze)
	{
		throw out_of_range("迷路のサイズがちいさいので生成しません");
	}
    if (width % 2 == 0) width++;
    if (height % 2 == 0) height++;

	std::vector<std::vector<int>> maze(width, std::vector<int>(height, Path));
	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			if (x == 0 || y == 0 || x == width - 1 || y == height - 1)
				maze[x][y] = Wall;
		}
	}
    for (int x = 2; x < width - 1; x += 2) {
        for (int y = 2; y < height - 1; y += 2) {
            maze[x][y] = Wall;

            while (true) {
                int direction = (y == 2) ? std::rand() % 4 : std::rand() % 3;

                int wallX = x;
                int wallY = y;

                switch (direction) {
                case 0: // 右
                    wallX++;
                    break;
                case 1: // 下
                    wallY++;
                    break;
                case 2: // 左
                    wallX--;
                    break;
                case 3: // 上
                    wallY--;
                    break;
                }

                if (maze[wallX][wallY] != Wall) {
                    maze[wallX][wallY] = Wall;
                    break;
                }
            }
        }
    }

    return maze;
}

void MakeMaze::AStarMaze(const std::vector<std::vector<int>>& maze, int width, int height)
{
    std::priority_queue<Cell, std::vector<Cell>, std::greater<Cell>> openSet;
    std::vector<std::vector<Cell>> cameFrom(maze.size(), std::vector<Cell>(maze[0].size()));
}

void MakeMaze::DebugPrint(const vector<vector<int>>& maze)
{
    std::cout << "Width: " << maze.size() << std::endl;
    std::cout << "Height: " << maze[0].size() << std::endl;

    for (size_t y = 0; y < maze[0].size(); y++) {
        for (size_t x = 0; x < maze.size(); x++) {
            std::cout << (maze[x][y] == Wall ? "■" : "　");
        }
        std::cout << std::endl;
    }
}
