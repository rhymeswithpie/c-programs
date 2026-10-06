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

#ifdef _WIN32
#include <windows.h>
#define sleep(ms) Sleep(ms)
#else
#include <unistd.h>
#define sleep(ms) usleep((ms) * 1000)
#endif

int main() {
    FILE *ptr;
    
    char s[99999];

    char b[99999];

    int freq[127] = {0};

    int ch;

    printf("what file you wanna open? ");
    scanf("%s", &b);
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
    while ((ch = fgetc(ptr)) != EOF) {
        putchar(ch);
    }

    ptr = fopen(b, "r");

    
    printf("\n\n");
    printf("--ANALYSIS--");
    printf("\n\n");
    int chars = 0;
    int sps = 0;
    int tabs = 0;
    int nls = 0;
    while ((ch = fgetc(ptr)) != EOF) {
        chars++;
        if (ch == 32) {
            sps++;
        }
        else if (ch == 10) {
            nls++;
        }
        else if (ch == 9) {
            tabs++;
        }
        else {
            freq[ch]++;
        }
    }
    
    size_t len = sizeof(freq) / sizeof(freq[0]); 
    char c;
    printf("[newlines: %d] [spaces: %d] [tabs: %d] [total chars: %d]\n", nls, sps, tabs, chars);
    printf("[");
    for (size_t i = 33; i < len; i++) {
        c = i;
        printf("{");
        printf("%c", c);
        printf(", ");
        printf("%d", freq[i]);
        printf("}");
        if (i < len - 1) {
            printf(", ");
        }
    }
    
    printf("]\n");
    printf("--ANALYSIS--\n");

}