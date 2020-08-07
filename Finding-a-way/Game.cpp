#include "Game.h"
#include "Util.h"

//Temp Store of Map array
char tempMap[16][58];

//Map Draw 1=wall S=Start D=Destination
// wall => #
// Start => @
// Destination => O
// Key => k
// Lock => L
char map1[16][58] = {
    {"111111111111111111111111111111111111111111111111111111111"},
    {"100000000000L000000000000000000000000000000000000000000D1"},
    {"100000000001000000000000000000000000000000000000000000001"},
    {"100000000010000000000000000000000000000000000000000000001"},
    {"100000000100000000000000000000000000000000000000000000001"},
    {"100000001000000000000000111000000000000000000000000000001"},
    {"100000001000000000000000000000000000000000000000000000001"},
    {"100000000100000000000000000000000000000000000000000000001"},
    {"100000000010000000000000000100000000000000000000000000001"},
    {"100000000001000000000000000000000000000000000000000000001"},
    {"100000K00000100000000000000000000000000000000000000000001"},
    {"100000000000010000000000000000000000000000000000000000001"},
    {"100000000000001000000000000000000000000000000000000000001"},
    {"100000000000000100000000000000000000000000000000000000001"},
    {"1S0000000000000010000000000000000000000000000000000000001"},
    {"111111111111111111111111111111111111111111111111111111111"}
};
//Map Draw 2 Hard Mode
char map2[16][58] = {
    {"111111111111111111111111111111111111111111111111111111111"},
    {"1000000000000100000000000000000100000000000000000000000D1"},
    {"100000000001001000000000000010001000000000000000000000001"},
    {"1000000000L0000100000000000100000100000000000000000000001"},
    {"100000000100000010000000001000000010000000000000000000001"},
    {"100000001000000001000000010000000001000000000000000000001"},
    {"1000K0001000000000100000110000000000100000000000000000001"},
    {"1000K0000100000000L00001000000000000010000000000000000001"},
    {"100000000010000000010001000011111111001000000000000000001"},
    {"100000000001000000001001000000000001000000000000000000001"},
    {"100000000000100000000100100000000001000000000000000000001"},
    {"100000000000010000000010010000000001000000000000000000001"},
    {"100000000000001000000001001000000001000000000000000000001"},
    {"100000000000000100000000100100000001001000000000000000001"},
    {"1S0000000000000010000000010010000000000100000000000000001"},
    {"111111111111111111111111111111111111111111111111111111111"}
};

void drawUI(int* x, int* y, int* key) {
    setColor(white, black);
    gotoxy(1, 17);
    printf(" Position : %02d, %02d", *x, *y);

    setColor(yellow, black);
    gotoxy(34, 17);
    std::cout << " Key : " << *key;

    setColor(white, black);
    gotoxy(1, 19);
    std::cout << "   If you want Show Main Screen !!!Press SpaceBar!!! ";
}


// Game Loop
void gLoop(int mapCode) {
    int x, y;
    int key = 0;
    int playing = 1;

    if (mapCode == 0) {
        memcpy(tempMap, map1, sizeof(tempMap));
    }
    else if (mapCode == 1) {
        memcpy(tempMap, map2, sizeof(tempMap));
    }
    drawMap(&x, &y);

    while (playing) {
        drawUI(&x, &y, &key);
        switch (keyControl()) {
        case UP:
            move(&x, &y, 0, -1, &key, &playing);
            break;

        case DOWN:
            move(&x, &y, 0, 1, &key, &playing);
            break;

        case RIGHT:
            move(&x, &y, 1, 0, &key, &playing);
            break;

        case LEFT:
            move(&x, &y, -1, 0, &key, &playing);
            break;

        case SUBMIT:
            playing = 0;
        }
    }
    system("cls");
    gotoxy(13, 8);
    std::cout << "Congratulations Game Clear!!!";
    std::cout << endl;
    gotoxy(13, 9);
    std::cout << "Thank you for playing my console game.";
    std::cout << endl;
    gotoxy(13, 10);
    std::cout << "Make By Seong Taek";
    Sleep(3000);
}

// Move Function and Exception of Wall 
void move(int* x, int* y, int _x, int _y, int* key, int* clear) {

    char mapObject = tempMap[*y + _y][*x + _x];
    setColor(white, black);

    if (mapObject == '0') {
        gotoxy(*x, *y);
        std::cout << " ";
        setColor(cyan, black);
        gotoxy(*x + _x, *y + _y);
        std::cout << "@";

        *x += _x;
        *y += _y;
    }
    else if (mapObject == 'K') {
        *key += 1;
        tempMap[*y + _y][*x + _x] = '0';
        gotoxy(*x + _x, *y + _y);
        std::cout << " ";
    }
    else if (mapObject == 'L') {
        if (*key > 0) {
            *key -= 1;
            tempMap[*y + _y][*x + _x] = '0';
            setColor(white, black);
            gotoxy(*x + _x, *y + _y);
            std::cout << " ";
        }
    }
    else if (mapObject == 'D') {
        *clear = 0;
    }

}

