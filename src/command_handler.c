#include <ncurses.h>

#ifndef COMMAND_HANDLER_H
#define COMMAND_HANDLER_H

void
validate_command()
{
	if(!strcmp(command, "q")) {
		exit(0);
	} else {
	  move(MAX_Y, 0);
		clrtoeol();
		raw();
	  move(MAX_Y, 0);
		attron(A_REVERSE);
		addstr("unkown command!");
		attroff(A_REVERSE);
		getch();
		move(MAX_Y, 0);
		clrtoeol();		
	}
}

void
get_command()
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
check_for_command(int input)
{
	if(input == ':'){
		get_command(input);
		return true;
	} else {
		return false;
	}
}

#endif
