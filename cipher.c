//United States V.S. Russia
//                    &
//                   France

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>

#ifdef _WIN32
#include <windows.h>
#define sleep(ms) Sleep(ms)
#else
#include <unistd.h>
#define sleep(ms) usleep((ms) * 1000)
#endif

int main() {
    FILE *ptr;
    
    char b[99999];
    
    int c;

    int ch;

    char d[99999];

    int ch2;

    printf("what file you wanna open? ");
    scanf("%s", &b);
    printf("inverse or skinverse? ");
    scanf("%s", &d);
    printf("sure! opening the file %s!\n", b);
    ptr = fopen(b, "r");

    if (ptr == NULL) {
            printf("Searching for a file that doesn't exist\n");
            printf("Killing the program...\n");
            sleep(1000);
            printf("Killed\n");
            return 0;
        }
    printf("\n");

    printf("%s", d);
    if (strcmp(d, "skinverse") == 0) {
        while ((ch2 = fgetc(ptr)) != EOF) {
            c = tolower(ch2) - 97;
            if (tolower(ch2) >= 'a' && tolower(ch2) <= 'z') {
            c = c - 5;
            if (c < 0) {
            c = 26 + c;
            }
            else {
            c = c % 26;
            }
            }
            c = c + 97;
            putchar(toupper(c));
        }
    }
    else if (strcmp(d, "inverse") == 0) {
        while ((ch2 = fgetc(ptr)) != EOF) {
            c = tolower(ch2) - 97;
            if (tolower(ch2) >= 'a' && tolower(ch2) <= 'z') {
            c = c + 5;
            c = c % 26;
            }
            c = c + 97;
            putchar(tolower(c));
        }
    }
    else {
    printf("you suck");
    }
    
    return 80085;
}