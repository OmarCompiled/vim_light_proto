#include <ncurses.h>

#ifndef KEYHANDLER_C
#define KEYHANDLER_C

void
input_loop(int input)
{
	while(true) {
		input = getch();
		getyx(stdscr, current_y, current_x);
		if(input == 27) {
			MODE = "";
			update_status_bar();
			return;
		}

		if(input == '\n') {
			current_y++;
			current_x = 0;
			update_status_bar();
			move(current_y, current_x);
			continue;
		}

		if(input == KEY_UP && current_y > 0) {
			current_y--;
			update_status_bar();
			move(current_y, current_x);
			continue;
		} else if(input == KEY_DOWN && current_y < LINES - 2) {
			current_y++;
			update_status_bar();
			move(current_y, current_x);
			continue;
		} else if(input == KEY_LEFT && current_x > 0) {
			current_x--;
			update_status_bar();
			move(current_y, current_x);
			continue;
		} else if(input == KEY_RIGHT && current_x < COLS - 1) {
			current_x++;
			update_status_bar();
			move(current_y, current_x);
			continue;
		}
		update_display(input);
	}
}

void
keyhandler(int input)
{
	switch(input) {
	case 'i':
		MODE = "INSERT";
		update_status_bar();
		input_loop(input);
		break;
	case ':':
		check_for_command(input);
		break;
	}
}

#endif
