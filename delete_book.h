#ifndef DELETE_BOOK_H_INCLUDED
#define DELETE_BOOK_H_INCLUDED
//Era
void delete_by_author(const char *filename, char *authorToDelete)
{
    FILE *fptr;
    FILE *tempFile;
    char line[100];
    fptr = fopen(filename, "r");
    if (fptr == NULL)
    {
        perror("Error opening the file! Try again!\n");
        return;
    }
    tempFile = fopen("temp.txt", "w");
    // Read the original file line by line
    while (fgets(line, sizeof(line), fptr) != NULL)
    {
        if (strstr(line, authorToDelete) == NULL)
        {
            fputs(line, tempFile);
        }

    }

    // Close both files
    fclose(fptr);
    fclose(tempFile);

    // Delete the original file
    if (remove(filename) != 0)
    {
        perror("Error deleting the original file!\n");
        return;
    }
    // Rename the temporary file to the original file name
    if (rename("temp.txt", filename) != 0)
    {
        perror("Error renaming the temporary file!\n");
        return;
    }
    printf("Book written by:'%s' deleted successfully.\n", authorToDelete);
}

void delete_by_title(const char *filename, const char *titleToDelete)
{
    FILE *fptr;
    FILE *tempFile;
    char line[100];
    fptr = fopen(filename, "r");
    if (fptr == NULL)
    {
        perror("Error opening the file");
        return;
    }
    tempFile = fopen("temp.txt", "w");
    // Read the original file line by line
    while (fgets(line, sizeof(line), fptr) != NULL)
    {
        if (strstr(line, titleToDelete) == NULL)
        {
           fputs(line, tempFile);
        }
    }
    // Close both files
    fclose(fptr);
    fclose(tempFile);

    // Delete the original file
    if (remove(filename) != 0)
    {
        perror("Error deleting the original file");
        return;
    }
    // Rename the temporary file to the original file name
    if (rename("temp.txt", filename) != 0)
    {
        perror("Error renaming the temporary file");
        return;
    }

    printf("Book named '%s' deleted successfully.\n", titleToDelete);
}




#endif // DELETE_BOOK_H_INCLUDED

