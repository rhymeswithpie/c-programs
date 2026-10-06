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

int* CreateInt(int n) {
    
    int *a = malloc(sizeof(int));
    *a = n;
    return a;
    
}


int main() {
    int* x = CreateInt(5);
    printf("%d", *x);
    free(x);
}
