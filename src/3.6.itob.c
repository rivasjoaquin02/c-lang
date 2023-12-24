#include <stdio.h>
#define MAX 1000
#define END '\0'

void itob(const int n, char s[], const int b);
void reverse(char s[]);

int main(void) {
  int t, n, b;
  char s[MAX];

  scanf("%d", &t);

  while (t--) {
    scanf("%d %d", &n, &b);
    itob(n, s, b);
    printf("%s\n", s);
  }

  return 0;
}

void itob(const int n, char s[], const int b) {
  int i, num;

  i = 0;
  num = n;
  do {
    if (num % b < 10)
      s[i++] = (num % b) + '0';
    else
      s[i++] = (num % b - 10) + 'a';
  } while ((num /= b) > 0);

  s[i] = END;

  reverse(s);
}

void reverse(char s[]) {
  int i, length;

  // obtain the length of the string
  for (length = 0; s[length] != END; ++length)
    ;

  for (i = 0; i + i < length; ++i) {
    int tmp = s[i];
    s[i] = s[length - i - 1];
    s[length - i - 1] = tmp;
  }
}
