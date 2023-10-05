#pragma once
#include<iostream>
#include<vector>
#include<random>
#include<stdexcept>

using namespace std;
class MakeMaze
{
public:
	const int Path = 0;//“¹
	const int Wall = 1;//•Ç
	const int randomvalue = 2;//‹ô”‚ğ•\Œ»‚·‚é‚½‚ß‚Ì•Ï”–¼
	const int od = 1;//Šï”‚ğ•\Œ»‚·‚é‚½‚ß‚Ì•Ï”–¼
	vector<vector<int>>GenerativeMaze(int width, int height);//–À˜H‚ğ¶¬‚·‚éŠÖ”
	void DebugMaze(const vector<vector<int>>& maze);

};

