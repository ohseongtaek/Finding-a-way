#include "02_Tetris_Game.h"
#include "02_Tetris.h"
GameTable::GameTable(int x, int y)
{
	blockObject = nullptr;
	this->x = x;
	this->y = y;
	for (int i = 0; i < y; i++)
	{
		vector<int> temp;
		for (int j = 0; j < x; j++)
		{
			temp.push_back(0);
		}
		table.push_back(temp);
	}

	for (int i = 0; i < x; i++)
	{
		table[0][i] = 1;
		table[y - 1][i] = 1;
	}
	for (int i = 1; i < y - 1; i++)
	{
		table[i][0] = 1;
		table[i][x - 1] = 1;
	}
	for (int i = 1; i < x - 1; i++)
	{
		table[y - 1][i] = 4;
	}
	for (int i = 1; i < x - 1; i++)
	{
		table[END_Y][i] = 5;
	}
}

void GameTable::DrawGameTable()
{
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if (table[i][j] == 1 || table[i][j] == 4)
			{
				cout << "в╠";
			}
			else if (table[i][j] == 2 || table[i][j] == 3)
			{
				cout << "бс";
			}
			else if (table[i][j] == 5)
			{
				cout << "==";
			}
			else
			{
				cout << "  ";
			}
		}
		cout << endl;
	}
}

void GameTable::createBlock()
{
	srand((unsigned int)time(NULL));
	int select = rand() % 5 + 1;
	if (select == 1)
	{
		blockObject = new Block1();
	}
	else if (select == 2)
	{
		blockObject = new Block2();
	}
	else if (select == 3)
	{
		blockObject = new Block3();
	}
	else if (select == 4)
	{
		blockObject = new Block4();
	}
	else if (select == 5)
	{
		blockObject = new Block5();
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int X = i + blockObject->getX();
			int Y = j + blockObject->getY();

			if (Y < 0 || X < 0 || Y >= TABLE_Y || X >= TABLE_X)
			{
				continue;
			}
			table[Y][X] = blockObject->getShape(blockObject->getRotationCount(), i, j);
		}
	}
}

void GameTable::MoveBlock(int key)
{
	Block backupBlock;
	vector<vector<int>> backupTable;
	backup::updateBlock(blockObject, backupBlock);
	backup::updateTable(table, backupTable);

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int Y = j + blockObject->getY();
			int X = i + blockObject->getX();

			if (Y < 0 || X < 0 || Y >= TABLE_Y || X >= TABLE_X)
			{
				continue;
			}
			if (table[Y][X] == 2)
			{
				table[Y][X] = 0;
			}
		}
	}

	if (key == DOWN)
	{
		blockObject->down();
	}
	else if (key == LEFT)
	{
		blockObject->left();
	}
	else if (key == RIGHT)
	{
		blockObject->right();
	}
	
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int y = j + blockObject->getY();
			int x = i + blockObject->getX();
			
			if (y < 0 || x < 0 || y >= TABLE_Y || x >= TABLE_X)
			{
				continue;
			}
			int blockvalue = blockObject->getShape(blockObject->getRotationCount(), i, j);
			if (blockvalue != 2)
			{
				continue;
			}

			if (table[y][x] == 0)
			{
				table[y][x] = blockvalue;
			}
			else if (table[y][x] == 1)
			{
				copy(backupTable.begin(), backupTable.end(), table.begin());
				blockObject->setX(backupBlock.getX());
				blockObject->setY(backupBlock.getY());
				return;
			}
			else if (table[y][x] == 3)
			{
				copy(backupTable.begin(), backupTable.end(), table.begin());
				blockObject->setX(backupBlock.getX());
				blockObject->setY(backupBlock.getY());
				if (key == DOWN)
				{
					BuildBlock();
					createBlock();
				}
				return;
			}
			else if (table[y][x] == 4)
			{
				copy(backupTable.begin(), backupTable.end(), table.begin());
				blockObject->setX(backupBlock.getX());
				blockObject->setY(backupBlock.getY());
				if (key == DOWN)
				{
					BuildBlock();
					createBlock();
				}
				return;
			}
		}
	}
}

