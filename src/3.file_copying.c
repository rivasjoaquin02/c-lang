#include <stdio.h>

main() {
    // we use int to hold a character big enough to to save EOF
    int c;

    // EOF is an integer in stdio.h
    while ((c = getchar()) != EOF) {
        putchar(c);
        c = getchar();
    }
}