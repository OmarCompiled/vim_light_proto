#include <ncurses.h>

#ifndef CONFIG_H
#define CONFIG_H

/* coordinate variables */
static int max_y;
static int max_x;
static int current_y = 0;
static int current_x = 0;

/* command prompt string  */
static char* command;

char* MODE;

bool
isArrowKey(int input)
{
	if(input == KEY_UP
	|| input == KEY_DOWN
	|| input == KEY_LEFT
	|| input == KEY_RIGHT) {
		return true;
	}
	return false;
}

WINDOW* status_bar;

#endif
