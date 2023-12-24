#include <stdio.h>
#define MAX 1000
#define END '\0'

void get_line(char s[]);
void escape(char s[], char t[]);

int main(void) {
  char s[MAX];
  char t[MAX];

  get_line(t);
  escape(s, t);

  printf("%s", s);

  return 0;
}

void get_line(char s[]) {
  int i, c;

  i = 0;
  while ((c = getchar()) != EOF) {
    s[i++] = c;
  }

  s[i] = END;
}

void escape(char s[], char t[]) {
  int i, j, c;

  for (i = j = 0; t[i] != END; ++i) {
    c = t[i];
    switch (c) {
    case '\n':
      s[j++] = '\\';
      s[j] = 'n';
      break;
    case '\t':
      s[j++] = '\\';
      s[j] = 't';
      break;
    default:
      s[j] = c;
      break;
    }
    j++;
  }
  s[j] = END;
}
