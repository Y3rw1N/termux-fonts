#ifndef UTILS_H 
#define UTILS_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define TERMUX_DIRECTORY "/data/data/com.termux/files/home/.termux"
#define FONTS_DIRECTORY TERMUX_DIRECTORY "/fonts"
#define FONT_SET_DEFAULT TERMUX_DIRECTORY "/font.ttf"
 
void set_font(const char *font_name);
void font_remove(const char *font_removing);

#endif // UTILS_H //
