#include "../include/fonts.h"

int opt;
struct stat info;

void process() {
    system("clear");
    printf("\nque fuente quieres instalar\n\n1. Cascadia Code\n2. Fira Code\nm3. Mononoki\n 4. Hack\n5. JetBrainsMono\n\n\033[0mfonts patched by \033[33mNerdFonts\033[0m\n>> ");
    scanf("%d",&opt);
    
    switch (opt) {

    case 1:
        if (stat(FONTS_DIRECTORY"/cascadia-code.ttf", &info) == 0) {  
            printf("\033[33mesta tipografia ya a sido instalada\n");
            sleep(2);
            break;

        } else if (!S_ISREG(info.st_mode)) {
            system(FONTS_H(cascadia_code_nerd));
            printf("Quieres establecer esta fuente?(s/N): ");
            scanf("%c", &opt);

            if (opt == "s" || opt == "S") {
                set_terminal_font(cascadia_code);
                break;
            } else {
                printf("abortar");
                break;
            }
        }

    case 2:
        if (stat(FONTS_DIRECTORY"/fira-code.ttf", &info) == 0) { 
          printf("\033[33mesta tipografia ya a sido instalada\n"); 
          sleep(2);
            break;

        } else if (!S_ISREG(info.st_mode)) {
            system(FONTS_H(fira_code_nerd));
            printf("Quieres establecer esta fuente?(s/N): ");
            scanf("%c", &opt);

            if (opt == "s" || opt == "S") {
                set_terminal_font(fira_code);
                break;
            } else {
                printf("abortar");
                break;
            }
        }

    case 3:
        if (stat(FONTS_DIRECTORY"/mononoki.ttf", &info) == 0) {
            printf("\033[33mesta tipografia ya a sido instalada\n");
            sleep(2);
            break;

        } else if  (!S_ISREG(info.st_mode)) {
            system(FONTS_H(mononoki_nerd));
            printf("Quieres establecer esta fuente?(s/N): ");
            scanf("%c", &opt);
            if (opt == "s" || opt == "S") {
                set_terminal_font(mononoki);
                break;
            } else {
                printf("abortar");
                break;
            }
   
        }
    case 4:
        if (stat(FONTS_DIRECTORY"/hack.ttf", &info) == 0) {
            printf("\033[33mesta tipografia ya a sido instalada\n");
            sleep(2);
            break;

        } else if  (!S_ISREG(info.st_mode)) {
            system(FONTS_H(mononoki_nerd));
            printf("Quieres establecer esta fuente?(s/N): ");
            scanf("%c", &opt);

            if (opt == "s" || opt == "S") {
                set_terminal_font(hack);
                break;
            } else {
                printf("abortar");
                break;
            }
        }
    case 5:
        if (stat(FONTS_DIRECTORY"/jetbrains.ttf", &info) == 0) {
        printf("\033[33mesta tipografia ya a sido instalada\n");
        sleep(2);
        break;

        } else if  (!S_ISREG(info.st_mode)) {
            system(FONTS_H(jetbrainsmono_nerd));
            printf("Quieres establecer esta fuente?(s/N): ");
            scanf("%c", &opt);

            if (opt == "s" || opt == "S") {
                set_terminal_font(jetbrainsmono);
                break;
            } else {
                printf("abortar");
                break;
            }
   
        }
    default:
        break;
    }
}

void check_directory() {
    if(stat(FONTS_DIRECTORY, &info) == 0 || !S_ISDIR(info.st_mode)) {
        mkdir(FONTS_DIRECTORY, 0777);
        process();
    }
}


int main() {
    for(int i = 0; i < 1; i++) {
        int result = system("command -v wget");

        if(WIFEXITED(result) && WEXITSTATUS(result) == 0) {
            check_directory();
            break;
        }

        result = system("pkg add wget");
        
        if (WIFEXITED(result) && WEXITSTATUS(result) == 0) {
            break;
        } else  {
            fprintf(stderr, "\033[31Hubo un error al instalar wget, revisa tu conexcion a internet\n");
        }
    }

    return 0;

}