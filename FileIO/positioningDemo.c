#include<stdio.h>
#include<stdlib.h>

int main(void){
    FILE* ptr = fopen("ResultFile.txt", "r");

    if(ptr == NULL){
        printf("File Not Present\n");
        return -1;
    }

    fseek(ptr, 0, SEEK_END);

    long int pos = ftell(ptr);

    fclose(ptr);
    ptr = NULL;

    printf("File Contains %ld bytes\n", pos);

    return 0;
}