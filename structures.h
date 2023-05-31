#ifndef STRUCTURES_H_INCLUDED
#define STRUCTURES_H_INCLUDED
struct book{
    char title[50];
    char author [20];
    int amount; //number of books available
    int quantity;
};
struct borrowedBook{
    int numOfBooks;
    struct book BB[5];
};
struct person{
    char name[20];
    char surname[20];
    double phone;
    char address[20];
    int ID;
    int dueDate;
    struct borrowedBook userBooks;
};

#endif // STRUCTURES_H_INCLUDED
