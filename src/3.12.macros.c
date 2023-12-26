#include <stdio.h>

#define repeat(i, a, b) for (int i = a; i < b; ++i)
#define max(a, b) (a > b ? a : b)
#define square(x) (x) * (x)
#define square_err(x) x *x

// # operator concatenates
#define dprint(expr) printf(#expr " = %d\n", expr)
#define paste(front, back) front##back

#define swap_generic(t, x, y)                                                  \
    {                                                                          \
        t _x = x;                                                              \
        x = y;                                                                 \
        y = _x;                                                                \
    }
#define swap_num(a, b)                                                         \
    {                                                                          \
        a = a + b;                                                             \
        b = a - b;                                                             \
        a = a - b;                                                             \
    }

int main(void) {
    // to test this
    // gcc 3.12.macros.c -DDEBUG && ./a.out
    // should print "DEBUG-MODE" in stdout

#ifdef DEBUG
    printf("DEBUG-MODE");
    freopen("debug.log", "w", stdout);
#endif

    repeat(i, 0, 3) { printf("i: %d\n", i); }

    int a = 6;
    int b = 7;
    printf("max: %d\n", max(a + 1, b + 6));
    printf("max: %d\n", max(a++, b++));

    int c = 1;
    printf("%d\n", square(c + 1));     // (1 + 1) * (1 + 1) => 4
    printf("%d\n", square_err(c + 1)); // 1 + 1 * 1 + 1 => 3

    dprint(2 + 3);

    printf("x/y"
           " = x/y");

    // printf(paste(name, 1)); // => name1

    a = 1;
    b = 2;
    // swap_generic(int, a, b);
    swap_num(a, b);
    printf("\nswap: a:%d, b:%d", a, b);

    return 0;
}
