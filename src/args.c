#include "../include/utils.h"

void help_message() {
	printf("\n  \'-S <fontname>\' to set the font.\n");
}

void set_font(char *fontName) {
	if (access(fontName, F_OK) != -1) {
        char fontSet[200];
        char comando[200];
        snprintf(fontSet, sizeof(fontSet), TERMUX_DIRECTORY"/font.ttf");
        snprintf(comando, sizeof(comando), "cp " FONTS_DIRECTORY "/%s.ttf %s", fontName, fontSet);
        system(comando);
        system("termux-reload-settings");
	}
}
