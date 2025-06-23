#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

int main(){
    //malloc & realloc example    
    // char *str = NULL;

    // str = (char*) malloc(7*sizeof(char));
    // strcpy(str, "Rishit");

    // char* ptr = str;

    // printf("String = > %s\t\tAddress => %p\n\n", str, str);
    
    // while(*ptr){
    //     printf("Character => %c\n", *ptr);
    //     ptr++;
    // }

    // str = (char*) realloc(str, 14*sizeof(char));

    // strcat(str, " Gupta");

    // printf("Update String => %s\tAddress => %p\n\n", str, str);

    // ptr = str;
    // while(*ptr){
    //     printf("Character => %c\n", *ptr);
    //     ptr++; 
    // }

    // free(str);

    int size;
    printf("Enter Size of String: ");
    scanf("%d",&size);
    getchar();
    
    char* ptr = malloc(size * sizeof(char));

    if(ptr != NULL){
        printf("Enter String: ");
        fgets(ptr, size, stdin);
    }
    printf("String entered by User => %s\n", ptr);

    free(ptr);
    ptr = NULL;
    return 0;
    
}