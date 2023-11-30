#include "../include/fonts.h"

char command[100];

void set_terminal_font(const char *font_name) {
     if (strcmp(font_name, "fira_code") == 0) {
        snprintf(command, sizeof(command), FONTS_DIRECTORY"/fira-code.ttf " TERMUX_DIRECTORY"/font.ttf");
        system(command);

    } else if (strcmp(font_name, "cascadia_code") == 0) {
        snprintf(command, sizeof(command), "cp " FONTS_DIRECTORY"/cascadia-code.ttf " TERMUX_DIRECTORY"/font.ttf");
        system(command);

    } else if (strcmp(font_name, "mononoki") == 0) {
        snprintf(command, sizeof(command), "cp " FONTS_DIRECTORY"/mononoki.ttf " TERMUX_DIRECTORY"/font.ttf");
        system(command);

    } else if (strcmp(font_name, "hack") == 0) {
        snprintf(command, sizeof(command), "cp " FONTS_DIRECTORY"/hack.ttf " TERMUX_DIRECTORY"/font.ttf");
        system(command);

    } else if (strcmp(font_name, "jetbrainsmono") == 0) {
        snprintf(command, sizeof(command), "cp " FONTS_DIRECTORY"/jetbrains-mono.ttf " TERMUX_DIRECTORY"/font.ttf");
        system(command);
    }
}