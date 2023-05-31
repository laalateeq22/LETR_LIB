#ifndef EDIT_BOOK_H_INCLUDED
#define EDIT_BOOK_H_INCLUDED
//rosi
void editBook(Book b[], int numBooks) {
    char name[50];
    int i;
    int choice;

    while (1) {
        printf("Enter the name of the book to edit (-1 to exit): ");
        scanf("%s", name);

        if (strcmp(name, "-1") == 0) {
            break;
        }

        // Search for the book by name
        for (i = 0; i < numBooks; i++) {
            if (strcmp(b[i].name, name) == 0) {
                printf("Book found!\n");
                printf("Select an option:\n");
                printf("1. Edit author name\n");
                printf("2. Edit amount\n");
                printf("3. Edit quantity\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);

                switch (choice) {
                    case 1:
                        printf("Enter new author name: ");
                        scanf("%s", b[i].author);
                        break;
                    case 2:
                        printf("Enter new amount: ");
                        scanf("%d", &b[i].amount);
                        break;
                    case 3:
                        printf("Enter new quantity: ");
                        scanf("%d", &b[i].quantity);
                        break;
                    default:
                        printf("Invalid option!\n");
                        break;
                }
                break;
            }
        }
        if (i == numBooks) {
            printf("Book not found!\n");
        }
    }

    // Open the file in read-write mode
    FILE *file = fopen("book.txt", "r+");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    // Overwrite the entire file with the updated book details
    for (i = 0; i < numBooks; i++) {
        fprintf(file, "%s %s %d %d\n", b[i].name, b[i].author, b[i].amount, b[i].quantity);
    }

    fclose(file);
    printf("Book details updated successfully!\n");
}




#endif // EDIT_BOOK_H_INCLUDED
