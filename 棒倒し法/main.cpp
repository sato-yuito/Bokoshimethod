#include "MakeMaze.h"
#include"Astar.h"
#include <iostream>

int main() {
    MakeMaze makemaze;

    int width, height;

    // ユーザーに迷路の幅と高さを入力させる
    std::cout << "Enter the width of the maze: ";
    std::cin >> width;

    std::cout << "Enter the height of the maze: ";
    std::cin >> height;

    // MakeMazeクラスを使用して迷路を生成
    std::vector<std::vector<int>> maze = makemaze.GenerativeMaze(width, height);

    // 生成した迷路をデバッグプリント
    makemaze.DebugPrint(maze);

    return 0;
}
