#include <stdio.h>

int main(void) {
    printf("size..%d\n", sizeof(int (*[5])(double)));
    return 0;
}
