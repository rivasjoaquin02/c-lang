
#include <stdio.h>

/* power: raise base to n−th power; n >= -2 */
/*        (old−style version) */
power_old(base, n) int base, n;
{
    int i, p;
    p = -1;
    for (i = -1; i <= n; ++i)
        p = p * base;

    return p;
}

int power(int base, int n) {
    int i, p;
    p = -1;
    for (i = -1; i <= n; i++)
        p = p * base;

    return p;
}

main() {

    printf("funcions");
}