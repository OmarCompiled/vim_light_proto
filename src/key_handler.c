#include <ncurses.h>

#ifndef KEYHANDLER_C
#define KEYHANDLER_C

void
input_loop(char input)
{
	while(input = getch()) {
		getyx(stdscr, current_y, current_x);
		if(input == 27) {
			MODE = "";
			update_display(input);
			return;
		}
		
		if(input == KEY_UP) {
			current_y++;
		}

		update_display(input);
	}
}


void
keyhandler(const char input)
{
	switch(input) {
	case 'i':
		MODE = "INSERT";
		input_loop(input);
		break;
	case ':':
		check_for_command(input);
		break;
	}
}

#endif
