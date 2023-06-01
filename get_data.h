#ifndef GET_DATA_H_INCLUDED
#define GET_DATA_H_INCLUDED
void readDataFromFile(FILE* file, struct person* p, int* numPeople)
{
    while (*numPeople < 150 && fscanf(file, "%s %s %lf %s %d %d",
                                            p[*numPeople].name, p[*numPeople].surname, &(p[*numPeople].phone),
                                            p[*numPeople].address, &(p[*numPeople].ID), &(p[*numPeople].dueDate)) == 6)
    {
        fscanf(file, "%d", &p[*numPeople].numOfBooks);
        for(int i=0; i<p[*numPeople].numOfBooks; i++){
            fscanf(file, "%s", p[*numPeople].BB[i]);
        }
        (*numPeople)++;
    }

}
void readBookDataFromFile(FILE* file, struct book* p, int* numBooks)
{
    while (*numBooks < 300 && fscanf(file, "%s %s %d %d",
                                           p[*numBooks].title, p[*numBooks].author, &(p[*numBooks].amount), &(p[*numBooks].quantity)) == 4)
    {
        (*numBooks)++;
    }
}



#endif // GET_DATA_H_INCLUDED


