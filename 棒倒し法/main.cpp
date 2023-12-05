#include"MakeMaze.h"


int main()
{
    MakeMaze makemaze;
    int width;
    cin >> width;
  
   
    int height;
    cin >> height;
    std::vector<std::vector<int>> maze = makemaze.GenerativeMaze(width, height);
    makemaze.DebugPrint(maze);
    return 0;
}