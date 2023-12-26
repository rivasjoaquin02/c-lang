#include <stdio.h>

#define MAX 1000

void itoa(int n, char s[]);

int main(void) {
    char s[MAX];
    int n;

    scanf("%d", &n);
    itoa(n, s);

    int i;
    for (i = 0; s[i] == '-' || (s[i] >= '0' && s[i] <= '9'); ++i)
        ;
    s[i] = '\0';

    printf("%s", s);

    return 0;
}

int i = 0;
void itoa(int n, char s[]) {
    if (n < 0) {
        s[i++] = '-';
        n = -n;
    }

    if (n / 10) itoa(n / 10, s);
    s[i++] = n % 10 + '0';
}
