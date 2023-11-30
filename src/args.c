#include "../include/utils.h"

void help_message() {
	printf("\n  \'-S <fontname>\' to set the font.\n");
}

void set_font(char *fontName) {
	if (access(fontName, F_OK) != -1) {
        char fontSet[200];
        char comando[200];
        snprintf(fontSet, sizeof(fontSet), "%s/font.ttf", TERMUX_DIRECTORY);
        snprintf(comando, sizeof(comando), "cp %s/%s.ttf %s",TERMUX_DIRECTORY, fontName, fontSet);
        system(comando);
        system("termux-reload-settings");
	}
}
