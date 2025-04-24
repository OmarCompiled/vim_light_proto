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

/* helper functions / type checking */
bool
isEscapeKey(int input)
{
	return (input == 27 ? true : false); 
}

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

bool
isEnterKey(int input)
{
	if(input == '\n'
	|| input == KEY_ENTER) {
		return true;
	}
	return false;
}

WINDOW* status_bar;

#endif
