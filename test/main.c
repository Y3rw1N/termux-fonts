// args file script

#include "include.h"
#include "fonts.h"
#include "shortcurl.h"

void help_msg() {
  prinf("usage:");
}

bool create_fonts_directory() {
    const char *home_dir = getenv("HOME");
    if (!home_dir) {
        fprintf(stderr, "No se pudo obtener el directorio de Termux\n");
        return false;
    }

    char path[PATH_MAX];
    snprintf(path, sizeof(path), "%s/.termux", home_dir);

    if (mkdir(path, 0755) && errno != EEXIST) {
        fprintf(stderr, "No se pudo crear el directorio: %s\n", path);
        return false; 
    }

    snprintf(path, sizeof(path), "%s/.termux/.fonts", home_dir);

    if (mkdir(path, 0755) && errno != EEXIST) {
        fprintf(stderr, "No se pudo crear el directorio: %s\n", path);
        return false; 
    }

    return true;
}

int main(int argc, char *argv[]) {
  const char *font_name = argv[2];

  if (argc != 3) {
    help_msg();
  } 

  if (strcmp(argv[1], "install") == 0) {
    const char *url = get_font_url(font_name);

    if (url == NULL) {
      fprintf(stderr, "font not found: %s\n", font_name);
      return 1;
    }

    char fonts_dir[512];
    if (!create_fonts_directory(fonts_dir, sizeof(fonts_dir))) {
        fprintf(stderr, "There was an error creating the directory");
        return 1;
    }

    char filename[512];
    snprintf(filename, sizeof(filename), "%s/%s", fonts_dir, font_name);

    if (curl_shortcut(url, filename)) {
      printf("The download was successful. The content was stored in %s\n", filename);
    } else {
      printf("Error downloading the resource\n");
    }
  }
  return 0;
} 