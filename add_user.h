#ifndef ADD_USER_H_INCLUDED
#define ADD_USER_H_INCLUDED
//rosi
void addUser(struct person p[], int *numUsers) {
    // Ask for user information
    printf("Enter user name: ");
    scanf("%s", p[*numUsers].name);
    printf("Enter user surname: ");
    scanf("%s", p[*numUsers].surname);
    printf("Enter user phone number: ");
    scanf("%lf", &p[*numUsers].phone);
    printf("Enter user address: ");
    scanf("%s",p[*numUsers].address);
    printf("Enter user ID: ");
    scanf("%d", &p[*numUsers].ID);
    printf("Enter due date: ");
    scanf("%d", &p[*numUsers].dueDate);

    // Increment the number of users
    (*numUsers)++;

    // Write updated user list to file
    FILE *fp = fopen("user.txt", "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    for (int i = 0; i < *numUsers; i++) {
        fprintf(fp, "%s %s %lf %s %d %d\n", p[i].name, p[i].surname, p[i].phone, p[i].address, p[i].ID, p[i].dueDate);
    }

    fclose(fp);
    printf("User added successfully!\n");
}



#endif // ADD_USER_H_INCLUDED



