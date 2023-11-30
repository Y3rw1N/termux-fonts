// This script was created to be a shortcut

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

#include "../include/fonts.h"
#include "../include/utils.h"

// variables
int opt; // important
struct stat info; // important

void menu() {
	printf("What font do you want to install?\n\n[\033[33m1\033[0m] Caskaydia Cove\n[\033[31m2\033[0m]. Fira Code\n[\033[34m3\033[0m] Mononoki\n[\033[36m4\033[0m] Hack\n[0] exit\n>> ");
	scanf("%d", &opt);

	switch (opt) {
		case 1:
			if (stat(FONTS_DIRECTORY "/cascadia-code.ttf", &info) == 0) {
				printf("this font was already installed\n");
				break;
			} else {
				system(cascadia_code_nerd);
			}
		case 2:
			if (stat(FONTS_DIRECTORY "/fira-code.ttf", &info) == 0) {
				printf("this font was already installed\n");
				break;
			} else {
				system(fira_code_nerd);
			}
		case 3:
			if (stat(FONTS_DIRECTORY "/mononoki.ttf", &info) == 0) {
				printf("this font was already installed\n");
				break;
			} else {
				system(mononoki_nerd);
			}
		case 4:
			if (stat(FONTS_DIRECTORY "/hack.ttf", &info) == 0) {
				printf("this font was already installed\n");
				break;
			} else {
				system(hack_nerd);
				break;
			}
		case 5:
			if (stat(FONTS_DIRECTORY "/jetbrains-mono.ttf", &info) == 0) {
				printf("this font was already installed\n");
				break;
			} else {
				system(fira_code_nerd);
				break;
			}
	}
}


void dir_check() {
  if (stat(FONTS_DIRECTORY, &info) == 0 || !S_ISDIR(info.st_mode)) {
		mkdir(FONTS_DIRECTORY, 0777);
		menu();
  }
}

int main(int argc, char *argv[]) {
	if (argc == 1) {
		for (int i = 0; i < 1; i++) {
			int req = system("command -v wget");

			if(EXISTSCMD(req)) {
				dir_check();
				break;
			}

			req = system("pkg add wget -y &>>/dev/null");

			if (EXISTSCMD(req)) {
				break;
			} else {
				fprintf(stderr, "\033[please check your internet connection\n");
				sleep(2);
			}	
		}
	} else if (argc == 2 && strcmp(argv[1], "-H") == 0) {
			help_message(argv[0]);
	} else if (argc == 3 && strcmp(argv[1], "-S") == 0) {
			set_font(argv[2]);
	} else {
			return 1;
		}
	return 0;
}
