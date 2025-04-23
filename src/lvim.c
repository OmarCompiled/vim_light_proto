#include <ctype.h>
#include <ncurses.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "config.h"
#include "screen_handler.h"
#include "command_handler.h"
#include "keyhandler.h"

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
