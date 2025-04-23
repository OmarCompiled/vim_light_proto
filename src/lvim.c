#include <ctype.h>
#include <ncurses.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "config.h"
#include "screen_handler.c"
#include "command_handler.c"
#include "keyhandler.c"

int
main()
{
	char input;
	setup_screen();

	while(true){
		input = getch();
		keyhandler(input);
	}
}
