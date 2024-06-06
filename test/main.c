#include "include.h"
#include "fonts.h"
#include "shortcurl.h"

void help_msg() {
    printf("usage: <program> <install|set> <font-name>\n");
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

    snprintf(path, sizeof(path), "%s/.termux/fonts", home_dir);

    if (mkdir(path, 0755) && errno != EEXIST) {
        fprintf(stderr, "No se pudo crear el directorio: %s\n", path);
        return false; 
    }

    return true;
}

bool set_font(const char *font_name) {
    const char *home_dir = getenv("HOME");
    if (!home_dir) {
        fprintf(stderr, "No se pudo obtener el directorio de Termux\n");
        return false;
    }

    char src_font_path[PATH_MAX];
    snprintf(src_font_path, sizeof(src_font_path), "%s/.termux/fonts/%s.ttf", home_dir, font_name);

    char dest_font_path[PATH_MAX];
    snprintf(dest_font_path, sizeof(dest_font_path), "%s/.termux/font.ttf", home_dir);

    printf("Moving font from %s to %s\n", src_font_path, dest_font_path);

    if (rename(src_font_path, dest_font_path) != 0) {
        fprintf(stderr, "Error setting the font: %s\n", strerror(errno));
        return false;
    }

    printf("Font successfully set to %s\n", font_name);
    return true;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        help_msg();
        return 1;
    }

    const char *command = argv[1];
    const char *font_name = argv[2];

    if (strcmp(command, "install") == 0) {
        const char *url = get_font_url(font_name);

        if (url == NULL) {
            fprintf(stderr, "Font not found: %s\n", font_name);
            return 1;
        }

        if (!create_fonts_directory()) {
            fprintf(stderr, "There was an error creating the directory\n");
            return 1;
        }

        char filename[512];
        snprintf(filename, sizeof(filename), "%s/.termux/fonts/%s.ttf", getenv("HOME"), font_name);

        if (curl_shortcut(url, filename)) {
            printf("The download was successful. The content was stored in %s\n", filename);
        } else {
            fprintf(stderr, "Error downloading the resource\n");
        }
    } else if (strcmp(command, "set") == 0) {
        if (!set_font(font_name)) {
            fprintf(stderr, "There was an error setting the font\n");
            return 1;
        }
    } else {
        help_msg();
        return 1;
    }

    return 0;
}