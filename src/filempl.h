#ifndef FILEMPL_C
#define FILEMPL_C

#include "include.h"

void set_default_font(void);
void create_fonts_directory(void);
bool set_font(const char *font_name);
bool copy_file(const char *source_path, const char *target_path);

#endif