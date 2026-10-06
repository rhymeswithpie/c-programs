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

void swap(int *a, int *b) {
    int tempa;
    int tempb;

    tempb = *a;
    tempa = *b;
    *b = tempb;
    *a = tempa;

    
}


int main() {
    int num = 0;
    int x = 5;
    int y = 3;
    int *p;
    p = &num;
    *p = 6;
    swap(&x,&y);
    printf("%d, %d\n", x, y);
    printf("%d\n", *p);
    printf("%p\n", p);
    printf("%p\n", &p);
    printf("%p\n", &*&*&*&p);
}