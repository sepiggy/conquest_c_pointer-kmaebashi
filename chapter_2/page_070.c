#include <stdio.h>

char *int_to_str(int int_value) {
    static char buf[20];
    sprintf(buf, "%d", int_value);
    return buf;
}

int main(void) {
    char *str1 = int_to_str(5);
    char *str2 = int_to_str(10);
    printf("str1..%s, str2..%s\n", str1, str2);
}
