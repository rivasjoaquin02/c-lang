#include <ctype.h>
#include <stdio.h>
#define MAX 1000
#define END '\0'

/* declarations */
int get_line(char line[]);
int htoi(const char hex[]);
int map_to_hex(const int ch);
int str_len(const char s[]);
int pow(const int base, const int exp);

int main(void) {
    char hex[MAX];
    while (get_line(hex) > 0) {
        int n = htoi(hex);
        printf("%d", n);
    }

    return 0;
}

enum HEX { a = 10,
           b,
           c,
           d,
           e,
           f };

int htoi(const char hex[]) {
    int n, i, length, lo;

    n = 0;
    lo = hex[1] == 'x' ? 2 : 0;
    length = hex[1] == 'x' ? str_len(hex) : str_len(hex) - 1;

    int c, curr;
    for (i = lo; hex[i] != END && hex[i] != 'h' && hex[i] != 'H'; ++i) {
        c = hex[i];

        if (c >= '0' && c <= '9') {
            curr = c - '0';
        } else if (c >= 'a' && c <= 'z') {
            curr = map_to_hex(c);
        } else if (c >= 'A' && c <= 'Z') {
            int lowerc = tolower(c);
            curr = map_to_hex(lowerc);
        }
        n += (curr * pow(16, length - i - 1));
    }

    return n;
}

int get_line(char line[]) {
    int i, c;

    for (i = 0; (c = getchar()) != EOF; ++i)
        line[i] = c;

    line[i] = END;

    return i;
}

int map_to_hex(const int ch) {
    switch (ch) {
        case 'a':
            return a;
        case 'b':
            return b;
        case 'c':
            return c;
        case 'd':
            return d;
        case 'e':
            return e;
        case 'f':
            return f;
    }
    return -1;
}

int str_len(const char s[]) {
    int i;

    for (i = 0; s[i] != END; i++)
        ;

    return i;
}

int pow(const int base, const int exp) {
    int n = 1;

    for (int i = 0; i < exp; ++i)
        n *= base;

    return n;
}