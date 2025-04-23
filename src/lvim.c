#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <ncurses.h>

#include "coords.h"

#define MAX_Y max_y-2
#define MAX_X max_x-2

void
back_to_position()
{
	command = NULL;
	raw();
	noecho();
	move(current_y, current_x);
}

void
get_command(const char input)
{
	move(MAX_Y, 0);
	noraw();
	addch(':');
	echo();
	command = (char *)malloc(sizeof(char) * 100);
	getstr(command);
	if(!strcmp(command, "q")) {
		exit(0);
	} else {
	  move(MAX_Y, 0);
		clrtoeol();
	}
	back_to_position();
}

void
clean_screen()
{
	free(command);
	endwin();
}

void
setup_screen()
{
	initscr();
	erase();
	raw();
	noecho();
	keypad(stdscr, TRUE);
	scrollok(stdscr, TRUE);
	getmaxyx(stdscr, max_y, max_x);

	atexit(clean_screen);
}

int
main()
{
	setup_screen();
	char input;
	while((input = getch())) {
		if(input == ':'){
			getyx(stdscr, current_y, current_x);
			get_command(input);
			continue;
		}
		printw("%c", input);
		refresh();
	}
}
