#pragma once
#include"MakeMaze.h"
struct Cell
{
	int x, y;//セルの座標
	int g, h, f;//コスト計算に必要な奴
	Cell* cell;
	Cell(int x, int y) :x(x), y(y), g(0), h(0), f(0), cell(nullptr){}
	bool operator<(const Cell& other)const
	{
		return f > other.f;
	}
};
class Astar: public MakeMaze
{
private:
	bool IsVaild(int x, int y, const std::vector<std::vector<int>>& maze, int StartX, int startY, int goalX, int goalY);
	int Heuristic(int x1, int Y1, int x2, int y2);//A*ではヒューリスティック関数というものが必要らしい(調べた)
	// 与えられたセルの隣接するセルを取得する関数
	std::vector<Cell> GetNeighbors(const Cell& cell, const std::vector<std::vector<int>>& maze);

public:
	std::vector<Cell> FindPath(const std::vector<std::vector<int>>& maze, int startX, int startY, int goalX, int goalY);
};

