#ifndef SEARCH_BY_AUTHOR_H_INCLUDED
#define SEARCH_BY_AUTHOR_H_INCLUDED
//tea
void search_books_by_author(const char* filename, const char* Author)
{
    int found =0;
    FILE* fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Error: cannot open file %s\n", filename);
        return;
    }
    struct book b;
    while (fscanf(fp, "%s %s %d %d", b.title, b.author, &b.amount, &b.quantity) == 4)
    {
        if (strcmp(b.author, Author) == 0){
            printf("Book: %s\n", b.title);
            found = 1;
        }
    }
    if(found != 1){
        printf("the author you are looking for was not found\n");
    }
    fclose(fp);
}



#endif // SEARCH_BY_AUTHOR_H_INCLUDED


