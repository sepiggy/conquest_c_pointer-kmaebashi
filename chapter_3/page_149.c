#include <stdio.h>

int main(void) {
//    char str[] = "abc"; // OK

//    char str[] = {'a', 'b', 'c', '\0'}; // OK

//    char str[4]; // ERROR
//    str = "abc";

    char *str = "abc"; // OK
    printf("%s\n", str);

    printf("size..%d\n", sizeof("abcdefghijklmnopqrstuvwxyz"));

    return 0;
}
