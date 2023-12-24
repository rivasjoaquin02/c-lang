#include "calc.h"
#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100

int main(void) {
    int type;
    char s[MAXOP];

    while ((type = getop(s)) != EOF && type != '\n') {
        switch (type) {
        case NUMBER:
            push(atof(s));
            break;
        case ADD:
        case SUB:
        case MUL:
        case DIV:
        case RES: {
            const double result = calculate(pop(), pop(), type);
            push(result);
            break;
        }
        default:
            break;
        }
    }

    const double result = pop();
    printf("%.3g", result);

    return 0;
}
