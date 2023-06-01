#ifndef SEARCH_BY_TITLE_H_INCLUDED
#define SEARCH_BY_TITLE_H_INCLUDED
//layan
int findBook(int NOB, struct book b[]){
    char findTitle[50];
    printf("enter the title of the book you want to find: ");
    scanf("%s", findTitle);
    for(int i=0; i<NOB; i++){
        if(strcmp(findTitle, b[i].title) == 0){
            return i;
        }
    }
    printf("the book was not found\n");
    return -1;
}
void print_book(int i, struct book b[]){
    if(i == -1){
        return;
    }
    printf("book title: %s\n", b[i].title);
    printf("Author: %s\n", b[i].author);
    printf("books available: %d\n", b[i].amount);
    printf("quantity: %d\n", b[i].quantity);
}
#endif // SEARCH_BY_TITLE_H_INCLUDED


