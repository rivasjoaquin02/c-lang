#include <ctype.h>
#include <stdio.h>

#define SIZE 10000
#define dprinti(expr) printf(#expr " = %d\n", expr)
#define dprintf(expr) printf(#expr " = %f\n", expr)

/* getint: reads the int from stdin in x
 * returns EOF or 0 if not a number or positive if valid */
int getint(int *n);
int getfloat(float *n);

int main(void) {
    int n, m, s;
    int ints[SIZE];
    float floats[SIZE];

    // for (n = 0; (s = getint(&ints[n])) != EOF && s != 0; ++n)
    //     ;
    // dprinti(n);
    // for (int i = 0; i < n; ++i) dprinti(ints[i]);

    for (m = 0; (s = getfloat(&floats[m])) != EOF && s != 0; ++m)
        ;
    dprinti(m);
    for (int i = 0; i < m; ++i) dprintf(floats[i]);

    return 0;
}

int getint(int *n) {
    int c, sign;

    // skip white spaces
    while (isspace(c = getchar()))
        ;

    // other character
    if (c != '-' && c != '+' && !isdigit(c) && c != EOF) {
        ungetc(c, stdin);
        return 0;
    }

    // sign of number
    sign = c == '-' ? -1 : 1;

    // if current char is sign move upwords
    if (c == '-' || c == '+') c = getchar();

    for (*n = 0; isdigit(c); c = getchar()) *n = 10 * *n + (c - '0');

    // give sign
    *n *= sign;

    if (c != EOF) ungetc(c, stdin);
    return c;
}

int getfloat(float *n) {
    int c, sign;
    float exp;

    // skip white spaces
    while (isspace(c = getchar()))
        ;

    // other character
    if (c != '-' && c != '+' && !isdigit(c) && c != EOF) {
        ungetc(c, stdin);
        return 0;
    }

    // sign of number
    sign = c == '-' ? -1 : 1;

    // if current char is sign move upwords
    if (c == '-' || c == '+') c = getchar();

    for (*n = 0; isdigit(c); c = getchar()) *n = 10.0 * *n + (c - '0');
    if (c == '.') c = getchar();
    for (exp = 1.0; isdigit(c); c = getchar()) {
        *n = 10.0 * *n + (c - '0');
        exp *= 10.0;
    }

    // give sign and exp
    *n *= sign;
    *n /= exp;

    if (c != EOF) ungetc(c, stdin);
    return c;
}
