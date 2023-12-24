#include <stdio.h>
#define MAX 1000
#define END '\0'

int any(const char s1[], const char s2[]);
void get_line(char s[]);

int main(void) {

    char s1[MAX];
    char s2[MAX];

    get_line(s1);
    get_line(s2);

    printf("%d", any(s1, s2));

    return 0;
}

int any(const char s1[], const char s2[]) {
    int pos = -1;

    for (int i = 0; s1[i] != END; i++)
        for (int j = 0; s2[j] != END; j++)
            if (s1[i] == s2[j])
                return i;

    return pos;
}

void get_line(char s[]) {
    int i, c;

    for (i = 0; (c = getchar()) != '\n' && c != EOF; i++)
        s[i] = c;

    s[i] = '\0';

    return i;
}