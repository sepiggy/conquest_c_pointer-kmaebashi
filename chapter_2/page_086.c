#include <stdio.h>
#include <stdlib.h>

typedef struct BookData_tag {
    char *title;
    int price;
    char *isbn;
    struct BookData_tag *next;
} BookData;

int main(void) {
    BookData *book_data_p;

    book_data_p = malloc(sizeof(BookData));

    book_data_p->title = malloc(sizeof(char) * 4);
    book_data_p->price = 35;
    book_data_p->isbn = "12345678";
    book_data_p->title = "xyj";

    printf("%s\t", book_data_p->title);
    printf("%d\t", book_data_p->price);
    printf("%s", book_data_p->isbn);

    return 0;
}