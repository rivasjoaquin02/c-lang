#include <stdio.h>
#include <string.h>

#define ARRAY_LENGTH 240
const int ARRAY_LENGTH_INT = 240;

enum escapes { BELL = '\a',
               BACKSPACE = '\b',
               TAB = '\t',
               NEWLINE = '\n',
               VTAB = '\v',
               RETURN = '\r' };

int main(void) {

    int bell = BACKSPACE;
    printf("%d%d", 2, bell);
    return 0;
}