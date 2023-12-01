#include "../include/utils.h"

void help_message() {
	printf("\n  \'-S <fontname>\' to set the font.\n");
}

void set_font(char *fontName) {
	if (access(fontName, F_OK) != -1) {
        char command[200];
        snprintf(command, sizeof(command), "cp /data/data/com.termux/files/home/.termux/%s.ttf %s",fontName,FONT_SET_DEFAULT);
        system(command);
        system("termux-reload-settings");
	}
}