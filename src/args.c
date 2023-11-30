#include "../include/utils.h"

void help_message() {
	printf("\n  \'-S <fontname>\' to set the font.");
}

void set_font(char *fontName) {
	if (access(fontName, F_OK) != -1) {
    char fontSet[100];
    snprintf(fontSet, sizeof(fontSet), "~/.termux/font.ttf");

    char comando[200];
    snprintf(comando, sizeof(comando), "cp " FONTS_DIRECTORY "/%s.ttf %s", fontName, fontSet);
    system(comando);
	}
}
