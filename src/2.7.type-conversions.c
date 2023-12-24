#include <ctype.h>
#include <stdio.h>

int atoi(char s[]) {
    int ans = 0;
    // for (int i = 0; s[i] >= '0' && s[i] <= '9'; ++i) {
    for (int i = 0; isdigit(s[i]); ++i) {
        ans = (ans * 10) + (s[i] - '0');
    }
    return ans;
}

// tolower from ctype.h do the same
int lower(int c) {
    if (c >= 'A' && c <= 'Z')
        return c + 'a' - 'A';
    return c;
}

int main(void) {

    printf("%d", atoi("10203"));

    return 0;
}