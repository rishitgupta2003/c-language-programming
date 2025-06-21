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
    
    // int arr[16];
    // arr[5] = 12;
    // arr[10] = 21;

    // int *p_arr5 = &arr[5];
    // int *p_arr10 = &arr[10];

    // printf("Difference between 2 pointers => %ld\n", p_arr10 - p_arr5);  // this will print 5;


    long i = 0L;
    long j = 0L;
    
    long *p_i = NULL;

    p_i = &i;   // p_i == address of i
    *p_i = 2L; // *p_i = 2L (i == 2L)

    ++i;        // i = 3L (*p_i = 3) 
    j += *p_i; // j(0) + 3L(*p_i)

    p_i = &j; // p_i == address of j
    ++*p_i;  // p_i = 4L (j == 4L)

    // Dereferencing a pointer and operating on it updates orignal variable;

    printf("i = %ld\nj = %ld\np_i = %p\n*p_i = %ld\nAddress of i => %p\nAddress of j => %p\n", i, j, p_i, *p_i, &i, &j);

    int y = 230503;
    const int* p_y = &y;
    // ++*p_y;   // Compile Time error (no pointer arithmetic operation possible on const int*)
    ++y;

    int* const p_y1 = &y; // Pointer cannot change address but arithmetic possible;

    const int* const p_y2 = &y; //nothing is possible

    printf("Value of *p_y => %d\nValue of y => %d\n", *p_y, y);

    ++*p_y1;
    printf("Value of *p_y1 => %d\n", *p_y1);

    // p_y1 = &num; //not possible


    int intValue = 23;
    float floatValue = 23.05;
    char charValue = 's';

    void* v_pointer = NULL; //void | generic pointer example

    v_pointer = &intValue;
    printf("\nValue of V_Pointer => %d\n", *(int*) v_pointer);

    v_pointer = &floatValue;
    printf("Value of V_Pointer => %.2f\n", *(float*) v_pointer);

    v_pointer = &charValue;
    printf("Value of V_Pointer => %c\n", *(char*) v_pointer);

    return 0;
}
