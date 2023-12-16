#include <stdio.h>
#define MAX_LINE 10000

int get_line(char line[], int lim);
void copy(char to[], char from[]);
void reverse(char s[], int length);

/* print the longest input line */
main() {
    int len, max;
    char line[MAX_LINE];
    char longest[MAX_LINE];

    max = 0;
    while ((len = get_line(line, MAX_LINE)) > 0) {
        reverse(line, len);

        if (len > 10)
            printf("%s\n", line);

        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }

    if (max > 0)
        printf("\nlength: %d \nlongest: %s", max, longest);

    return 0;
}

/* copy: copy 'from' into 'to' */
void copy(char to[], char from[]) {
    int i = 0;

    while ((to[i] = from[i]) != '\0')
        ++i;
}

/* getline: read a line into s, return length */
int get_line(char line[], int lim) {
    int c, len;

    for (len = 0; len < lim - 1 & (c = getchar()) != EOF & c != '\n'; len++) {
        line[len] = c;
    }
    line[len + 1] = '\0';

    return len;
}

void reverse(char s[], int length) {
    for (int i = 0; i * 2 < length; ++i) {
        int tmp = s[i];
        s[i] = s[length - i - 1];
        s[length - i - 1] = tmp;
    }
}