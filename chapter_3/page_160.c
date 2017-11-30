#include <stdio.h>

int main(void) {
    char *color_name1[]={
            "red",
            "green",
            "blue",
    };

    char c1 = color_name1[1][2];
    printf("%c", c1);

    char color_name2[][6] = {
            "red",
            "green",
            "blue",
    };
    char c2 = color_name2[1][2];
    printf("%c", c2);
    return 0;
}
