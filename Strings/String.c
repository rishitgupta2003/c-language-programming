#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define MAX_SIZE 1000

int stringLength(const char str[]);
bool stringEquals(const char str1[], const char str2[]);
void stringConcat(const char str1[], const char str2[], char str3[]);
void stringReverse(const char str[], char result[]);
void sortStrings(char arr[][MAX_SIZE], int size);

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

    char toRev[MAX_SIZE];
    char result[MAX_SIZE];

    printf("Enter String to reverse -> ");
    scanf("%s", toRev);
    stringReverse(toRev, result);

    printf("Orignal String -> %s\nReversed String -> %s\n", toRev, result);
    
    unsigned int n;
    printf("Enter Number of Strings you need -> ");
    scanf("%d", &n);
    
    char strings[n][MAX_SIZE];
    for(int i = 0; i < n; i++){
        printf("Enter String %d -> ", i+1);
        scanf("%s", strings[i]);
    }

    for(int i = 0; i < n; i++){
        printf("String %d = %s\n", i+1, strings[i]);
    }

    sortStrings(strings, n);
    printf("\nAfter Sorting\n");

    for(int i = 0; i < n; i++){
        printf("String %d = %s\n", i+1, strings[i]);
    }

    
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

void stringReverse(const char str[], char result[]){
    int len = strlen(str);
    int i;
    
    for(i = 0; i < len; i++){
        result[i] = str[len - i - 1];
    }

    result[i] = '\0';
}

void sortStrings(char arr[][MAX_SIZE], int size){
    for(int i = 0; i < size; i++){
        char temp[MAX_SIZE];
        for(int j = i + 1; j < size; j++){
            if(strcmp(arr[i], arr[j]) > 0){
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], temp);
            }
        }
    }
}