#ifndef SHORTCURL_H
#define SHORTCURL_H

#include "include.h"

size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream);

bool curl_shortcut(const char *url, const char *filename);

#endif