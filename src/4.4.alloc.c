#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n) {
    // end - where is
    if (allocbuf + ALLOCSIZE - allocp >= n) {
        allocp += n;
        return allocp - n;
    }

    // theres no space (0 is not a valid mem addres in C)
    // 0 is the only int that can be assingned to a pointer
    // and a pointer can be compared with 0
    return 0; //null can be used as well
}

void afree(char *p) {
    // p is in the range [allocbuf ... allocbuf + ALLOCSIZE]
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE) allocp = p;
}
