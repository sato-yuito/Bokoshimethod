#include "MakeMaze.h"
#include "Astar.h"
#include <iostream>

int main() {
    MakeMaze makemaze;
    Astar astar;

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

   
    int startX, startY, goalX, goalY;

    std::cout << "スタート位置 (x y): ";
    std::cin >> startX >> startY;

    std::cout << "ゴール位置 (x y): ";
    std::cin >> goalX >> goalY;

    std::vector<AStarCell> path = astar.FindPath(maze, startX, startY, goalX, goalY);

    if (!path.empty()) {
        std::cout << "Found path: ";
        for (const auto& cell : path) {
            std::cout << "(" << cell.x << ", " << cell.y << ") ";
        }
        std::cout << std::endl;
    }
    else {
        std::cout << "Path not found." << std::endl;
    }

    return 0;
}

