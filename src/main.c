#include "include.h"
#include "fonts.h"
#include "shortcurl.h"

void help_msg() {
  printf("usage:\n");
  printf("  termux-font install <font_name>\n");
  printf("  termux-font set <font_name>\n");
  printf("  termux-font default\n");
}

bool create_fonts_directory() {
    const char *home_dir = getenv("HOME");
    if (!home_dir) {
        fprintf(stderr, "could not get directory\n");
        return false;
    }

    char path[PATH_MAX];
    snprintf(path, sizeof(path), "%s/.termux", home_dir);

    if (mkdir(path, 0755) && errno != EEXIST) {
        fprintf(stderr, "Could not create directory: %s\n", path);
        return false; 
    }

    snprintf(path, sizeof(path), "%s/.termux/fonts", home_dir);

    if (mkdir(path, 0755) && errno != EEXIST) {
        fprintf(stderr, "Could not create directory: %s\n", path);
        return false; 
    }

    return true;
}

bool set_font(const char *font_name) {
    const char *home_dir = getenv("HOME");
    if (!home_dir) {
        fprintf(stderr, "could not set directory\n");
        return false;
    }

    char source_path[PATH_MAX];
    snprintf(source_path, sizeof(source_path), "%s/.termux/fonts/%s.ttf", home_dir, font_name);

    char target_path[PATH_MAX];
    snprintf(target_path, sizeof(target_path), "%s/.termux/font.ttf", home_dir);
    system("termux-reload-settings");

    if (access(source_path, F_OK) == -1) {
        fprintf(stderr, "Font not found: %s\n", source_path);
        return false;
    }

    if (access(target_path, F_OK) == 0) {
        remove(target_path);
    }

    if (rename(source_path, target_path) != 0) {
        perror("error setting font");
        return false;
    }

    return true;
}

void set_default_font() {
    const char *home_dir = getenv("HOME");
    if (!home_dir) {
        fprintf(stderr, "could not set directory\n");
    }

    char path[PATH_MAX];
    snprintf(path, sizeof(path), "%s/.termux/font.ttf", home_dir);

    if (access(path, F_OK) != 0) {
        printf("you havent established a font yet\n");
    }

    remove(path);
    system("termux-reload-settings");
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

        const char *home_dir = getenv("HOME");
        char filename[512];
        snprintf(filename, sizeof(filename), "%s/.termux/fonts/%s.ttf", home_dir, font_name);

        if (curl_shortcut(url, filename)) {
            printf("The download was successful. The content was stored in %s\n", filename);
        } else {
            fprintf(stderr, "Error downloading the resource\n");
            return 1;
        }
        
    } else if (strcmp(command, "set") == 0) {
        if (set_font(font_name)) {
            printf("Font set successfully.\n");
        } else {
            fprintf(stderr, "There was an error setting the font\n");
            return 1;
        }

    } else if (strcmp(command, "default") == 0) {
        set_default_font();

    } else {
        help_msg();
        return 1;
    }

    return 0;
}
