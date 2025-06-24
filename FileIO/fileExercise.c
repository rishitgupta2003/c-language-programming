#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int main(void){
    FILE* tempFile = NULL;
    FILE* ptr = NULL;
    int c;

    tempFile = fopen("ResultFile.txt", "w");
    ptr = fopen("textWrite.txt", "r");

    if(tempFile == NULL){
        printf("File are not present\n");
        return -1;
    }

    while((c = fgetc(ptr)) != EOF){
        if(islower(c)){
            c = c - 32;
        }
        fputc(c, tempFile);
    }

    fclose(tempFile);
    fclose(ptr);

    remove("textWrite.txt");

    return 0;


}