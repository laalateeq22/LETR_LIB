#ifndef ADD_BOOK_H_INCLUDED
#define ADD_BOOK_H_INCLUDED
//era
int findBookIndex(struct book books[], int numBooks, char* title)
{
    for (int i = 0; i < numBooks; i++)
    {
        if (strcmp(books[i].title, title) == 0)
        {
            return i;  // Book found, return its index
        }
    }
    return -1;  // Book not found, return -1
}

void addBook(const char* filename,  struct book books[],char* inputTitle)
{
    FILE* fptr = fopen(filename, "a");
    if (fptr == NULL)
    {
        printf("Failed to open the file.\n");
        return;
    }
    char newAuthor[50];
    char newTitle[50];
    int newAmount;

    strcpy(newTitle,inputTitle);
    printf ("Enter the name of the author that wrote this book:\n");
    scanf("%s", newAuthor);
    printf ("How many copies of this book are you inserting in the library?\n");
    scanf("%d", &newAmount);
    fprintf(fptr, "\n");
    fprintf(fptr, "%s  %s %d %d", newTitle, newAuthor, newAmount,newAmount);
    fclose(fptr);
    printf("Book entered successfully in the library!\n");
    printf("Thank you!:)\n\n");
    printf ("-----------------------------------------------------\n");
}

void update_Book_Quantity(const char* filename, int bookIndex)
{
    FILE* fptr = fopen(filename, "r");
    if (fptr == NULL)
    {
        printf("Failed to open the file.\n");
        return;
    }
    // temporary file to store edited data
    FILE* tempFile = fopen("output.txt", "w");
    if (tempFile == NULL)
    {
        printf("Failed to create temporary file.\n");
        fclose(fptr);
        return;
    }
    int newAmount;
    printf("Enter the new quantity: ");
    scanf("%d", &newAmount);

    char line[150];
    int lineCount = 0;
    while (fgets(line, sizeof(line), fptr) != NULL)
    {
        char title[50];
        char author[50];
        int amount;
        int quantity;
        sscanf(line, "%s %s %d %d", title, author,&amount, &quantity);

        if (lineCount == bookIndex)
        {
            // Update the quantity of the book because it already exists in the file
            fprintf(tempFile,"%s    %s  %d  %d  \n", title, author,newAmount,quantity);
        }
        else
        {
            // Write the line as is to the temporary file
            fprintf(tempFile, "%s", line);
        }

        lineCount++;
    }

    fclose(fptr);
    fclose(tempFile);

    // Remove the original file
    remove(filename);
    // Rename the temporary file to the original filename
    rename("output.txt", filename);
}


void saveInArray(const char *filename, struct book books[], int numBooks)
{
//saving file elements in an array so it is easily accesible
    FILE* fptr = fopen(filename, "r");
    if (fptr == NULL)
    {
        printf("Failed to open file named \"book.txt\"!\n");
    }

    for (int i = 0; i < numBooks; i++)
    {
        fscanf(fptr, "%s %s %d %d", books[i].title, books[i].author, &books[i].amount, &books[i].quantity );
    }
    fclose(fptr);
}




#endif // ADD_BOOK_H_INCLUDED
