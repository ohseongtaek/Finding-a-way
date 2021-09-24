#include "02_Tetris_DefineBlock.h"

//https://seokjin2.tistory.com/35

// Main menu Class 
class MainMenu
{
public:
	MainMenu()
	{
        cout << "\n\n\n\n";
        cout << "\t\t"; cout << "@@@@@@@@@@@@  @@@@@@@@@   @@@@@@@@@@@  @@@@@@@@   @   @@@@@@@@@@@\n";
        cout << "\t\t"; cout << "      @       @                @       @      @   @   @          \n";
        cout << "\t\t"; cout << "      @       @                @       @      @   @   @          \n";
        cout << "\t\t"; cout << "      @       @@@@@@@@@        @       @     @    @   @@@@@@@@@@@\n";
        cout << "\t\t"; cout << "      @       @                @       @ @ @      @             @\n";
        cout << "\t\t"; cout << "      @       @                @       @     @    @             @\n";
        cout << "\t\t"; cout << "      @       @@@@@@@@@        @       @      @   @   @@@@@@@@@@@\n\n\n\n\n";
        cout << "\t\t"; cout << "                   TetrisGame Made By seongtaek.oh\n";
        cout << "\t\t"; cout << "                   If you want Game Start Please any key\n";
        getchar(); 
        system("cls"); 
	}
};

// Table Backup Class
class backup
{
public:
    static void updateBlock(Block* source, Block& backupBlock)
    {
        backupBlock.setX(source->getX());
        backupBlock.setY(source->getY());
        backupBlock.setRotationCount(source->getRotationCount());
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                for (int k = 0; k < 4; k++)
                {
                    backupBlock.setShape(i, j, k, source->getShape(i, j, k));
                }
            }
        }
    }
    static void updateTable(vector<vector<int>>& source, vector<vector<int>>& backupTable)
    {
        backupTable.resize(source.size(), vector<int>(source.size()));
        copy(source.begin(), source.end(), backupTable.begin());
    }
};
