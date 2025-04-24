#include "config.h"

#ifndef SCREEN_HANDLER_H
#define SCREEN_HANDLER_H

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
clean_screen()
{
	free(command);
	endwin();
}

void
setup_screen()
{
	initscr();
	status_bar = newwin(1, COLS, LINES-1, 0);

	raw();
	noecho();	
	keypad(stdscr, TRUE);
	scrollok(stdscr, TRUE);
	getmaxyx(stdscr, max_y, max_x);

	atexit(clean_screen);
}

void
update_status_bar()
{
	werase(status_bar);
	wprintw(status_bar, "--%s-- \t\t\t\t Ln %d, Col %d", MODE, current_y + 1, current_x + 1);
	wrefresh(status_bar);
}

void
update_display(const char input)
{
	update_status_bar();
	if(input != 27) {
		printw("%c", input);
		refresh();
	}
}

#endif
