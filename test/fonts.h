#include "include.h"

#define FIRA_CODE "https://github.com/ryanoasis/nerd-fonts/raw/master/patched-fonts/FiraCode/Regular/FiraCodeNerdFontMono-Regular.ttf"
#define CASCADIA_CODE "https://github.com/ryanoasis/nerd-fonts/raw/master/patched-fonts/CascadiaCode/Regular/CaskaydiaCoveNerdFontMono-Regular.ttf"
#define JETBRAINS_MONO "https://github.com/ryanoasis/nerd-fonts/raw/master/patched-fonts/JetBrainsMono/NoLigatures/Regular/JetBrainsMonoNLNerdFontMono-Regular.ttf"
#define IOSEVKA "https://github.com/ryanoasis/nerd-fonts/raw/master/patched-fonts/Iosevka/IosevkaNerdFontMono-Regular.ttf"
#define MONONOKI "https://github.com/ryanoasis/nerd-fonts/raw/master/patched-fonts/Mononoki/Regular/MononokiNerdFontMono-Regular.ttf"

const char* get_font_url(const char* font_name) {
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
  } else {
    return NULL;
  }
}