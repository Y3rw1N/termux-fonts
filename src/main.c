#include "include.h"
#include "fonts.h"
#include "shortcurl.h"
#include "filempl.h"

void help_msg() {
    printf("usage:\n");
    printf("  termux-font install [--gui] <font-name>\n");
    printf("  termux-font set <font-name>\n");
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        help_msg();
        return 1;
    }

    const char *command = argv[1];
    bool is_gui = false;
    const char *font_name = NULL;

    if (strcmp(command, "install") == 0) {
        if (strcmp(argv[2], "--gui") == 0) {
            is_gui = true;
            font_name = argv[3];
        } else {
            font_name = argv[2];
        }

        if (!font_name) {
            help_msg();
            return 1;
        }

        const char *url = get_font_url(font_name);
        if (!url) {
            fprintf(stderr, "Font not found: %s\n", font_name);
            return 1;
        }

        if (!create_fonts_directory()) {
            fprintf(stderr, "There was an error creating the directory\n");
            return 1;
        }

        char filename[PATH_MAX];
        if (is_gui) {
            const char *PREFIX = getenv("PREFIX");
            snprintf(filename, sizeof(filename), "%s/share/fonts/TTF/%s.ttf", PREFIX, font_name);

            char dirpath[PATH_MAX];
            snprintf(dirpath, sizeof(dirpath), "%s/share/fonts/TTF", PREFIX);
            if (mkdir(dirpath, 0755) && errno != EEXIST) {
                fprintf(stderr, "Could not create directory: %s\n", dirpath);
                printf("It could be because you don't have a desktop environment installed yet\nif that is not the case create the directory manually.\n");
                return 1;
            }

            if (!curl_shortcut(url, filename)) {
                fprintf(stderr, "Error downloading the resource\n");
                return 1;
            }

            printf("The download was successful. The content was stored in %s\n", filename);
            return 0;
        }

        const char *home_dir = getenv("HOME");
        snprintf(filename, sizeof(filename), "%s/.termux/fonts/%s.ttf", home_dir, font_name);

        if (!curl_shortcut(url, filename)) {
            fprintf(stderr, "Error downloading the resource\n");
            return 1;
        }

        printf("The download was successful. The content was stored in %s\n", filename);
        return 0;
    }

    if (strcmp(command, "set") == 0) {
        font_name = argv[2];

        if (strcmp(font_name, "default") == 0) {
            set_default_font();
            return 0;
        }

        if (set_font(font_name)) {
            printf("Font set successfully.\n");
            system("termux-reload-settings");
            return 0;
        }

        fprintf(stderr, "There was an error setting the font\n");
        return 1;
    }

    help_msg();
    return 1;
}
