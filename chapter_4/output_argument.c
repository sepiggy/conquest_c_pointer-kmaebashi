#include <stdio.h>

void func(int *, double *);

int main(void) {
    int a;
    double b;

    func(&a, &b);
    printf("a..%d b..%f\n", a, b);

    return 0;
}

void func(int *a, double *b) {
    *a = 5;
    *b = 3.5;
}
