#include "MakeMaze.h"
#include"Astar.h"
#include <iostream>

int main() {
    MakeMaze makemaze;

    int width, height;

    // ユーザーに迷路の幅と高さを入力させる
    std::cout << "好きな幅を入力してください: ";
    std::cin >> width;

    std::cout << "好きな高さを入力してください: ";
    std::cin >> height;

    // MakeMazeクラスを使用して迷路を生成
    std::vector<std::vector<int>> maze = makemaze.GenerativeMaze(width, height);

    // 生成した迷路をデバッグプリント
    makemaze.DebugPrint(maze);

    

    
    return 0;
}
