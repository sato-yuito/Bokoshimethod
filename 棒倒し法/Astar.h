#pragma once
#include"MakeMaze.h"

struct AStarCell
{
	int x, y;//�Z���̍��W
	int g, h, f;//�R�X�g�v�Z�ɕK�v�ȓz
	AStarCell* parent;
	
	AStarCell(int x, int y) :x(x), y(y), g(0), h(0), f(0), parent(nullptr){}
	bool operator<(const AStarCell& other)const
	{
		return f > other.f;
	}
};
class Astar: public MakeMaze
{
private:
	bool IsVaild(int x, int y, const std::vector<std::vector<int>>& maze);
	int Heuristic(int x1, int Y1, int x2, int y2);//A*�ł̓q���[���X�e�B�b�N�֐��Ƃ������̂��K�v�炵��(���ׂ�)
	// �^����ꂽ�Z���̗אڂ���Z�����擾����֐�
	std::vector< AStarCell> GetNeighbors(const  AStarCell& currentCell, const std::vector<std::vector<int>>& maze);
public:
	std::vector< AStarCell> FindPath(const std::vector<std::vector<int>>& maze, int startX, int startY, int goalX, int goalY);
	std::vector< AStarCell> ReconstructPath(const  AStarCell& goal);
};

