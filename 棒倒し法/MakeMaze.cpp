#include "MakeMaze.h"

vector<vector<int>> MakeMaze::GenerativeMaze(int width, int height)
{
    srand(time(NULL));
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

    // Mark start and goal cells
    maze[1][1] = Start;
    maze[width - 2][height - 2] = Goal;

    
    return maze;
}


void MakeMaze::DebugPrint(const vector<vector<int>>& maze)
{
    std::cout << "Width: " << maze.size() << std::endl;
    std::cout << "Height: " << maze[0].size() << std::endl;

    for (size_t y = 0; y < maze[0].size(); y++) {
        for (size_t x = 0; x < maze.size(); x++) {
            switch (maze[x][y]) {
            case Path:
                std::cout << "　";
                break;
            case Wall:
                std::cout << "■";
                break;
            case Start:
                std::cout << "Ｓ";
                break;
            case Goal:
                std::cout << "Ｇ";
                break;
            default:
                std::cout << "X";
                break;
            }
        }
        std::cout << std::endl;
    }
}
