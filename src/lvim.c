#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <ncurses.h>

void
get_command(const char input)
{
	noraw();
	addch(':');
	echo();
	char *command = (char *)malloc(sizeof(char) * 100);
	getstr(command);
	if(!strcmp(command, "q")) {
		exit(0);
	} else {
		addstr("Unkown command");
	}
	free(command);
	raw();
	noecho();
}

void
clean_screen()
{
	endwin();
}

void
setup_screen()
{
	initscr();
	raw();
	noecho();
	keypad(stdscr, 1);
	
	atexit(clean_screen);
}

int
main()
{
	int cur_y, cur_x;
	int max_y, max_x;
	cur_y = max_y = cur_x = max_x = 0;

	setup_screen();
	
	char input;
	while((input = getch())) {
		input == ':' ? get_command(input) : 0;
		printw("%c", input);
		refresh();
	}
}
