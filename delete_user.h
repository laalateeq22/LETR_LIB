void delete_user(const char* filename, const char* key, int search_type) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: cannot open file %s\n", filename);
        return;
    }

    char temp_filename[] = "temp.txt";
    FILE* temp_fp = fopen(temp_filename, "w");
    if (temp_fp == NULL) {
        printf("Error: cannot create temporary file.\n");
        fclose(fp);
        return;
    }

    char line[100];
    int found = 0;
    struct person deleted_user;

    while (fgets(line, sizeof(line), fp) != NULL) {
        struct person p;
        sscanf(line, "%s %s %lf %s %d %d %d %s", p.name, p.surname, &p.phone, p.address, &p.ID, &p.dueDate, p.BB);

        int match = 0;
        if (search_type == 1 && p.ID == atoi(key))
            match = 1;
        else if (search_type == 2 && strcmp(p.name, key) == 0)
            match = 1;
        else if (search_type == 3 && strcmp(p.surname, key) == 0)
            match = 1;
        else if (search_type == 4 && p.phone == atof(key))
            match = 1;

        if (match) {
            found = 1;
            deleted_user = p;
        } else {
            fputs(line, temp_fp);
        }
    }

    fclose(fp);
    fclose(temp_fp);

    if (found) {
        remove(filename);
        rename(temp_filename, filename);
        printf("User with name: %s, surname: %s, ID: %d, phone: %.0lf has been deleted.\n",
               deleted_user.name, deleted_user.surname, deleted_user.ID, deleted_user.phone);
    } else {
        remove(temp_filename);
        printf("User with %s not found in the file.\n", key);
    }
}
