#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define MAX_SIZE 1000

int stringLength(const char str[]);
bool stringEquals(const char str1[], const char str2[]);
void stringConcat(const char str1[], const char str2[], char str3[]);


int main(int argc, char *argv[]){
    printf("\t\t\tStrings\t\t\t\n");
    
    char str[MAX_SIZE];
    strcpy(str, argv[1]);
    char str2[MAX_SIZE];
    strcpy(str2, argv[2]);

    unsigned int len = stringLength(str);
    unsigned int len2 = stringLength(str2);

    printf("Length of %s -> %d\n", str, len);
    printf("Length of %s -> %d\n", str2, len2);

    printf("Are the 2 Strings Equal -> %d\n", stringEquals(str, str2));

    char str3[MAX_SIZE];
    stringConcat(str, str2, str3);

    printf("After concatenation -> %s\n", str3);
}

int stringLength(const char str[]){
    unsigned int len = 0;
    while(str[len++] != '\0'){}
    return len - 1;
}


bool stringEquals(const char str1[], const char str2[]){
    int i = 0;
    while(str1[i] != '\0' && str2[i] != '\0'){
        if(str1[i] != str2[i]) return false;
        i++;
    }
    return str1[i] == str2[i];
}


void stringConcat(const char str1[], const char str2[], char str3[]){
    int i = 0, j = 0;
    
    while(str1[i] != '\0'){
        str3[i] = str1[i];
        i++;
    }

    while(str2[j] != '\0'){
        str3[i++] = str2[j++];
    }

    str3[i] = '\0';
}