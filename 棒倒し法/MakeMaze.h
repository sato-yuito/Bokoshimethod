#pragma once
#include<iostream>
#include<vector>
#include<random>
#include<stdexcept>

using namespace std;
class MakeMaze
{
public:
	const int Path = 0;//��
	const int Wall = 1;//��
	const int randomvalue = 2;//������\�����邽�߂̕ϐ���
	const int od = 1;//���\�����邽�߂̕ϐ���
	vector<vector<int>>GenerativeMaze(int width, int height);//���H�𐶐�����֐�
	void DebugMaze(const vector<vector<int>>& maze);

};

