#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#ifndef UTILS_H 
#define UTILS_H

#define HOME_DIRECTORY "/data/data/com.termux/files/home"
#define TERMUX_DIRECTORY HOME_DIRECTORY "/.termux"
#define FONTS_DIRECTORY TERMUX_DIRECTORY "/fonts"

void set_font();
void help_message();

#endif // UTILS_H //