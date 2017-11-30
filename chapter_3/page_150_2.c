#include <stdio.h>

int main(void) {
    char str[] = "abc";
    str[0] = 'd';
    printf("%s", str);

    char *str1 = "abc";
//    str1[0] = 'd'; // ERROR?
//    printf("%s", str1);
    return 0;
}
