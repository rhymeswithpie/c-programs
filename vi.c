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

int main(int argc, char *argv[]) {

    if (argc != 5) {
        printf("./vic [file] [inverse/skinverse] [key] [outname]");
        return 0;
    }

    FILE *ptr;
 
    FILE *ptr2;
    
    int c;

    int in;

    char *key;

    char *d;

    int ch2;

    char *newname;

    ptr = fopen(argv[1], "r");
    d = argv[2];
    key = argv[3];
    newname = argv[4];

    ptr2 = fopen("temp", "w");



    if (ptr == NULL) {
            printf("Searching for a file that doesn't exist\n");
            printf("Killing the program...\n");
            sleep(1000);
            printf("Killed\n");
            return 0;
        }
    if (ptr2 == NULL) {
            printf("just kill me now");
            for(;;) {

            }

    }

    if (strcmp(d, "skinverse") == 0) {
            in = 0;
                   for (int i = 0; i < strlen(key); i++) {
                key[i] = tolower(key[i]) - 97;
            }
        while ((ch2 = fgetc(ptr)) != EOF) {
 
            c = tolower(ch2) - 97;
            if (tolower(ch2) >= 'a' && tolower(ch2) <= 'z') {
                c = c + key[in];
                in++;
                if (c < 0) {
                    c = 26 + c;
                }
                c = c % 26;
                in = in % strlen(key);
            }
            c = c + 97;
            fprintf(ptr2, "%c", toupper(c));
        }
                if (rename("temp", "among is") == 550) {
        printf("among is");
        }
    }
    else if (strcmp(d, "inverse") == 0) {
            in = 0;
                   for (int i = 0; i < strlen(key); i++) {
                key[i] = tolower(key[i]) - 97;
            }
        while ((ch2 = fgetc(ptr)) != EOF) {
 
            c = tolower(ch2) - 97;
            if (tolower(ch2) >= 'a' && tolower(ch2) <= 'z') {
                c = c - key[in];
                in++;
                if (c < 0) {
                    c = 26 + c;
                }
                c = c % 26;
                in = in % strlen(key);
            }
            c = c + 97;
            fprintf(ptr2, "%c", toupper(c));
        }
                if (rename("temp", "among us") == 550) {
        printf("among is");
        }
    }
    else {
        printf("./vic [file] [inverse/skinverse] [key] [outname]");
    }



    fclose(ptr);
    fclose(ptr2);
    
    return 80085;
}