#include <ctype.h>
#include <ncurses.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "config.h"

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
validate_command()
{
	if(!strcmp(command, "q")) {
		exit(0);
	} else {
	  move(MAX_Y, 0);
		clrtoeol();
	}
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
	validate_command();
	back_to_position();
}

bool
check_for_command(const char input)
{
	if(input == ':'){
		get_command(input);
		return true;
	} else {
		return false;
	}
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
	wprintw(status_bar, "%s \t\t\t\t Ln %d, Col %d", "HI", current_y + 1, current_x + 1);
	wrefresh(status_bar);
}

int
main()
{
	setup_screen();

	char input;
	while(input = getch()) {
		getyx(stdscr, current_y, current_x);
		if(check_for_command(input)) {
			continue;
		}
		update_status_bar();
		printw("%c", input);
		refresh();
	}
}
