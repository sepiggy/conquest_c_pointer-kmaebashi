#include <stdio.h>

int main(void) {
    int array[3] = {1, 2, 3};
    int (*array_p)[3];

    array_p = &array;

    printf("%d", sizeof(*array_p));
    printf("\n");
    printf("%d", sizeof(*array));

    return 0;
}
