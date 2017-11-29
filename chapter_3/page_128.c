#include <stdio.h>
#define COLOR_NUM (sizeof(color_name) / sizeof(char*))

int main(void) {
    char *color_name[] = {
            "black",
            "blue",
            "red",
            "yello",
            "green",
            "white",
            "orange",
            "gray"
    };

    for (int i = 0; i < COLOR_NUM; ++i) {
        puts(color_name[i]);
    }

    printf("%d\n", sizeof color_name);
    printf("%d\n", sizeof(char*));
    return 0;
}
