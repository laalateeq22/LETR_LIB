#ifndef UPCOMING_DUE_DATE_H_INCLUDED
#define UPCOMING_DUE_DATE_H_INCLUDED
//layan
void upcomingDueDate(struct person p[], struct book b[], int NOU,  int NOB){
    for(int i=0; i<NOU; i++){
        if(p[i].dueDate == 1)
            printf("%s %s %d %.0lf due tommorrow\n", p[i].name, p[i].surname, p[i].ID, p[i].phone);
        else if(p[i].dueDate == 0)
            printf("%s %s %d %.0lf due Today\n", p[i].name, p[i].surname, p[i].ID, p[i].phone);
        else if(p[i].dueDate < 4)
            printf("%s %s %d %.0lf due in: %d days\n", p[i].name, p[i].surname, p[i].ID, p[i].phone, p[i].dueDate);
    }
}
void getData(struct book b[], struct person p[], int NOU, int NOB){
    //name1 surname1 6666666666 address1 213 1 1 book1
    for(int i=0;i<NOU; i++){
        scanf("%s %s %lf %s %d %d %d", p[i].name, p[i].surname, &p[i].phone, p[i].address, &p[i].ID, &p[i].dueDate, &p[i].userBooks.numOfBooks);
        for(int j=0; j<p[i].userBooks.numOfBooks; j++){
            scanf(" %s", p[i].userBooks.BB[j].title);
        }
    }
    //book1 author1 1 2
    for(int i=0; i<NOB; i++){
        scanf("%s %s %d %d", b[i].title, b[i].author, &b[i].amount, &b[i].quantity);
    }
}



#endif // UPCOMING_DUE_DATE_H_INCLUDED
