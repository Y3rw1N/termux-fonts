#include "include.h"
#include "fonts.h"

const char* get_font_url(const char *font_name) {
  if (strcmp(font_name, "firacode") == 0) {
    return FIRA_CODE;
  } else if (strcmp(font_name, "cascadia-code") == 0) {
    return CASCADIA_CODE;
  } else if (strcmp(font_name, "jetbrainsmono") == 0) {
    return JETBRAINS_MONO;
  } else if (strcmp(font_name, "mononoki") == 0) {
    return MONONOKI;
  } else if (strcmp(font_name, "iosevka") == 0) {
    return IOSEVKA;
  } else if (strcmp(font_name, "hack") == 0) {
		return HACK;
  } else {
    return NULL;
  }
}
