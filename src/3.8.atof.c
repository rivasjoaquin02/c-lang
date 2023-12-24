#include <ctype.h>
#include <math.h>
#include <stdio.h>
#define MAXLINE 1000

int get_line(char line[], int max);
double atof(char s[]);

int main(void) {

  char line[MAXLINE];

  while (get_line(line, MAXLINE) > 0) {
    printf("%.15g\n", atof(line));
  }

  return 0;
}

int get_line(char line[], int max) {
  int i, c;

  for (i = 0; (c = getchar()) != '\n' && c != EOF; ++i)
    line[i] = c;

  line[i] = '\0';

  return i;
}

double atof(char s[]) {
  if (s == NULL)
    return 0.0;

  double val, power;
  int i, sign;

  i = 0;
  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-')
    i++;

  for (val = 0.0; isdigit(s[i]); ++i)
    val = 10.0 * val + (s[i] - '0');

  if (s[i] == '.')
    i++;

  for (power = 1.0; isdigit(s[i]); ++i) {
    val = 10.0 * val + (s[i] - '0');
    power *= 10.0;
  }

  double exp = 0.0;
  int exp_sign = 1;
  if (s[i] == 'e' || s[i] == 'E') {
    i++;
    exp_sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '-' || s[i] == '+')
      i++;

    for (; isdigit(s[i]); ++i)
      exp = 10.0 * exp + (s[i] - '0');
  }

  double result = sign * val / power;
  if (exp != 0.0)
    result *= pow(10, exp_sign * exp);

  return result;
}
