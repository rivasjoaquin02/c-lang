#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 1000000

size_t binary_search(const size_t x, const size_t v[], const size_t n);
size_t binary_search_2(const size_t x, const size_t v[], const size_t n);

int main(void) {
    srand(time(NULL)); // use current time as seed

    size_t n, x;
    n = MAX;
    x = rand() / (RAND_MAX / (MAX) + 1);

    size_t *nums = malloc(n * sizeof(size_t));
    if (nums == NULL) {
        printf("Error: can't assign memory");
        return 1;
    }
    for (size_t i = 0; i < n; i++)
        nums[i] = i + 1;

    size_t pos = binary_search(x, nums, n);
    printf("%lu", pos);

    free(nums);

    return 0;
}

size_t binary_search(const size_t x, const size_t v[], const size_t n) {
    size_t low, high, mid;

    low = 0;
    high = n - 1;

    while (low <= high) {
        mid = (low + high) / 2;

        if (v[mid] == x)
            return mid;
        else if (v[mid] > x)
            high = mid - 1;
        else
            low = mid + 1;
    }

    return -1;
}

size_t binary_search_2(const size_t x, const size_t v[], const size_t n) {
    size_t low, high, mid;

    low = 0;
    high = n - 1;
    mid = (low + high) / 2;

    while (low <= high) {
        if (x < v[mid])
            high = mid - 1;
        else
            low = mid + 1;

        mid = (low + high) / 2;
    }

    return x == v[mid]
               ? mid
               : -1;
}