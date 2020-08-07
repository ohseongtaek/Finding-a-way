#include "Main.h"

//Key Borad Event handling 
typedef enum KeyBoard {
    UP = 0,
    DOWN = 1,
    LEFT = 2,
    RIGHT = 3,
    SUBMIT = 4
}keyboard;

void titleDraw();
void infoDraw();
int menuDraw();
int keyControl();
int maplistDraw();
void gLoop(int a);
void drawMap(int* a, int* b);
void move(int* a, int* b, int c, int d, int* k, int* clear);
void drawUI(int* a, int* b, int* k);