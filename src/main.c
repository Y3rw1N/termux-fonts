#include "include.h"
#include "fonts.h"
#include "shortcurl.h"
#include "filempl.h"

void help_msg() {
  printf("usage:\n");
  printf("  termux-font install <font-name>\n");
  printf("  termux-font set <font-name>\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        help_msg();
        return 1;
    }

    const char *command = argv[1];
    const char *font_name = argv[2];

    if (strcmp(command, "install") == 0) {

        if (argc != 3) {
            help_msg();
            return 1;
        }

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

        if (argc != 3) {
            help_msg();
            return 1;
        }

        if (strcmp(command, "default") == 0) {
            set_default_font();
        } else {
            if (set_font(font_name)) {
                printf("Font set successfully.\n");
                system("termux-reload-settings");
            } else {
                fprintf(stderr, "There was an error setting the font\n");
                return 1;
            }
        }

    } else {
        help_msg();
        return 1;
    }

    return 0;
}
