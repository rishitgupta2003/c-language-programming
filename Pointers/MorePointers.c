#include<stdio.h>

void swapByValue(int a, int b);
void swapByReference(int *a, int *b);

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
    printf("\nValue of X = %d and Y = %d after calling swapByReference function\n", x, y);

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