#include "../include/utils.h"

void help_message() {
	printf("\n  \'-S <fontname>\' to set the font.\n");
}

void set_font(char* name) {
  if (access(name, F_OK) != -1) {
    char command[200];
    snprintf(command, sizeof(command), "cp /data/data/com.termux/files/home/.termux/%s.ttf %s", FONT_SET_DEFAULT, name);
    system(command);
    system("termux-reload-settings");
	}      
}
