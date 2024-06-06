#include "shortcurl.h"

bool curl_shortcut(const char *url, const char *filename) {
  CURL *curl;
  CURLcode res;
  bool success = false;
  FILE *file = fopen(filename, "wb");

  if (!file) {
    fprintf(stderr, "Could not open file: %s\n", filename);
    return false;
  }

  curl = curl_easy_init();

  if (curl) {
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

    res = curl_easy_perform(curl);

    if (res == CURLE_OK)
      success = true;
    else
      fprintf(stderr, "error when making the request: %s\n", curl_easy_strerror(res));

    curl_easy_cleanup(curl);

  } else {
    fprintf(stderr ,"no se pudo llamar a CURL");
  }

  fclose(file);
  return success;
}