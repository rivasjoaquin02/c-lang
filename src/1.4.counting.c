#include <stdio.h>

main() {
    long number_chars = 0,
         number_lines = 0,
         number_blanks = 0,
         number_tabs = 0,
         last_char;
    int c;

    while ((c = getchar()) != EOF) {
        ++number_chars;

        if (c == '\n')
            ++number_lines;
        else if (c == ' ')
            ++number_blanks;
        else if (c == '\t')
            ++number_tabs;
        if (c != ' ' || (c == ' ' && last_char != ' '))
            putchar(c);

        last_char = c;
    }

    printf("\n\n");
    printf("chars: %ld \n", number_chars);
    printf("lines: %ld \n", number_lines);
    printf("blanks: %ld \n", number_blanks);
    printf("tabs: %ld \n", number_tabs);
}