void GameTable::RotateBlock()
{
	Block backupBlock;
	vector<vector<int>> backupTable;
	backup::updateBlock(blockObject, backupBlock);
	backup::updateTable(table,backupTable);

	for (int i = 0; i < 4; i++) 
	{
		for (int j = 0; j < 4; j++)
		{
			int y = j + blockObject->getY();
			int x = i + blockObject->getX();

			if (y < 0 || x < 0 || y >= TABLE_Y || x >= TABLE_X)
			{
				continue;
			}

			if (table[y][x] == 2)
			{
				table[y][x] = 0;
			}
		}
	}

	blockObject->rotate();

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int y = j + blockObject->getY();
			int x = i + blockObject->getX();

			if (y < 0 || x < 0 || y >= TABLE_Y || x >= TABLE_X)
			{
				continue;
			}

			int blockValue = blockObject->getShape(blockObject->getRotationCount(), i, j);
			if (blockValue != 2)
			{
				continue;
			}

			if (table[y][x] == 0)
			{
				table[y][x] = blockObject->getShape(blockObject->getRotationCount(), i, j);
			}
			else if (table[y][x] == 1 || table[y][x] == 3 || table[y][x] == 4)
			{
				copy(backupTable.begin(), backupTable.end(), table.begin());
				blockObject->setRotationCount(backupBlock.getRotationCount());
				return;
			}
		}
	}
}

void GameTable::BuildBlock()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int y = j + blockObject->getY();
			int x = i + blockObject->getX();

			if (y < 0 || x < 0 || y >= TABLE_Y || x >= TABLE_X)
			{
				continue;
			}

			int blockValue = blockObject->getShape(blockObject->getRotationCount(), i, j);
			if (blockValue != 2)
			{
				continue;
			}
			table[y][x] = 3;
		}
	}
}

void GameTable::HardDropBlock()
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int Y = j + blockObject->getY();
			int X = i + blockObject->getX();

			if (Y < 0 || X < 0 || Y >= TABLE_Y || X >= TABLE_X)
			{
				continue;
			}
			
			if (table[Y][X] == 2) 
			{
				table[Y][X] = 0; 
			}
		}
	}
	while (true) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				int Y = j + blockObject->getY();
				int X = i + blockObject->getX();

				if (Y < 0 || X < 0 || Y >= TABLE_Y || X >= TABLE_X)
				{
					continue;
				}

				int blockValue = blockObject->getShape(blockObject->getRotationCount(), i, j);

				if (blockValue != 2)
				{
					continue;
				}

				if (table[Y][X] == 3 || table[Y][X] == 4) 
				{
					blockObject->up();
					BuildBlock(); 
					createBlock();
					return; 
				}
			}
		}
		blockObject->down(); 
	}
}

void GameTable::DeleteLinear()
{
	for (int Y = END_Y + 1; Y < TABLE_Y - 1; Y++) 
	{
		bool isLinear = true;
		for (int X = 1; X < TABLE_X - 1; X++) 
		{
			if (table[Y][X] != 3)
			{
				isLinear = false;
			}
		}
		if (isLinear) 
		{
			for (int i = Y; i > END_Y - 1; i--)
			{
				for (int j = 1; j < TABLE_X - 1; j++) 
				{
					table[i][j] = table[i - 1][j];
				}
			}
		}
	}
}

bool GameTable::isReachEnding()
{
	for (int X = 1; X < TABLE_X - 1; X++) 
	{
		if (table[END_Y][X] == 3)
		{
			return true;
		}
	}
	return false;
}


GamePlay::GamePlay()
{
	gt = new GameTable(TABLE_X, TABLE_Y);
	gt->createBlock();
	gt->DrawGameTable();

	int timer = 0;
	clock_t start, end;
	start = clock();
	float time;

	while (true)
	{
		int nSelect;
		end = clock();
		time = ((float)(end - start) / CLOCKS_PER_SEC);
		if (time >= 1.5)
		{
			gt->MoveBlock(DOWN);
			start = clock();
		}
		if (_kbhit())
		{
			nSelect = _getch();
			if (nSelect == 224)
			{
				nSelect = _getch();
				switch (nSelect)
				{
				case UP:
					gt->RotateBlock();
					break;
				case DOWN:
					gt->MoveBlock(DOWN);
					break;
				case LEFT:
					gt->MoveBlock(LEFT);
					break;
				case RIGHT:
					gt->MoveBlock(RIGHT);
					break;
				default:
					break;
				}
			}
			else if (nSelect == SPACE)
			{
				gt->HardDropBlock();
			}
		}
		if (gt->isReachEnding())
		{
			return;
		}
		gt->DeleteLinear();
		gotoxy(0, 0);
		gt->DrawGameTable();
	}
}

void CursorView(char show)
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}
void gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
