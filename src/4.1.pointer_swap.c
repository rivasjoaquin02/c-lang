#include <stdio.h>

#define dprint(expr) printf(#expr " = %d\n", expr)

void swap(int x, int y) {
    int tmp = x;
    x = y;
    y = tmp;
}

void swap_p(int *x, int *y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

int main(void) {

    int a = 2, b = 3;

    swap(a, b);
    printf("Wrong Swap\n");
    dprint(a);
    dprint(b);

    swap_p(&a, &b);
    printf("Swap by reference\n");
    dprint(a);
    dprint(b);

    return 0;
}
