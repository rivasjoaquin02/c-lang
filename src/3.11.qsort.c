
/* qsort: sort v[left] ... v[right] into increasing order */
void qsort(int v[], int left, int right) {}

int main(void) { return 0; }

/* 
 * 0 1 2 3 4 5  6 7 8 9
 * 4 3 1 4 5 76 4 2 1 123 
 * l                  r
 * swap l -> (l + r) /2
 * 5       4
 *   l+1 ...          r
 * swap last -> if v[i] < v[left]
