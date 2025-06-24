#include<stdio.h>
#include<stdlib.h>

int main(void){
    char *filename = "daydate.txt";
    FILE *pfile = NULL;

    pfile = fopen(filename, "r");

    if(pfile == NULL){
        printf("%s doesn't exists\n", filename);
        return -1;
    }

    char day[9];
    int date;
    char month[5];
    int year;

    fscanf(pfile, "%s %d %s %d", day, &date, month, &year);

    printf("Today DayDate: %s,%d/%s/%d\n", day, date, month, year);

    return 0;
}