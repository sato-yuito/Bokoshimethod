#pragma once
#include<iostream>
#include<vector>
#include<random>
#include<stdexcept>

using namespace std;
const int Path = 0;//“¹
const int Wall = 1;//•Ç

class MakeMaze
{
public:
	
	static vector<vector<int>>GenerativeMaze(int width, int height);//–À˜H‚ğ¶¬‚·‚éŠÖ”
	void DebugPrint(const std::vector<std::vector<int>>& maze);

};

