#include <stdio.h>

#define dprint(expr) printf(#expr, " = %d\n", expr)

int main() {

    int arr[] = {1, 2, 3, 4, 5};
    int n = 4;
    int *pa = arr;

    for (int i = 0; i < n; ++i) {
        printf("*pa + %d\n", i);
        printf("%d\n", *(pa + 1));
    }

    return 0;
}
