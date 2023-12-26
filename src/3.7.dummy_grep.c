#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int get_line(char line[], int max);
int strindex(char source[], char searchfor[]);
int strindex_rightmost(char source[], char searchfor[]);

char pattern[] = "ould";

int main(void) {
    char line[MAXLINE];

    while (get_line(line, MAXLINE) > 0) {
        if (strindex_rightmost(line, pattern) >= 0) printf("%s\n", line);
    }

    return 0;
}

int get_line(char line[], int max) {
    int i, c;

    for (i = 0; (c = getchar()) != '\n' && c != EOF; ++i) line[i] = c;

    line[i] = '\0';

    return i;
}

int strindex(char source[], char searchfor[]) {
    int i, c, found;

    found = 0;
    for (i = 0; (c = source[i]) != '\0'; ++i) {
        if (source[i] == searchfor[0]) {
            found = 1;
            for (int k = 0; k < strlen(searchfor); ++k)
                if (source[i + k] != searchfor[k]) {
                    found = 0;
                    break;
                }
        }

        if (found) return i;
    }
    return -1;
}

int strindex_rightmost(char source[], char searchfor[]) {
    int i, c, found;

    int source_len = strlen(source);
    int searchfor_len = strlen(searchfor);

    found = 0;
    for (i = source_len - 1; i >= 0; --i) {
        if (source[i] == searchfor[searchfor_len - 1]) {
            found = 1;
            for (int k = 0; k < searchfor_len; ++k)
                if (source[i - k] != searchfor[searchfor_len - 1 - k]) {
                    found = 0;
                    break;
                }
        }

        if (found) return i;
    }
    return -1;
}
