#include <stdio.h>

/*
 * | OR
 * ^ XOR
 * << left shift
 * >> right shift
 * ~ complement (uniry)
 */

int main(void) {

    int n = 9;
    n = n << 2; // equivalent to x*4

    printf("%d\n", n);

    return 0;
}