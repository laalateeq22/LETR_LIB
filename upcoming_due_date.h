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



#endif // UPCOMING_DUE_DATE_H_INCLUDED


