#include "../include/utils.h"

void help_message() {
	printf("\n  \'-S <fontname>\' to set the font.\n nm");
}

void set_font(char *fontName) {
	if (access(FONTS_DIRECTORY, F_OK) != -1) {
        char command[200];
        snprintf(command, sizeof(command), "cp %s/%s.ttf %s", FONTS_DIRECTORY, fontName, FONT_SET_DEFAULT);
        system(command);
        system("termux-reload-settings");
	}
}