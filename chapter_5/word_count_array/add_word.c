#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "word_manage_p.h"

static void shift_array(int index) {
    for (int src = num_of_word - 1; src >= index; src--) {
        word_array[src + 1] = word_array[src];
    }
    num_of_word++;
}

/*
 * 复制字符串
 */
static char *my_strdup(char *src) {
    char *dest;

    dest = malloc(sizeof(char) * (strlen(src) + 1));
    strcpy(dest, src);

    return dest;
}

/*
 * 追加单词
 */
void add_word(char *word) {
    int i, rst;

    for (i = 0; i < num_of_word; i++) {
        rst = strcmp(word_array[i].name, word);
        if (rst >= 0)
            break;
    }

    if (num_of_word != 0 && rst == 0) {
        word_array[i].count++;
    } else {
        shift_array(i);
        word_array[i].name = my_strdup(word);
        word_array[i].count = 1;
    }
}
