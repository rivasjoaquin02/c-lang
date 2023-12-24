#include "calc.h"
#include <ctype.h>
#include <stdio.h>

/* getop: returns the operator or the operand */
int getop(char s[]) {
    int i, c;

    while ((s[0] = c = getchar()) == ' ' || c == '\t')
        ;

    s[1] = '\0';

    if (!isdigit(c)) return c;

    for (i = 1; (c = getchar()) != '\n' && c != EOF; ++i) {
        if (isdigit(c) || c == '.') {
            s[i] = c;
        } else if (c == ' ') {
            s[i] = '\0';
            return NUMBER;
        } else
            return c;
    }

    return EOF;
}
