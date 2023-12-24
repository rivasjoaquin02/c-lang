#define NUMBER '0'

enum OP {
    ADD = '+',
    SUB = '-',
    MUL = '*',
    DIV = '/',
    RES = '%',
};

void push(const double f);
double pop(void);

int getop(char s[]);
double calculate(const double x, const double y, const int op);
