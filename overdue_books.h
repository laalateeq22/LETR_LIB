#ifndef OVERDUE_BOOKS_H_INCLUDED
#define OVERDUE_BOOKS_H_INCLUDED
//tea
void print_due_date(const char* filename)
{
    FILE* fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Error: cannot open file %s\n", filename);
        return;
    }

    struct person p;
    while (fscanf(fp, "%s %s %lf %s %d %d", p.name, p.surname, &p.phone, p.address, &p.ID, &p.dueDate) == 6){
        if (p.dueDate==0)
            printf("The user with name %s ,surname %s , ID %d and address %s has a book overdue \n", p.name, p.surname, p.ID,p.address);
    }

    fclose(fp);
}
#endif // OVERDUE_BOOKS_H_INCLUDED


