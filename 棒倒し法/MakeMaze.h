#pragma once
#include<iostream>
#include<vector>
#include<random>
#include<stdexcept>
#include <queue>
#include <cmath>

using namespace std;

const int Path = 0;//��
const int Wall = 1;//��
const int Start = 2;
const int Goal = 3;
const int Visited = 4;

struct Cell {
	int x, y, f, g, h;
	// �\�[�g�̂��߂̔�r���Z�q���`
	bool operator>(const Cell& other) const {
		return f > other.f;
	}
};

class MakeMaze
{
protected:
	int width;
	int height;
public:
	
	static vector<vector<int>>GenerativeMaze(int width, int height);//���H�𐶐�����֐�
	void DebugPrint(const std::vector<std::vector<int>>& maze);

};

