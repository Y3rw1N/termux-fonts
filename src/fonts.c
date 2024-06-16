#include "include.h"
#include "fonts.h"

const char* get_font_url(const char *font_name) {
  if (strcmp(font_name, "firacode") == 0) { return FIRA_CODE; }
  if (strcmp(font_name, "cascadia-code") == 0) { return CASCADIA_CODE; }
  if (strcmp(font_name, "jetbrainsmono") == 0) { return JETBRAINS_MONO; }
  if (strcmp(font_name, "mononoki") == 0) { return MONONOKI; }
  if (strcmp(font_name, "iosevka") == 0) { return IOSEVKA; }
  if (strcmp(font_name, "hack") == 0) { return HACK; }
  return NULL;
}