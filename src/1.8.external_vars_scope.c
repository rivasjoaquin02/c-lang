#include <stdio.h>
#define MAX_LINE 10000

int get_line(void);
void copy(void);

int max;
char line[MAX_LINE];
char longest[MAX_LINE];

/* print the longest input line */
main() {
    int len;
    extern int max;
    extern char longest[];

    max = 0;
    while ((len = get_line()) > 0) {

        if (len > 10)
            printf("%s\n", line);

        if (len > max) {
            max = len;
            copy();
        }
    }

    if (max > 0)
        printf("\nlength: %d \nlongest: %s", max, longest);

    return 0;
}

/* copy: copy 'from' into 'to' */
void copy(void) {
    extern char line[];
    extern char longest[];

    int i = 0;

    while ((longest[i] = line[i]) != '\0')
        ++i;
}

/* getline: read a line into s, return length */
int get_line(void) {
    extern char line[];

    int c, len;

    for (len = 0; len < MAX_LINE - 1 & (c = getchar()) != EOF & c != '\n'; len++) {
        line[len] = c;
    }
    line[len + 1] = '\0';

    return len;
}
