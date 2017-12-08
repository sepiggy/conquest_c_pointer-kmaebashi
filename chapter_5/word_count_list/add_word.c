#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "word_manage_p.h"

static char *my_strdup(char *src) {
    char *dest;

    dest = malloc(sizeof(char) * (strlen(src) + 1));
    strcpy(dest, src);

    return dest;
}

static Word *create_word(char *name) {
    Word *new_word;

    new_word = malloc(sizeof(Word));

    new_word->name = my_strdup(name);
    new_word->count = 1;
    new_word->next = NULL;

    return new_word;
}

void add_word(char *word) {
    Word *pos;
    Word *prev;
    Word *new_word;
    int result;

    prev = NULL;
    for (pos = word_header; pos != NULL; pos = pos->next) {
        result = strcmp(pos->name, word);
        if (result >= 0)
            break;

        prev = pos;
    }


}
