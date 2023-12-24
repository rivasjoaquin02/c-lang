#include <stdio.h>
#define MAXLINE 1000
#define END '\0'

int get_line(char line[], int maxlength);
void replace_blanks(char line[]);

int main(void) {
    char line[MAXLINE];

    while (get_line(line, MAXLINE) > 0) {
        replace_blanks(line);
        printf("%s", line);
    }

    return 0;
}

int get_line(char line[], int maxlength) {
    int c, i;

    for (i = 0; i < maxlength && (c = getchar()) != EOF; ++i)
        line[i] = c;

    line[i] = END;

    return i;
}

/* replace_blanks: replaces blank spaces with number of them */
/* ej: abc  ef => abc2ef*/
void replace_blanks(char line[]) {
    int lastc, i, p, c, space_count;

    for (i = 0, p = 0, space_count = 0; line[i] != END; ++i) {
        c = line[i];

        if (c != ' ') {
            if (lastc == ' ') 
                line[p++] = '0' + space_count;
            line[p++] = c;
            space_count = 0;
        } else {
            ++space_count;
        }

        lastc = c;
    }

    line[p] = END;
}