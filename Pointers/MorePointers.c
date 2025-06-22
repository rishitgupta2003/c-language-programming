#include<stdio.h>
#include<string.h>

void swapByValue(int a, int b);
void swapByReference(int* const a, int* const b);
int addArrElements(int* const arr_ptr, const int len);
void printChar(char* const ptr);
void copyStringUsingPointer(char *copy, char *orignal);
int stringLength(char* const string);

int main(int argc, char *argv[]){
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int *arr_ptr = arr;
    int len = 9;

    while(len-- > 0){
        printf("%d\t", *arr_ptr);
        arr_ptr++;
    }

    int x = 10;
    int y = 20;

    printf("\nValue of X = %d and Y = %d", x, y);
    swapByValue(x, y);
    printf("\nValue of X = %d and Y = %d after calling swapByValue function\n", x, y);


    printf("\n\nValue of X = %d and Y = %d", x, y);
    swapByReference(&x, &y);
    printf("\nValue of X = %d and Y = %d after calling swapByReference function\n\n", x, y);

    arr_ptr = arr;

    *(arr_ptr + 9) = 10;
    len = 10;


    while(len-- > 0){
        printf("%d\t", *arr_ptr);
        arr_ptr++;
    }

    len = 10;

    printf("\nSum of Elements of Array => %d\n\n",addArrElements(arr, len));

    char charArr[] = "Any String";
    char *p = charArr;
    printChar(charArr);

    for(int i = 0; i < strlen(charArr); i++){
        printf("charArr[%d] = %c\t*(p+%d) = %c\t&charArr[%d] = %p\tp+%d = %p\n",
            i,charArr[i],i,*(p+i),i,&charArr[i],i,p+i 
        );
    }

    char copy[strlen(charArr)];
    copyStringUsingPointer(copy, charArr);
    printf("copy => %s\n", copy);

    len = stringLength(charArr);
    printf("Length of %s => %d\n", charArr, len);


    char string[] = "Rishit Gupta";
    char* pointer = string;

    printf("%s\n", string + 5);

    int aa = 10;
    int* aaa = &aa;
    printf("%d\n", aaa);


    return 0;
}

void swapByValue(int x, int y){
    int temp = x;
    x = y;
    y = temp;
}

void swapByReference(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp; 
}

int addArrElements(int arr[], const int len){
    int sum = 0, *ptr;
    int* end = arr + len;

    for(ptr = arr; ptr < end; ++ptr){
        sum += *ptr;
    }
    
    return sum;
}

void printChar(char *ptr){
    int i = 0;
    while(*ptr != '\0'){
        printf("Character-%d : %c\n", i++, *ptr);
        ptr++;
    }
}

void copyStringUsingPointer(char *to, char *from){
    while(*from){
        *to++ = *from++;
    }
    *to = '\0';
}

int stringLength(char* const string){
    const char* length = string;

    while(*length){
        ++length;
    }

    return length - string;
}