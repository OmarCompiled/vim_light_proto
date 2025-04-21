#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <ncurses.h>

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
	setup_screen();
	
	char input;
	while(input = getch()) {
		printw("%c", input);
		refresh();
	}
}
