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
	static vector<vector<int>>GenerativeMaze(int width, int height);//���H�𐶐�����֐�
	void DebugPrint(const std::vector<std::vector<int>>& maze);

};

