#include <stdio.h>
#define MAXVAL 10000

static int sp = -1;
static double stack[MAXVAL];

void push(const double f) {
    if (sp + 1 < MAXVAL)
        stack[++sp] = f;
    else
        printf("Error the stack is full\n");
}

double pop(void) {
    if (sp >= 0) return stack[sp--];

    printf("Error the stack is empty\n");
    return 0.0;
}
