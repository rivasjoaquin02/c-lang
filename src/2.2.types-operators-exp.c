#include <stdio.h>
#include <limits.h>
#include <float.h>


int main() {
    printf("int: %d - %d\n", INT_MIN, INT_MAX);
    printf("uint: %d - %o\n\n", 0, UINT_MAX);

    printf("short: %d - %d\n", SHRT_MIN, SHRT_MAX);
    printf("ushort: %d - %o\n\n", 0, USHRT_MAX);

    printf("long: %ld - %ld\n", LONG_MIN, LONG_MAX);
    printf("ulong: %ld - %o\n", 0, ULONG_MAX);

    printf("char: %d - %d\n", CHAR_MIN, CHAR_MAX);
    printf("char: %d - %o\n\n", 0, UCHAR_MAX);

    printf("float: %f - %f\n", FLT_MIN, FLT_MAX);
    printf("double: %lf - %lf\n", DBL_MIN, DBL_MAX);

    return 0;
}