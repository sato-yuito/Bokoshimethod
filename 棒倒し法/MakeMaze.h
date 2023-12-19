#pragma once
#include<iostream>
#include<vector>
#include<random>
#include<stdexcept>
#include <queue>
#include <cmath>

using namespace std;

const int Path = 0;//道
const int Wall = 1;//壁
const int Start = 2;
const int Goal = 3;
const int Visited = 4;



class MakeMaze
{
protected:
	struct Cell {
		int x, y, f, g, h;
		// ソートのための比較演算子を定義
		bool operator>(const Cell& other) const {
			return f > other.f;
		}
	};

	int width;
	int height;
public:
	
	static vector<vector<int>>GenerativeMaze(int width, int height);//迷路を生成する関数
	void DebugPrint(const std::vector<std::vector<int>>& maze);

};

