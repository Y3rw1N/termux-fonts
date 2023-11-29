#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

#define HOME_DIRECTORY "/data/data/com.termux/files/home"
#define FONTS_DIRECTORY HOME_DIRECTORY "/.termux/fonts"
 #define cascadia_code "wget -O "FONTS_DIRECTORY"/cascadia-code.ttf https://github.com/ryanoasis/nerd-fonts/blob/master/patched-fonts/CascadiaCode/Regular/CaskaydiaCoveNerdFontMono-Regular.ttf"
#define fira_code "wget -O "FONTS_DIRECTORY"/fira-code.ttf https://github.com/ryanoasis/nerd-fonts/raw/master/patched-fonts/FiraCode/Regular/FiraCodeNerdFontMono-Regular.ttf"
