// p173
// 从标准输入读取文本文件的内容，并且将其用于标准输出

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define ALLOC_SIZE (256)

#include "read_line.h"

char **add_line(char **, char *, int *, int *);

char **read_file(FILE *, int *);

int main(void) {
    char **text_data;
    int line_num;

    text_data = read_file(stdin, &line_num);
    for (int i = 0; i < line_num; ++i) {
        printf("%s\n", text_data[i]);
    }

    return 0;
}

char **add_line(char **text_data, char *line, int *line_alloc_num, int *line_num) {
    assert(*line_alloc_num >= *line_num);

    if (*line_alloc_num == *line_num) {
        text_data = realloc(text_data, (*line_alloc_num + ALLOC_SIZE) * sizeof(char *));
        *line_alloc_num += ALLOC_SIZE;
    }
    text_data[*line_num] = line;
    (*line_num)++;

    return text_data;
}

char **read_file(FILE *fp, int *line_num_p) {
    char **text_data = NULL;
    int line_num = 0;
    int line_alloc_num = 0;
    char *line;

    while ((line = read_line(fp)) != NULL) {
        text_data = add_line(text_data, line, &line_alloc_num, &line_num);
    }

    /* 将 text_data 缩小到实际需要的大小 */
    text_data = realloc(text_data, line_num * sizeof(char *));
    *line_num_p = line_num;

    return text_data;
}