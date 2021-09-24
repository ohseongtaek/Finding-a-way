#pragma once
#include <iostream>
#include <vector>
#include <conio.h>
#include <Windows.h>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

#define END_Y 6
#define TABLE_X 20
#define TABLE_Y 38
#define LEFT 75		// 방향키 왼쪽
#define RIGHT 77	// 방향키 오른쪽
#define UP 72		// 방향키 위쪽
#define DOWN 80		// 방향키 아래쪽 
#define SPACE 32	// 스페이스바 

// Block 종류 
const int block1[4][4][4] = {
        {
                        {0, 0, 0, 0},
                        {0, 0, 0, 0},
                        {2, 2, 2, 2},
                        {0, 0, 0, 0}
        },
        {
                        {0, 0, 2, 0},
                        {0, 0, 2, 0},
                        {0, 0, 2, 0},
                        {0, 0, 2, 0}
        },
        {
                        {0, 0, 0, 0},
                        {0, 0, 0, 0},
                        {2, 2, 2, 2},
                        {0, 0, 0, 0}
        },
        {
                        {0, 0, 2, 0},
                        {0, 0, 2, 0},
                        {0, 0, 2, 0},
                        {0, 0, 2, 0}
        },
};
const int block2[4][4][4] = {
        {
                        {0, 0, 0, 0},
                        {0, 2, 2, 0},
                        {0, 2, 2, 0},
                        {0, 0, 0, 0}
        },
        {
                        {0, 0, 0, 0},
                        {0, 2, 2, 0},
                        {0, 2, 2, 0},
                        {0, 0, 0, 0}
        },
        {
                        {0, 0, 0, 0},
                        {0, 2, 2, 0},
                        {0, 2, 2, 0},
                        {0, 0, 0, 0}
        },
        {
                        {0, 0, 0, 0},
                        {0, 2, 2, 0},
                        {0, 2, 2, 0},
                        {0, 0, 0, 0}
        },
};
const int block3[4][4][4] = {
        {
                        {0, 2, 0, 0},
                        {0, 2, 0, 0},
                        {0, 2, 2, 0},
                        {0, 0, 0, 0}
        },
        {
                        {0, 0, 0, 0},
                        {0, 2, 2, 2},
                        {0, 2, 0, 0},
                        {0, 0, 0, 0}
        },
        {
                        {0, 2, 2, 0},
                        {0, 0, 2, 0},
                        {0, 0, 2, 0},
                        {0, 0, 0, 0}
        },
        {
                        {0, 0, 0, 0},
                        {0, 0, 2, 0},
                        {2, 2, 2, 0},
                        {0, 0, 0, 0}
        },
};
const int block4[4][4][4] = {
        {
                        {0, 0, 0, 0},
                        {0, 2, 0, 0},
                        {0, 2, 2, 0},
                        {0, 0, 2, 0}
        },
        {
                        {0, 0, 0, 0},
                        {0, 2, 2, 0},
                        {2, 2, 0, 0},
                        {0, 0, 0, 0}
        },
        {
                        {0, 0, 0, 0},
                        {0, 2, 0, 0},
                        {0, 2, 2, 0},
                        {0, 0, 2, 0}
        },
        {
                        {0, 0, 0, 0},
                        {0, 2, 2, 0},
                        {2, 2, 0, 0},
                        {0, 0, 0, 0}
        },
};
const int block5[4][4][4] = {
        {
                        {0, 0, 0, 0},
                        {0, 2, 2, 2},
                        {0, 0, 2, 0},
                        {0, 0, 0, 0}
        },
        {
                        {0, 0, 2, 0},
                        {0, 2, 2, 0},
                        {0, 0, 2, 0},
                        {0, 0, 0, 0}
        },
        {
                        {0, 0, 2, 0},
                        {0, 2, 2, 2},
                        {0, 0, 0, 0},
                        {0, 0, 0, 0}
        },
        {
                        {0, 0, 2, 0},
                        {0, 0, 2, 2},
                        {0, 0, 2, 0},
                        {0, 0, 0, 0}
        },
};

// Block Control Parent Class 
class Block
{
protected:
	int shape[4][4][4];
	int x;
	int y;
	int rotationCount;

public:
	int getShape(int rotationCount, int y, int x)
	{
		return shape[rotationCount][y][x];
	}

	// Get Position Function 
	int getX()
	{
		return x;
	}
	int getY()
	{
		return y;
	}
	int getRotationCount()
	{
		return rotationCount;
	}

	// Set Position Function 
	void setX(int x)
	{
		this->x = x;
	}
	void setY(int y)
	{
		this->y = y;
	}
	void setRotationCount(int r)
	{
		this->rotationCount = r;
	}
	void setShape(int r, int y, int x, int value)
	{
		this->shape[r][y][x] = value;
	}

	// Block move Function 
	void down()
	{
		y++;
	}
	void left()
	{
		x--;
	}
	void right()
	{
		x++;
	}
	void up()
	{
		y--;		// not using function
	}

	// Block Rotation Function 
	void rotate()
	{
		rotationCount = (rotationCount + 1) % 4;
	}
};

//Block Control child Class of 1
class Block1 : public Block
{
public:
	Block1()
	{
		x = TABLE_X / 2 - 3;
		y = 1;
		rotationCount = 0;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				for (int k = 0; k < 4; k++)
				{
					shape[i][j][k] = block1[i][j][k];
				}
			}
		}
	}
};

//Block Control child Class of 2
class Block2 : public Block
{
public:
	Block2()
	{
		x = TABLE_X / 2 - 3;
		y = 1;
		rotationCount = 0;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				for (int k = 0; k < 4; k++)
				{
					shape[i][j][k] = block2[i][j][k];
				}
			}
		}
	}
};

//Block Control child Class of 3
class Block3 : public Block
{
public:
	Block3()
	{
		x = TABLE_X / 2 - 3;
		y = 1;
		rotationCount = 0;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				for (int k = 0; k < 4; k++)
				{
					shape[i][j][k] = block3[i][j][k];
				}
			}
		}
	}
};

//Block Control child Class of 4
class Block4 : public Block
{
public:
	Block4()
	{
		x = TABLE_X / 2 - 3;
		y = 1;
		rotationCount = 0;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				for (int k = 0; k < 4; k++)
				{
					shape[i][j][k] = block4[i][j][k];
				}
			}
		}
	}
};

//Block Control child Class of 5
class Block5 : public Block
{
public:
	Block5()
	{
		x = TABLE_X / 2 - 3;
		y = 1;
		rotationCount = 0;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				for (int k = 0; k < 4; k++)
				{
					shape[i][j][k] = block5[i][j][k];
				}
			}
		}
	}
};