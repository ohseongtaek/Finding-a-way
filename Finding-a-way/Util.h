#include "Main.h"

void init();
void gotoxy(int a, int b);
void setColor(int a, int b);

#ifndef __COLOR_LIST_
#define __COLOR_LIST_
enum {
	black,
	blue,
	green,
	cyan,
	red,
	magenta,
	brown,
	purple,
	lightgray,
	darkgray,
	lightblue,
	lightgreen,
	lightpurple,
	yellow,
	what,
	white
};
#endif