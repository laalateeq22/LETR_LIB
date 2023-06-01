#ifndef SEARCH_BY_USER_H_INCLUDED
#define SEARCH_BY_USER_H_INCLUDED
//layan
int findUser(int NOU, struct person p[]){
    int option;
    int userI;
    printf("please specify the type of way you would like to search for the user:\n");
    printf("1. by name \n2. by surname \n3. by phone number \n4. by ID\n your choice:  ");
    scanf("%d", &option);
    if(option == 1){ //by name
        char userName[20];
        printf("enter the name of the user you want to find: ");
        scanf("%s", userName);
        for(int i=0; i<NOU; i++){
            if(strcmp(userName, p[i].name) == 0)
                userI = i;
        }
        if(userI == -1)
            printf("user was not found");
    }
    else if(option == 2){ //by surname
        char userSurname[20];
        printf("enter the surname of the user you want to find: ");
        scanf("%s", userSurname);
        for(int i=0; i<NOU; i++){
            if(strcmp(userSurname, p[i].surname) ==0)
                userI = i;
        }
        if(userI == -1)
            printf("user was not found");
    }
    else if(option == 3){ //by phone number
        double userPhone;
        printf("enter the phone number you want to find: ");
        scanf("%lf", &userPhone);
        for(int i=0; i<NOU; i++){
            if(userPhone == p[i].phone)
                userI = i;
        }
        if(userI == -1)
            printf("user was not found");
    }
    else if(option == 4){ //by ID
        int userID=-1;
        printf("enter the user ID you want to find: ");
        scanf("%d", &userID);
        for(int i=0; i<NOU; i++){
            if(userID == p[i].ID)
                userI = i;
        }
        if(userID == -1)
            printf("user was not found");
    }
    else
        printf("invalid option");
    return userI;

}
void print_user(int i, struct person p[]){
    printf("user name: %s\n", p[i].name);
    printf("surname: %s\n", p[i].surname);
    printf("phone: %.0lf\n", p[i].phone);
    printf("address: %s\n", p[i].address);
    printf("ID: %d \n", p[i].ID);
    if(p[i].numOfBooks == 0){
        printf("this user currently has no borrowed books\n");
    }
    else{
        printf("borrowed books:\n");
        for(int j=0; j<p[i].numOfBooks; j++){
            printf("book %d: %s\n", j+1, p[i].BB[j]);
        }
    }
}
int findUserWithUserID(int NOU, struct person p[]){
    int userID;
    printf("enter the user ID you want to find: ");
    scanf("%d", &userID);
    for(int i=0; i<NOU; i++){
        if(userID == p[i].ID)
            return i;
    }
    return -1;
}
#endif // SEARCH_BY_USER_H_INCLUDED


