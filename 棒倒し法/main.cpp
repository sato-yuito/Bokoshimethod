#include"MakeMaze.h"


int main()
{
    MakeMaze makemaze;
    int width = 15;
    int height = 15;
    std::vector<std::vector<int>> maze = makemaze.GenerativeMaze(width, height);
    makemaze.DebugPrint(maze);
    return 0;
}