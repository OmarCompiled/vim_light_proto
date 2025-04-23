#include <ncurses.h>

#ifndef CONFIG_H
#define CONFIG_H

/* coordinate variables */
static int max_y;
static int max_x;
int 	 current_y = 0;
int 	 current_x = 0;

/* command prompt string  */
static char* command;

char* MODE;

WINDOW* status_bar;

#endif
