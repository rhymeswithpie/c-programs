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
    double a = 812438120419848;
    double base = 16;
    char out[99999] = {0};
    char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    double i = 1;
    int outindex = 0; 
    double li = 0;

    for(;;) {
        while (pow(base,i) <= a) {
            i++;
            printf("a");
        }

        if (li != 0 && li - i > 1) {
            for (int k = 0; k < (int)(li - i - 1); k++) {
                out[outindex++] = '0';
            }
        }

        int count = 0;
        double cpower = pow(base, i - 1);
        while (a >= cpower) {
            count++;
            a -= cpower;
        }
        
        out[outindex++] = digits[count];
        
        if (a <= 0) {
            while (i > 1) {
                out[outindex++] = '0';
                i--;
            }
            goto im_using_a_goto_and_theres_nothing_you_can_do_about_it;
        }
        li = i;
        i = 1;
    }

im_using_a_goto_and_theres_nothing_you_can_do_about_it: {
    printf("%s", out);
}

}