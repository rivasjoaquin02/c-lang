#include <stdio.h>

int sum(int a, int b);

int main(void) {

  int a, b;
  int f[10];

  scanf("%d %d", &a, &b);

  printf("%d", sum(a, b));

  return 0;
}

int sum(int a, int b) { return a + b; }
