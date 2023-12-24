#include <stdio.h>

int lower(const int c);

int main(void) {

    int c = getchar();
    c = lower(c);
    putchar(c);

    return 0;
}

int lower(const int c) {
    return c == 'A'
               ? 'a'
           : c == 'B'
               ? 'b'
           : c == 'C'
               ? 'c'
               : '.';
}