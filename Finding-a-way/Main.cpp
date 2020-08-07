#include "Main.h"
#include "Game.h"
#include "Util.h"
#define endl '\n'

// Main (Start Point)
int main()
{
    init();
    while (1) {
        titleDraw();    // Loop of Init 
        int menuCode = menuDraw(); // Store of Event Value that Key board
        if (menuCode == 0) {
            // Game Start 
            int n = maplistDraw();
            if (n == 0) {
                gLoop(0);
            }
            else if (n == 1) {
                gLoop(1);
            }
        }
        else if (menuCode == 1) {
            // Game Information
            infoDraw();
        }
        else if (menuCode == 2) {
            // Game End
            return 0;
        }
        system("cls");
        setColor(white, black);
    }
    return 0;
    /* debug code for gotoxy function
    gotoxy(2, 2);
    std::cout << "2,2" << endl;
    gotoxy(6, 6);
    std::cout << "6,6" << endl;
    */

    /* debug code for KeyControl function
    int keyCode = keyControl();
    std::cout << " what ? " << keyCode << endl;
    return 0;
    */

}