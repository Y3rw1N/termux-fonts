#include "utils.h"

struct stat buffer;

bool is_font_exists(const char *font_default) {
  FILE *font_file = fopen(font_default, "r");
  if (font_file != NULL) {
    return true;
  } else {
    return false;
  }
}

void set_font(const char *font_default) {
    char command[200];

    snprintf(command, sizeof(command), "cp " FONTS_DIRECTORY "/%s.ttf " FONT_SET_DEFAULT, font_default);

    if (!is_font_exists(font_default)) {
      printf("el archivo no existe, instala la fuente de nuevo");
      return;
    }

    system(command);
    system("termux-reload-settings");
}
 

void font_remove() {
  char command[200];
  snprintf(command, sizeof(command), "rm " FONT_SET_DEFAULT);

  if (!is_font_exists(FONT_SET_DEFAULT)) {
    printf("el archivo no existe");
    return;
  }
  system(command);
  system("termux-reload-settings");
  
}
