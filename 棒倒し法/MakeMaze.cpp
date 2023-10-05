#include "MakeMaze.h"

vector<vector<int>> MakeMaze::GenerativeMaze(int width, int height)
{
	const int sizeMaze = 5;//5より小さかったら生成しない
	if (height < sizeMaze || width < sizeMaze)
	{
		throw out_of_range("迷路のサイズがちいさいので生成しません");
	}
	if (width % randomvalue == 0)
		width += od;
	if (height % randomvalue == 0)
		height += od;

	std::vector<std::vector<int>> maze(width, std::vector<int>(height, Path));
	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			if (x == 0 || y == 0 || x == width - randomvalue || y == height - randomvalue)
				maze[x][y] = Wall;
			else
				maze[x][y] = Path;
		}
	}
    std::random_device rd;
    std::mt19937 mt(rd());
    for (int x = randomvalue; x < width - randomvalue; x += randomvalue) {
        for (int y = randomvalue; y < height - randomvalue; y += randomvalue) {
            maze[x][y] = Wall;

            while (true) {
                int direction;
                if (y == Even)
                    direction = mt() % 4;
                else
                    direction = mt() % 3;

                int wallX = x;
                int wallY = y;
                switch (direction) {
                case 0: // 右
                    wallX += Even;
                    break;
                case 1: // 下
                    wallY += Even;
                    break;
                case 2: // 左
                    wallX -= Even;
                    break;
                case 3: // 上
                    wallY -= Even;
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

void MakeMaze::DebugMaze(const vector<vector<int>>& maze)
{
	std::cout << "Width: " << maze.size() << std::endl;
	std::cout << "Height: " << maze[0].size() << std::endl;
	for (int y = 0; y < maze[0].size(); y++) {
		for (int x = 0; x < maze.size(); x++) {
			std::cout << (maze[x][y] == Wall ? "■" : "　");
		}
		std::cout << std::endl;
	}
}
