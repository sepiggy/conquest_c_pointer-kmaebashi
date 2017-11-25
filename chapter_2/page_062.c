#include <stdio.h>

void func(void);

int main(void) {
    func();
    return 0;
}

void func(void) {
    char *str = "abc";

    printf("str..%s\n", str);
    str[0] = 'd';
}