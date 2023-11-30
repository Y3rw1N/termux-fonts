#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#include "utils.h"

#ifndef FONTS_H
#define FONTS_H

#define cascadia_code_nerd "wget -O "FONTS_DIRECTORY"/cascadia-code.ttf https://github.com/ryanoasis/nerd-fonts/raw/master/patched-fonts/CascadiaCode/Regular/CaskaydiaCoveNerdFontMono-Regular.ttf"

#define fira_code_nerd "wget -O "FONTS_DIRECTORY"/fira-code.ttf https://github.com/ryanoasis/nerd-fonts/raw/master/patched-fonts/FiraCode/Regular/FiraCodeNerdFontMono-Regular.ttf"

#define mononoki_nerd "wget -O "FONTS_DIRECTORY"/mononoki.ttf https://github.com/ryanoasis/nerd-fonts/raw/master/patched-fonts/Monoid/Regular/MonoidNerdFont-Regular.ttf"

#define hack_nerd "wget -O "FONTS_DIRECTORY"/hack.ttf https://github.com/ryanoasis/nerd-fonts/raw/master/patched-fonts/Hack/Regular/HackNerdFontMono-Regular.ttf"

#define jetbrainsmono_nerd "wget -O "FONTS_DIRECTORY"/jetbrains-mono.ttf https://github.com/ryanoasis/nerd-fonts/raw/master/patched-fonts/JetBrainsMono/Ligatures/Regular/JetBrainsMonoNerdFont-Regular.ttf"

void set_terminal_font(const char *fonts_name);

#endif