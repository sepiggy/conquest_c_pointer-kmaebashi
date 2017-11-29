#include <printf.h>

int main(void) {
    char str[256] = "hello, world";
    printf(str);
    puts("");
    puts(str);
    printf("%c\n", "01234567890ABCDEF"[10]);
    printf("%c\n", str[7]);

    return 0;
}
