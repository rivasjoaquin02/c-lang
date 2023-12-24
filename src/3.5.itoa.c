#include <stdio.h>
#include <string.h>
#define MAX 1000
#define END '\0'

void itoa(const int n, char s[]);
void reverse(char s[]);

int main(void) {
  char s[MAX];
  int n;

  scanf("%d", &n);
  itoa(n, s);
  // printf("%s\n", s);
  reverse(s);
  printf("%s", s);

  return 0;
}

void itoa(const int n, char s[]) {
  int i, c, sign, num;

  num = n;
  if ((sign = num) < 0)
    num = -num;

  i = 0;
  do {
    c = num % 10 + '0';
    s[i++] = c;
  } while ((num /= 10) > 0);

  if (sign < 0)
    s[i++] = '-';

  s[i] = END;
}

void reverse(char s[]) {
  int i, length;

  length = strlen(s);

  for (i = 0; i + i < length; ++i) {
    int tmp = s[i];
    s[i] = s[length - i - 1];
    s[length - i - 1] = tmp;
  }
}
