#pragma once
#include<iostream>
#include<vector>
#include<random>
#include<stdexcept>

using namespace std;
class MakeMaze
{
public:
	const int Path = 0;//道
	const int Wall = 1;//壁
	const int randomvalue = 2;//偶数を表現するための変数名
	const int od = 1;//奇数を表現するための変数名
	vector<vector<int>>GenerativeMaze(int width, int height);//迷路を生成する関数
	void DebugMaze(const vector<vector<int>>& maze);

};

