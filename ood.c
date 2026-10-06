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

struct Person {
    int age;
    char* name;
};

int GetAge(struct Person* p) {return p -> age;}

int SetAge(struct Person* p, int a) {p -> age = a;}

char* GetName(struct Person* p) {return p -> name;}

char* SetName(struct Person* p, char* a) {p -> name = a;}


int main() {
    struct Person* p = malloc(sizeof(*p));
    SetAge(p, 13);
    SetName(p, "bros really be arguin g with s//e 1");
    
    printf("age -> %d name -> %s", GetAge(p), GetName(p));

    free(p);
}