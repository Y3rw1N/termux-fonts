#ifndef UTILS_H 
#define UTILS_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdbool.h>

#define TERMUX_DIRECTORY "/data/data/com.termux/files/home/.termux"
#define FONTS_DIRECTORY TERMUX_DIRECTORY "/fonts"
#define FONT_SET_DEFAULT TERMUX_DIRECTORY "/font.ttf"
 
bool set_font(const char *font_default);
bool font_remove(const char *font_default);
bool is_font_exists(const char *font_default);


#endif // UTILS_H //
