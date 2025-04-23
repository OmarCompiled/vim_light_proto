#include <ncurses.h>

#ifndef KEYHANDLER_C
#define KEYHANDLER_C

void
input_loop(char input)
{
	while(input = getch()) {
		getyx(stdscr, current_y, current_x);
		if(KEY_ENTER) {
			LINES++;
		} else if(KEY_SDC) {
			break;
		}
		if(check_for_command(input)) {
			continue;
		}

		update_status_bar();
		printw("%c", input);
		refresh();
	}
}

void
keyhandler(const char input)
{
	if(input == 'i') {
		MODE = "INSERT";
		input_loop(input);
	}
}

#endif
