#ifndef STRUCTURES_H_INCLUDED
#define STRUCTURES_H_INCLUDED
struct book{
    char title[50];
    char author [20];
    int amount; //number of books available
    int quantity;
};

struct person{
    char name[20];
    char surname[20];
    double phone;
    char address[20];
    int ID;
    int dueDate;
    int numOfBooks;
    char BB[5][50];
};

#endif // STRUCTURES_H_INCLUDED
