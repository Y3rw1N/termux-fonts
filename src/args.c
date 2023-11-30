#include "../include/utils.h"

void help_message() {
	printf("\n  \'-S <fontname>\' to set the font.\n nm");
}

void set_font(char *fontName) {
	if (access(fontName, F_OK) != -1) {
        char command[200];
        snprintf(command, sizeof(command), "cp "FONTS_DIRECTORY"%s.ttf " FONT_SET_DEFAULT"", fontName);
        system(command);
        system("termux-reload-settings");
	}
}