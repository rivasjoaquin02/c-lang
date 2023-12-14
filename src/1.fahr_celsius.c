#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20
/* print Fahrenheit−Celsius table
 for fahr = 0, 20, ..., 300 */

main () {
    float fahr, celsius;

    fahr = LOWER;
    while (fahr <= UPPER) {
        celsius = (5.0/9.0) * (fahr - 32.0);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + STEP;
    }
}