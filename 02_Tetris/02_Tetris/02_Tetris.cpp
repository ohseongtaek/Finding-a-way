#include "02_Tetris.h"
#include "02_Tetris_Game.h"
#include <iostream>

int main(void)
{
    CursorView(false);
    system("mode con cols=100 lines=40 | title Tetris Game");
    GameTable gt(TABLE_X, TABLE_Y);
    MainMenu();
    GamePlay();
    getchar();
    return 0;
}


