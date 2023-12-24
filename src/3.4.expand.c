/*
* expand(s1, s2)
* expands shorthand notations like a-z in s1
* to equivalent abc...xyz in s2
* - [ ] Must allow lowercase-uppercase letters
* - [ ] Must allow digits
* - [ ] Must handle cases like a-b-c and a-z0-9 and -a-z
in: "a-c" out: "abc".
in: "a-z" out: "abcdefghijklmnopqrstuvwxyz".
in: "A-C" out: "ABC".
in: "0-2" out: "012".
in: "a-b-c" out: "abc".
in: "a-z0-9" out: "abcdefghijklmnopqrstuvwxyz0123456789".
in: "-a-z" out: "-abcdefghijklmnopqrstuvwxyz".
*/
#include <stdio.h>
#define END '\0'
#define MAX 100

void get_line(char line[], const int maxlength);
void expand(char s1[], char s2[]);

int main(void) {
  char s1[MAX];
  char s2[MAX];

  int t;
  scanf("%d ", &t);

  while (t--) {
    get_line(s1, MAX);
    expand(s1, s2);
    printf("%s\n", s2);
  }

  return 0;
}

void get_line(char line[], const int maxlength) {
  int i, c;

  for (i = 0; i < maxlength && (c = getchar()) != '\n' && c != EOF; ++i)
    line[i] = c;

  line[i] = END;
}

void expand(char s1[], char s2[]) {
  int i, j, c, lo, hi, lastc;

  i = 0;
  j = 0;
  lo = 0;
  hi = 0;
  lastc = 0;

  // corner case
  if (s1[i] == '-') {
    s2[j++] = '-';
    i++;
  }

  while (s1[i] != END) {
    c = s1[i];

    if (c != '-') {
      if (!lo) {
        lo = c;
      } else if (!hi)
        hi = c;
    }

    if (lo && hi) {
      for (int k = lo; k <= hi; ++k) {
        if (lastc == k)
          continue;
        s2[j++] = k;
        lastc = k;
      }
      lo = hi;
      hi = 0;
    }
    i++;
  }
  s2[j] = END;
}