// Map Draw 0 Easy Mode 1 Hard Mode 
void drawMap(int* x, int* y) {
    system("cls");
    for (int h = 0; h < 16; h++) {
        for (int w = 0; w < 58; w++) {
            char temp = tempMap[h][w];
            if (temp == '0') {
                setColor(black, black);
                std::cout << " ";
            }
            else if (temp == '1') {
                setColor(white, white);
                std::cout << "#";
            }
            else if (temp == 'S') {
                *x = w;
                *y = h;
                setColor(cyan, black);
                std::cout << "@";
            }
            else if (temp == 'D') {
                setColor(lightgreen, black);
                std::cout << "O";
            }
            else if (temp == 'K') {
                setColor(yellow, black);
                std::cout << "*";
            }
            else if (temp == 'L') {
                setColor(brown, black);
                std::cout << "+";
            }
        }
        std::cout << endl;
    }
    setColor(white, black); // Reset Default Color 
    //Sleep(3000);
}

//Console Menu Draw
int menuDraw() {
    int x = 22;
    int y = 8;
    gotoxy(x - 2, y);
    std::cout << "> Start Game";
    gotoxy(x, y + 1);
    std::cout << "Game Information";
    gotoxy(x, y + 2);
    std::cout << "Game End";
    //Wait Keyboard Input and if entered w,a,s,d,space Handling Code
    while (1) {
        int n = keyControl();
        switch (n) {
        case UP: {
            if (y > 8) {
                gotoxy(x - 2, y);
                std::cout << " ";
                gotoxy(x - 2, --y);
                std::cout << ">";
            }
            break;
        }

        case DOWN: {
            if (y < 10) {
                gotoxy(x - 2, y);
                std::cout << " ";
                gotoxy(x - 2, ++y);
                std::cout << ">";
            }
            break;
        }

        case SUBMIT: {
            return y - 8;
        }
        }
        //return n;
    }
}
void infoDraw() {
    system("cls");
    std::cout << endl; std::cout << endl;
    std::cout << " [Control]               ";
    std::cout << endl; std::cout << endl;
    std::cout << " Move Key   : W,A,S,D" << endl;
    std::cout << " Select Key : Space Bar" << endl;
    std::cout << " Game Maker : Seong Taek Oh" << endl;
    std::cout << " Press the space bar to go to the main screen" << endl;
    std::cout << endl;
    std::cout << endl;
    std::cout << endl;
    std::cout << " [Game Rules]" << endl;
    std::cout << endl;
    std::cout << " @ <- This is your Character" << endl;
    std::cout << " O <- The point of arrival" << endl;
    std::cout << " + <- These letters are locked doors." << endl;
    std::cout << " * <- Key to open door" << endl;


    while (1) {
        if (keyControl() == SUBMIT) {
            break;
        }
    }
}
//Console Init 
void titleDraw() {
    std::cout << endl; std::cout << endl;
    std::cout << "==========================================================";
    std::cout << endl; std::cout << endl;
    std::cout << "                      Game Start                          ";
    std::cout << "                                           by.seongtaekoh ";
    std::cout << endl; std::cout << endl;
    std::cout << "==========================================================";
    std::cout << endl; std::cout << endl;
}
//Key Borad Event
int keyControl() {
    char temp = _getch();
    if (temp == 'w' || temp == 'W') {
        return UP;
    }
    else if (temp == 'a' || temp == 'A') {
        return LEFT;
    }
    else if (temp == 's' || temp == 'S') {
        return DOWN;
    }
    else if (temp == 'd' || temp == 'D') {
        return RIGHT;
    }
    else if (temp == ' ') {
        return SUBMIT;
    }
}


//Map List Draw Function
int maplistDraw() {
    int x = 24;
    int y = 6;
    system("cls");
    std::cout << endl;
    gotoxy(x - 2, y - 2);
    std::cout << "[Map Select]";
    gotoxy(x - 2, y);
    std::cout << "> Easy ";
    gotoxy(x, y + 1);
    std::cout << "Hard";
    gotoxy(x, y + 2);
    std::cout << "Go back";

    while (1) {
        int n = keyControl();
        switch (n) {
        case UP: {
            if (y > 6) {
                gotoxy(x - 2, y);
                std::cout << " ";
                gotoxy(x - 2, --y);
                std::cout << ">";
            }
            break;
        }
        case DOWN: {
            if (y < 9) {
                gotoxy(x - 2, y);
                std::cout << " ";
                gotoxy(x - 2, ++y);
                std::cout << ">";
            }
            break;
        }
        case SUBMIT: {
            return y - 6;
        }
        }
    }


}