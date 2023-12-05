#pragma once
#include<iostream>
#include<vector>
#include<random>
#include<stdexcept>
#include <queue>
#include <cmath>

using namespace std;

const int Path = 0;//“¹
const int Wall = 1;//•Ç
const int Start = 2;
const int Goal = 3;
const int Visited = 4;

struct Cell {
	int x, y, f, g, h;
	// ƒ\[ƒg‚Ì‚½‚ß‚Ì”äŠr‰‰Zq‚ğ’è‹`
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
	
	static vector<vector<int>>GenerativeMaze(int width, int height);//–À˜H‚ğ¶¬‚·‚éŠÖ”
	void DebugPrint(const std::vector<std::vector<int>>& maze);

};

