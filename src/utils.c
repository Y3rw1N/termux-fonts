#include "../include/utils.h"

void help_message() {
    printf("nose");
}

void set_font(const char *font_name) {
    char command[200];
    snprintf(command, sizeof(command), "cp " FONTS_DIRECTORY "/%s.ttf" FONT_SET_DEFAULT, font_name);
    system(command);
    system("termux-reload-settings");
}
