#pragma once
#include "02_Tetris_DefineBlock.h"

void CursorView(char show);
void gotoxy(int x, int y);

class GameTable 
{
private:
	int x;
	int y;
	Block* blockObject;
	vector<vector<int>> table;

public:
	GameTable(int x, int y);
	void DrawGameTable();
	void createBlock();
	void MoveBlock(int key);
	void RotateBlock();
	void BuildBlock();
	void HardDropBlock();
	void DeleteLinear();
	bool isReachEnding();
};

class GamePlay
{
private :
	GameTable* gt;
public:
	GamePlay();
	~GamePlay()
	{
		system("cls");
		gotoxy(10, 10);
		cout << " Game Over ";
		delete gt;
	}
};

