#include <stdio.h>

int main(void) {
    char *color_name1[] = {
            "red",
            "green",
            "blue",
    };

    char color_name2[][6] = {
            "red",
            "green",
            "blue",
    };

    printf("color_name1 size...%d", sizeof(color_name1));
    printf("\n");
    printf("color_name2 size...%d", sizeof(color_name2));

    return 0;
}
