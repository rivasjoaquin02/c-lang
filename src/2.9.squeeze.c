#include <stdbool.h>
#include <stdio.h>
#define MAX 1000

void squeeze(char s1[], const char s2[]);
void get_line(char s[]);

int main(void) {
    char s1[MAX], s2[MAX];
    get_line(s1);
    get_line(s2);

    squeeze(s1, s2);

    printf("%s\n", s1);

    return 0;
}

void squeeze(char s1[], const char s2[]) {
    int i, j;
    bool exist;

    for (i = j = 0; s1[i] != '\0'; i++) {
        exist = false;

        for (int k = 0; !exist && s2[k] != '\0'; k++)
            if (s1[i] == s2[k])
                exist = true;

        if (!exist)
            s1[j++] = s1[i];
    }

    s1[j] = '\0';
}

void get_line(char s[]) {
    int i, c;

    for (i = 0; (c = getchar()) != '\n' && c != EOF; i++)
        s[i] = c;

    s[i] = '\0';

    return i;
}
