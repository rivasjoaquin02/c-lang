#include <stdio.h>

double a = 30;
int sum(register int a, register int b) { return a + b; }

int main(void) {
    char *pattern = "ould";
    // char pattern[] = {'o', 'u', 'l', 'd', '\0'};

    printf("%d", sum(45, 23));
    printf("%s", pattern);

    return 0;
}
