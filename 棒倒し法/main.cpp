#include "MakeMaze.h"
#include"Astar.h"
#include <iostream>

int main() {
    MakeMaze makemaze;

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

    

    
    return 0;
}
