#include <stdio.h>
#define dprint(expr) printf(#expr, " = %d\n", expr)

int str_len(char *s) {
    int n;
    for (n = 0; *s != '\0'; ++s, ++n)
        ;
    return n;
}

int str_len2(char *s) {
    char *p = s;
    while (*p != '\0') p++;
    return p - s;
}

int main() {

    int arr[] = {1, 2, 3, 4, 5};
    char s[] = {'a', 'b', 'c', 'd', 'e'};
    int n = 4;
    int *pa = arr;

    // this works 😲
    printf("%d\n", *(arr + 1)); // 2

    printf("%d\n", *pa); // 1
    ++*pa;
    printf("%d\n", *pa); // 2

    printf("%d\n", str_len(s));             // 5
    printf("%d\n", str_len("Hello World")); // 11

    return 0;
}
