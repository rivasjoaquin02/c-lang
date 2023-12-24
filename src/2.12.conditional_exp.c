#include <stdio.h>



int main(void) {

    int a = 10;
    float b = 10.0;

    printf("%.2f", a > b ? a : b);

    return 0;
}