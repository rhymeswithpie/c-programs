#include <stdio.h>
#include <string.h>

int main() {
    char f[500];
    printf("hi guys\n");
    printf("skin ");
    fgets(f, sizeof(f), stdin);
    if(f == "cats") {
        printf("dogs");
    }
    else {
        printf("hamster");
    }
    printf(f);
    return 900000000;
}