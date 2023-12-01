#include "../include/utils.h"

void help_message() {
	printf("\n  \'-S <fontname>\' to set the font.\n");
}

void set_font(char *name) {
    char command[60];
    snprintf(command, sizeof(command), "cp "TERMUX_DIRECTORY"/%s.ttf "FONT_SET_DEFAULT"", name);
    system(command);
    system("termux-reload-settings"); 
}
