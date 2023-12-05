#include "../include/utils.h"

struct stat buffer;

void set_font(const char *font_name) {
    char command[200];
    snprintf(command, sizeof(command), "cp " FONTS_DIRECTORY "/%s.ttf " FONT_SET_DEFAULT, font_name);
    system(command);
    system("termux-reload-settings");
}

void font_remove(const char *font_removing) {
  char command[200];
  snprintf(command, sizeof(command), "rm " FONTS_DIRECTORY "/%s.ttf", font_removing);
  if (stat(FONTS_DIRECTORY, "/",font_removing,".ttf", &buffer) == 0) {
    system(command);
  } else {
    printf("font not found");
  }
}
