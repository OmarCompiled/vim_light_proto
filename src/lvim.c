#include <ctype.h>
#include <ncurses.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "config.h"
#include "screen_handler.c"
#include "command_handler.c"
#include "key_handler.c"

int
main()
{
	ESCDELAY = 50;
	char input;
	setup_screen();

	while(input = getch()){
		keyhandler(input);
	}
}
