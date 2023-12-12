#include "MakeMaze.h"
#include"Astar.h"
#include <iostream>

int main() {
    MakeMaze makemaze;

    int width, height;

    // ���[�U�[�ɖ��H�̕��ƍ�������͂�����
    std::cout << "Enter the width of the maze: ";
    std::cin >> width;

    std::cout << "Enter the height of the maze: ";
    std::cin >> height;

    // MakeMaze�N���X���g�p���Ė��H�𐶐�
    std::vector<std::vector<int>> maze = makemaze.GenerativeMaze(width, height);

    // �����������H���f�o�b�O�v�����g
    makemaze.DebugPrint(maze);

    return 0;
}
