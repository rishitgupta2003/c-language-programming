#include<stdio.h>

void main(int argc, char *argv[]){

    int num = 20;
    int* pointer = &num;
    printf("Size of Pointer -> %d\n\n", (int) sizeof(pointer));

    int num1;
    int* pointer2 = &num1;

    printf("Address of Num1 => %p\n", pointer2);
    printf("Value stored at Pointer => %d\n", *pointer2);

    int num2 = 30;
    int* pointer3 = &num2;

    printf("\nAddress of Num2 => %p\n", pointer3);
    printf("Address of Pointer storing Num2 Address => %p\n", (void*) &pointer3);
}