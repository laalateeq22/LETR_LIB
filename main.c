//Libraries//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"
#include "get_data.h"
#include "search_by_user.h"
#include "search_by_title.h"
#include "search_by_author.h"
#include "upcoming_due_date.h"
#include "overdue_books.h"
#include "edit_book.h"
#include "edit_by_user.h"
#include "delete_book.h"
#include "delete_user.h"
#include "add_book.h"
#include "add_user.h"
#include "option.h"
//global Definition//
#define MAX_PEOPLE 150
#define MAX_BOOKS 300
///teas file name for search by author
int main()
{
    //DESIGN//
    int option =1, n;
    char pass[20];
    printf("\n\t###########################################################################");
    printf("\n\t############                                                   ############");
    printf("\n\t############        Library Management System Project          ############");
    printf("\n\t############                                                   ############");
    printf("\n\t###########################################################################");
    printf("\n\t---------------------------------------------------------------------------\n");
    printf("\n\t----------------------------------------------------------------------------");
    printf("\n");
    printf("\n\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t        =                 WELCOME TO                =");
    printf("\n\t        =          LIBRARY MANAGEMENT SYSTEM        =");
    printf("\n\t        =                                           =");
    printf("\n\t        =                 \"LETR LIB\"!               =");
    printf("\n\t        =                                           =");
    printf("\n\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("Hello! Welcome to \"LETR LIB\"!\n");
    printf("---------------------------------------------------------------------------------------------------------\n");
    printf("We are a local library which currently holds 100 books and has the capacity to store 300 books in total.\n");
    printf("We have around 75 different users, and if you would like to join our loving community we are open to applications. <3\n\n");
    //DECLARING & GETTING THE DATA//
    struct person p[MAX_PEOPLE];
    struct book b[MAX_BOOKS];
    int numPeople = 0;
    int numBooks = 0;
    FILE *libBook;
    FILE *libUser;
    libBook=fopen("book.txt", "r");///file name
    libUser=fopen("user.txt", "r");///file name
    if (libUser==NULL){
        printf("Failed to open file consisting user properties");
        exit(1);
    }
     if (libBook==NULL){
        printf("Failed to open file consisting book properties");
        exit(1);
    }
    readDataFromFile(libUser, p, &numPeople);
    readBookDataFromFile(libBook, b, &numBooks);
    int NOB = numBooks, NOU = numPeople;
    //PERFORMING THE TASKS//
    printf("\
Enter\n\
1. if you are a user\n\
2. if you are library manager.\n\
3. if you are member\n\
enter your option: ");
    scanf("%d", &option);
    printf("\n---------------\n");
    if(option == 1){//by user:
        int n;
        while(1){
            printf("What would you like to search?\n");
            printf("\
1. Search for the book by title\n\
2. search for the books by the author \n\
-1. to exit\n\
enter your option: ");
            scanf("%d", &n);
            printf("\n---------------\n");
            if (n == 1){//Layan_Title
                int i = findBook(NOB, b);
                if(i != -1)
                    print_book(i, b);
            }
            else if (n == 2){//search for the book by author Tea
                char Author[20];
                printf("enter the name of the author: ");
                scanf("%s", Author);
                search_books_by_author("book.txt", Author); ///change the name of the file name
            }
            else if(n == -1)
                break;
            else
                printf("this is not an option in the menu\n");
            printf("\nTask completed!\n");
            printf("---------------------------------------------------------------------------------------------------------\n");
        }
    }
    else if (option == 2){//by manager:
        int cnt = 0;
        while(cnt < 3){//for the password options
            printf("Enter the password to access the Library Management System: ");
            scanf("%s", pass);
            if(strcmp(pass, "cuteKoala") == 0){
                printf("\
1. Search for the book data by title\n\
2. search for the books by author \n\
3. search the users \n\
4. edit a user\n\
5. edit a book\n\
6. add a book\n\
7. add a user\n\
8. delete a user\n\
9. delete a book\n\
10. find the overdue books\n\
11. find the upcoming due date\n\
-1. exit the menu\n");
                printf("enter the task you want to perform: ");
                scanf("%d", &n);
                printf("\n---------------\n");

                if(n == 1){//LAYANS SEARCH BY TITLE
                    int i = findBook(NOB, b);
                    print_book(i, b);
                }
                else if(n == 2){//TEAS SEARCH BY AUTHOR
                    char Author[20];
                    printf("enter the name of the author: ");
                    scanf("%s", Author);
                    search_books_by_author("book.txt", Author); ///change the name of the file name
                }
                else if(n == 3){//LAYAN SEARCH BY USER
                    int userID = findUser(NOU, p);
                    if(userID != -1)
                        print_user(userID, p);
                }
                else if(n == 4){//LAYAN EDIT USER
                    editUser(p, b,NOU, NOB);
                }
                else if(n == 5){//ROSIS EDIT BOOK
                    editBook(b, NOB);
                }
                else if(n == 6){//ERAS ADD BOOKS
                    const char *filename = "book.txt";/// file name here
                    add_Books(filename);
                }
                else if(n == 7){//ROSIS ADD USERS
                    addUser(p, &NOU);
                                        }
                else if(n == 8){//TEAS DELETE USER
                    char filename[] = "user.txt";
                    int search_type;
                    char key[20];
                    printf("Enter search type (1 for ID, 2 for name, 3 for surname, 4 for phone): ");
                    scanf("%d", &search_type);
                    printf("Enter search key: ");
                    scanf("%s", key);
                    delete_user(filename, key, search_type);

                }
                else if(n == 9){//ERAS DELETE BOOKS
                    const char *filename = "book.txt";
                    char authorToDelete[50];
                    char titleToDelete[50];
                    int num, nrOfBooksToBeDeleted, nrOfAuthorsToDelete;
                    printf ("Do you want to delete a book by:\n1-Delete by Title\n2-Delete by Author\n");
                    scanf("%d", &num);
                    if (num==1)
                    {
                        printf("How many books do you want to delete?\n");
                        scanf("%d", &nrOfBooksToBeDeleted);
                        for(int i=0; i<nrOfBooksToBeDeleted; i++)
                        {
                            printf("Which book do you want to delete?\n");
                            scanf ("%s", titleToDelete);
                            delete_by_title("book.txt",titleToDelete);
                        }
                    }
                    else if (num==2)
                    {
                        printf("How many authors do you want to delete?\n");
                        scanf("%d", &nrOfAuthorsToDelete);
                        for(int i=0; i<nrOfAuthorsToDelete; i++)
                        {
                            printf("Books of which author do you want to delete?\n");
                            scanf ("%s", authorToDelete);
                            delete_by_author(filename, authorToDelete);
                        }
                    }

                    else if (num==2){
                        int nrOfAuthorsToDelete;
                        char authorToDelete[20];
                        printf("How many authors do you want to delete?\n");
                        scanf("%d", &nrOfAuthorsToDelete);
                        for(int i=0; i<nrOfAuthorsToDelete; i++){
                            printf("Books of which author do you want to delete?\n");
                            scanf ("%s", authorToDelete);
                            delete_by_author("book.txt", authorToDelete);
                        }
                    }
                    else{
                        printf("You entered an invalid number. Try again! :)\n");
                    }
                }

                else if(n == 10){//TEAS OVERDUE DATE
                    print_due_date("user.txt");///change the file name

                }
                else if(n == 11){//LAYANS UPCOMING DATE
                    upcomingDueDate(p, b, NOU, NOB);
                }
                else if(n == -1){
                    break;
                }
                else{
                    printf("You entered an invalid number. Try again! :)\n");
                }
                printf("\nTask completed!\n");
                printf("---------------------------------------------------------------------------------------------------------\n");
            }
            else{
                cnt++;
                if(cnt <3){
                    printf("you have entered the incorrect password \nyou have %d chances left\n", 3-cnt);
                }
                else{
                    int n;
                    printf("\n---------------\n");
                    printf("you have exceeded the number of incorrect passwords.\nyou are currently in the user mode\n");
                    printf("\n---------------\n");
                    while(1){
                        printf("What would you like to search?\n");
                        printf("\
1. Search for the book by title\n\
2. search for the books by the author \n\
-1. to exit\n\
enter your option: ");
                        scanf("%d", &n);
                        printf("\n---------------\n");
                        if (n == 1){//Layan_Title
                            int i = findBook(NOB, b);
                            if(i != -1)
                                print_book(i, b);
                        }
                        else if (n == 2){//search for the book by author Tea
                            char Author[20];
                            printf("enter the name of the author: ");
                            scanf("%s", Author);
                            search_books_by_author("book.txt", Author); ///change the name of the file name
                        }
                        else if (n == -1)
                            break;
                        else
                            printf("this is not an option in the menu\n");
                        printf("\nTask completed!\n");
                        printf("---------------------------------------------------------------------------------------------------------\n");
                    }
                }
            }
        }
        if(cnt == 4){
            int n;
            while(1){
                printf("What would you like to search?\n");
                printf("1. Search for the book by: title\n\
                       2. search for the books by the author \n\
                       enter \"-1\" to exit");
                scanf("%d", &n);

                if (n == 1){//Layan_Title
                    int i = findBook(NOB, b);
                    print_book(i, b);
                }
                else if (n == 2){//search for the book by author Tea
                    char Author[20];
                    printf("enter the author: ");
                    scanf("%s", Author);
                    search_books_by_author("book.txt", Author); ///change the name of the file name
                }
                else if(n == -1)
                    break;
                else
                    printf("this is not an option in the menu\n");
            }
        }
    }
    else if(option == 3){//by member:
        int cnt = 0, userID, found=-1;
        while(cnt != 4){
            printf("enter your user ID: ");
            scanf("%d", &userID);
            int userI = found = findUserWithUserID(userID, NOU, p); ///add function here
            if(found == -1){
                cnt++;
                printf("this user ID does not exist\n\
                       you have %d chances left\n", 3-cnt);
            }
            else{
                printf("\
            what would you like to perform\n\
            1. view your account details\n\
            2. edit your data\n\
            3. search for books by author\n\
            4. search for book by title\n");
                int x;
                scanf("%d", &x);
                while(1){
                    if(x == -1)//exit the menu
                        break;
                    else if(x == 1){//see their data
                        print_user(userI, p);
                        break;
                    }
                    else if(x == 2){//edit their data
                        editUserID(p, b, NOU, NOB, userI);
                    }
                    else if(x == 3){//search for the book by author
                        char Author[20];
                        printf("enter the author: ");
                        scanf("%s", Author);
                        search_books_by_author("book.txt", Author); ///change the file name
                    }
                    else if(x == 4){//search book by title
                        int i = findBook(NOB, b);
                        print_book(i, b);
                    }
                    else
                        printf("ERROR: invalid option");

                }
            }
        }
    }
    else{//if another option is entered:
        printf("this is not an option");
    }

    //CLOSING THE FILES//
    fclose(libBook);
    fclose(libUser);
    //END MESSAGE TO USER//
    printf("thank you for you daily dosage of knowledge. \nhave a great day, \nhope to see you here again soon!");
    return 0;
}
