#ifndef EDIT_BY_USER_H_INCLUDED
#define EDIT_BY_USER_H_INCLUDED
//layan
void update_data(int NOU, struct person p[]){
    FILE *fp = fopen("user.txt", "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    for (int i = 0; i < NOU; i++) {
        fprintf(fp, "%s %s %lf %s %d %d\n", p[i].name, p[i].surname, p[i].phone, p[i].address, p[i].ID, p[i].dueDate);
        fprintf(fp, "%d", p[i].userBooks.numOfBooks);
        for(int j=0; j<p[i].userBooks.numOfBooks; j++){
            printf(fp, "%s", p[i].userBooks.BB[j].title);
        }
    }

    fclose(fp);
}
void editUser(struct person p[], struct book b[], int NOU,  int NOB){
    int option;
    int userI = findUser(NOU, p); //create function here
    while(userI == -1){
        userI = findUser(NOU, p); //create function here
    }
    printf("please choose what you would like to edit:\n");
    printf("1. name \n2. surname \n3. phone number \n4. address \n5. ID \n6. has the user returned a book? \n7. does the user want to borrow a book?\n");\
    scanf("%d", &option);
    int newID;         int bookI;
        if(option == 1){//by name
            char newName[20];
            printf("enter the new name:  ");
            scanf("%s", newName);
            strcpy(p[userI].name, newName);
        }
        else if(option == 2){ //by surname
            char newSurname[20];
            printf("enter the new Surname:  ");
            scanf("%s", newSurname);
            strcpy(p[userI].surname, newSurname);
        }
        else if(option == 3){ //by number
            double newPhone;
            printf("enter the new number:  ");
            scanf("%lf", &newPhone);
            p[userI].phone = newPhone;
        }
        else if(option == 4){ //by address
            char newAddress[20];
            printf("enter the new address:  ");
            scanf("%s", newAddress);
            strcpy(p[userI].address, newAddress);
        }
        else if(option == 5){ //by ID
            printf("enter new ID:  ");
            scanf("%d", &newID);
            p[userI].ID = newID;
        }
        else if(option == 6){ //returning book
            int lastElement;    char bookReturn[50];
            if(p[userI].userBooks.numOfBooks == 0){//checks if he has not borrowed any books
                printf("the selected user has not borrowed any books previously\n");
            }
            else{
                printf("enter the book the user is returning:  ");
                scanf("%s", bookReturn);
                int found=0;
                for(int i=0; i<p[userI].userBooks.numOfBooks; i++){
                    if(strcmp(bookReturn, p[userI].userBooks.BB[i].title) == 0){
                        lastElement = p[userI].userBooks.numOfBooks - 1;
                        p[userI].userBooks.BB[i]= p[userI].userBooks.BB[lastElement];
                        p[userI].userBooks.numOfBooks--; //changing the number of books borrowed
                        found = 1;
                        break;
                    }
                }
                if(found == 0)
                    printf("this user has not borrowed this book\n");
            }
        }
        else if(option == 7){ //borrowing book
            if(p[userI].userBooks.numOfBooks == 5){
                printf("the user can no longer borrow any other books since they have reached the limits\n");
            }
            else{
                bookI = findBook(NOB, b); //create the function to find the book
                while(bookI ==-1){
                    bookI = findBook(NOB, b); //create the function to find the book
                }
                b[bookI].amount--; //decreasing the books in the file
                p[userI].userBooks.BB[p[userI].userBooks.numOfBooks] = b[bookI]; //adding the book details for the user
                p[userI].userBooks.numOfBooks++; //increasing the number of books the user borrowed
            }
        }
        else
            printf("invalid option");
        update_data(NOU, p);

}

void editUserID(struct person p[], struct book b[], int NOU, int NOB, int userI){
    while(userI == -1){
        printf("please choose what you would like to edit:\n");
        printf("1. name \n2. surname \n3. phone number \n4. address \n5. ID \n6. has the user returned a book? \n7. does the user want to borrow a book?\n");\
        int option;
        scanf("%d", &option);
        int newID;         int bookI;
        if(option == 1){//by name
            char newName[20];
            printf("enter the new name:  ");
            scanf("%s", newName);
            strcpy(p[userI].name, newName);
        }
        else if(option == 2){ //by surname
            char newSurname[20];
            printf("enter the new Surname:  ");
            scanf("%s", newSurname);
            strcpy(p[userI].surname, newSurname);
        }
        else if(option == 3){ //by number
            double newPhone;
            printf("enter the new number:  ");
            scanf("%lf", &newPhone);
            p[userI].phone = newPhone;
        }
        else if(option == 4){ //by address
            char newAddress[20];
            printf("enter the new address:  ");
            scanf("%s", newAddress);
            strcpy(p[userI].address, newAddress);
        }
        else if(option == 5){ //by ID
            printf("enter new ID:  ");
            scanf("%d", &newID);
            p[userI].ID = newID;
        }
        else if(option == 6){ //returning book
            int lastElement;    char bookReturn[50];
            if(p[userI].userBooks.numOfBooks == 0){//checks if he has not borrowed any books
                printf("the selected user has not borrowed any books previously\n");
            }
            else{
                printf("enter the book the user is returning:  ");
                scanf("%s", bookReturn);
                int found=0;
                for(int i=0; i<p[userI].userBooks.numOfBooks; i++){
                    if(strcmp(bookReturn, p[userI].userBooks.BB[i].title) == 0){
                        lastElement = p[userI].userBooks.numOfBooks - 1;
                        p[userI].userBooks.BB[i]= p[userI].userBooks.BB[lastElement];
                        p[userI].userBooks.numOfBooks--; //changing the number of books borrowed
                        found = 1;
                        break;
                    }
                }
                if(found == 0)
                    printf("this user has not borrowed this book\n");
            }
        }
        else if(option == 7){ //borrowing book
            if(p[userI].userBooks.numOfBooks == 5){
                printf("the user can no longer borrow any other books since they have reached the limits\n");
            }
            else{
                bookI = findBook(NOB, b); //create the function to find the book
                while(bookI ==-1){
                    bookI = findBook(NOB, b); //create the function to find the book
                }
                b[bookI].amount--; //decreasing the books in the file
                p[userI].userBooks.BB[p[userI].userBooks.numOfBooks] = b[bookI]; //adding the book details for the user
                p[userI].userBooks.numOfBooks++; //increasing the number of books the user borrowed
            }
        }
        else
            printf("invalid option");
    }
}


#endif // EDIT_BY_USER_H_INCLUDED
