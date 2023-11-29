#include "./include/fonts.h"

int opt;
struct stat info;

void process() {
    system("clear");
    printf("\nque tipografia quieres instalar\n\n1. Cascadia Code\n2. Fira Code\n\033[31m3. Mononoki\n\n\033[0mfonts patched by \033[33mNerdFonts\033[0m\n>> ");
    scanf("%d",&opt);
    
    switch (opt) {
    case 1:
        if (stat(FONTS_DIRECTORY"/cascadia-code.ttf", &info) == 0) {  
            printf("esta tipografia ya a sido instalada");
            break;
        } else if (!S_ISREG(info.st_mode)) {
            system(cascadia_code);
            break;
        }
    case 2:
        if (stat(FONTS_DIRECTORY"/fira-code.ttf", &info) == 0) { 
            printf("esta tipografia ya a sido instalada"); 
            break;
        } else if (!S_ISREG(info.st_mode)) {
            system(fira_code);
            break;
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


int main(int i) {
    for(i = 0; i < 1; i++) {
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
