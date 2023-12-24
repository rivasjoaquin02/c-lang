#include "calc.h"
#include <math.h>

double calculate(const double x, const double y, const int op) {
    switch (op) {
    case ADD:
        return x + y;
    case SUB:
        return x - y;
    case MUL:
        return x * y;
    case DIV:
        return x / y;
    case RES:
        return fmod(x, y);
    default:
        return 0.0;
    }
}
