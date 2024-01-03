#include <stdio.h>

#define dprint(expr) printf(#expr " = %d\n", expr)

int main(void) {

    int a = 10;
    int b = 20;
    int *ip;

    ip = &a;
    dprint(*ip);

    b = *ip;
    dprint(b);

    *ip = 0;
    dprint(*ip);
    dprint(a);

    int c[] = {324, 12, 45, 2, 5};
    ip = c;

    dprint(*ip);
    ip++; // increase the address pos
    dprint(*ip);
    ++*ip;   // increase the value
    (*ip)++; // increase the value
    dprint(*ip);

    printf("sfjkj");

    return 0;
}
