#include <stdio.h>

int func(double d);

int main() {
    int (*func_p)(double);

    func_p = func;
    func_p(0.5);

    return 0;
}

int func(double d) {
    printf("d..%lf", d);
}
