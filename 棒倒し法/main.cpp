#include "MakeMaze.h"
#include "Astar.h"
#include <iostream>

int main() {
    MakeMaze makemaze;
    Astar astar;

    int width, height;

    // ���[�U�[�ɖ��H�̕��ƍ�������͂�����
    std::cout << "�D���ȕ�����͂��Ă�������: ";
    std::cin >> width;

    std::cout << "�D���ȍ�������͂��Ă�������: ";
    std::cin >> height;

    // MakeMaze�N���X���g�p���Ė��H�𐶐�
    std::vector<std::vector<int>> maze = makemaze.GenerativeMaze(width, height);

    // �����������H���f�o�b�O�v�����g
    makemaze.DebugPrint(maze);

   
    int startX, startY, goalX, goalY;

    std::cout << "�X�^�[�g�ʒu (x y): ";
    std::cin >> startX >> startY;

    std::cout << "�S�[���ʒu (x y): ";
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

