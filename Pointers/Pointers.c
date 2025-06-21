#include <stdio.h>

int main(int argc, char *argv[]) {

    int num = 20;
    int* pointer = &num;
    printf("Size of 'pointer' (int*)        => %d bytes\n\n", (int) sizeof(pointer));

    int num1 = 100;  // initializing to avoid garbage
    int* pointer2 = &num1;

    printf("Address of 'num1'               => %p\n", (void*)pointer2);
    printf("Value at address 'pointer2'     => %d\n", *pointer2);

    int num2 = 30;
    int* pointer3 = &num2;

    printf("\nAddress of 'num2'               => %p\n", (void*)pointer3);
    printf("Address of 'pointer3' itself    => %p\n", (void*)&pointer3);

    int** pointer4 = &pointer3;

    printf("\nAddress stored in 'pointer4'    => %p (i.e., address of pointer3)\n", (void*)pointer4);
    printf("Value stored at *pointer4       => %p (i.e., address of num2)\n", (void*)*pointer4);
    printf("Value at **pointer4             => %d (i.e., value of num2)\n", **pointer4);

    float x = 10;
    void* a = &x;

    printf("\n(void*) pointer value           => %p\n", a);
    return 0;
}
