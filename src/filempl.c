#include "filempl.h"

bool set_font(const char *font_name) {
    const char *home_dir = getenv("HOME");
    if (!home_dir) {
        fprintf(stderr, "Could not get home directory\n");
        return false;
    }

    char source_path[PATH_MAX];
    snprintf(source_path, sizeof(source_path), "%s/.termux/fonts/%s.ttf", home_dir, font_name);

    if (access(source_path, F_OK) == -1) {
        fprintf(stderr, "Font not found: %s\n", source_path);
        return false;
    }

    char target_path[PATH_MAX];
    snprintf(target_path, sizeof(target_path), "%s/.termux/font.ttf", home_dir);

    // printf("Source path: %s\n", source_path);
    // printf("Target path: %s\n", target_path);
 
    if (access(target_path, F_OK) == 0) {
        if (remove(target_path) != 0) {
            perror("Error removing existing font");
            return false;
        }
    }

    if (!copy_file(source_path, target_path)) {
        fprintf(stderr, "Error setting font: %s\n", strerror(errno));
        return false;
    }

    return true;
}

bool copy_file(const char *source_path, const char *target_path) {
    FILE *source_file = fopen(source_path, "rb");
    if (!source_file) {
        fprintf(stderr, "Error opening source file: %s\n", source_path);
        return false;
    }

    FILE *target_file = fopen(target_path, "wb");
    if (!target_file) {
        fclose(source_file);
        fprintf(stderr, "Error opening target file: %s\n", target_path);
        return false;
    }

    int ch;
    while ((ch = fgetc(source_file)) != EOF) {
        if (fputc(ch, target_file) == EOF) {
            fclose(source_file);
            fclose(target_file);
            fprintf(stderr, "Error writing to target file\n");
            return false;
        }
    }

    fclose(source_file);
    fclose(target_file);
    return true;
}

void set_default_font(void) {
    const char *home_dir = getenv("HOME");
    if (!home_dir) {
        fprintf(stderr, "Could not get home directory\n");
        return;
    }

    char path[PATH_MAX];
    snprintf(path, sizeof(path), "%s/.termux/font.ttf", home_dir);

    if (access(path, F_OK) != 0) {
        printf("You haven't established a default font yet.\n");
        return;
    }

    if (remove(path) != 0) {
        perror("Error removing default font");
        return;
    }

    system("termux-reload-settings");
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