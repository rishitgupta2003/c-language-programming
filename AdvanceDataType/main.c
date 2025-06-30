//
// Created by rishitg on 27/6/25.
//

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//#include<complex.h>

// typedef struct ListNode* ListNode_ptr;
//
// typedef struct ListNode {
//     int data;
//     ListNode_ptr next;
// } ListNode;
//
// int main(void) {
//     ListNode_ptr temp, head = (ListNode_ptr) malloc(sizeof(ListNode));
//     head->data = 10;
//     head->next = (ListNode_ptr) malloc(sizeof(ListNode));
//     head->next->data = 20;
//     head->next->next = NULL;
//
//     temp = head;
//
//     while (temp != NULL) {
//         printf("Value at %p: %d\n", temp, temp->data);
//         temp = temp->next;
//     }
//
//     printf("\n");
//
//     temp = head;
//
//     while (temp != NULL) {
//         ListNode_ptr res = temp;
//         temp = temp->next;
//         printf("Memory Location %p freed\n", res);
//         free(res);
//     }
//
//     temp = head = NULL;
//
//     return 0;
// }

// struct flexible {
//     int arraySize;
//     int arr[];
// };

// int main(void) {
//     int desiredSize;
//     printf("Enter Size of Array: ");
//     scanf("%d", &desiredSize);
//
//     struct flexible* fArr = (struct flexible*) malloc(sizeof(struct flexible) + desiredSize*sizeof(int));
//
//     fArr->arraySize = desiredSize;
//
//     for (int i = 0; i < desiredSize; i++) {
//         printf("Enter Element %d: ", i);
//         scanf("%d", &(fArr->arr[i]));
//     }
//
//     for (int i = 0; i < desiredSize; i++) {
//         printf("%d\t", fArr->arr[i]);
//     }
//
// }


//Complex Numbers
// int main(void) {
//     double complex z = 1.0 + 3.0*I;
//     double complex z1 = 2.0 + 6.0*I;
//
//     printf("Complex Numbers\nz = %.2f + %.2fi\n", creal(z), cimag(z));
//     printf("Complex Numbers\nz = %.2f + %.2fi\n", creal(z1), cimag(z1));
//
//     printf("Done with Complex Numbers\n");
//
// }


//Designated Initializer
// char main(void) {
//     int arr[100] = {1,2,3, [3 ... 9] = 10, [10] = 80, [70] = 90, [42] = 102};
//     for (int i = 0; i < 100; i++) {
//         printf("%d ", arr[i]);
//     }
//
//
//     int const x = 10;
//
// }

//Binary to Decimal

int convertToDecimal(long long bin);
long long convertToBinary(int num);

void swap(short int* p, short int* q);


int main(void) {
    // long long bin = 1001001;
    // int dNum = convertToDecimal(bin);
    //
    // int num = 25;
    // int bNum = convertToBinary(num);
    //
    // printf("Binary: %lld\tDecimal: %d\n", bin, dNum);
    // printf("Decimal: %d\tBinary: %lld\n", num, bNum);

    // short int num1 = 10;
    // short int num2 = 20;
    //
    // printf("Num1=%d\tNum2=%d\n", num1, num2);
    // swap(&num1, &num2);
    // printf("Num1=%d\tNum2=%d\n", num1, num2);
    //
    // int a = 1;
    // printf("NUMBER = %d\t~NUMBER = %d\n", a, ~(a));
    //
    // printf("%d\n", 1&(-2));

    int a;
    int b;

    printf("Enter Number 1: ");
    scanf("%d", &a);

    printf("Enter Number 2: ");
    scanf("%d", &b);

    printf("Number1:\nDecimal: %d\tBinary: %lld\n\n", a, convertToBinary(a));
    printf("Number2:\nDecimal: %d\tBinary: %lld\n\n", b, convertToBinary(b));

    printf("~a: %lld\n", convertToBinary((~a)));
    printf("~b: %lld\n", convertToBinary((~b)));

    printf("a(%lld)&b(%lld): %lld\na(%lld)|b(%lld): %lld\na(%lld)^b(%lld): %lld\n",
        convertToBinary(a), convertToBinary(b),
        convertToBinary(a), convertToBinary(b),
        convertToBinary(a), convertToBinary(b),
        convertToBinary(a&b), convertToBinary(a|b), convertToBinary(a^b));

    printf("a(%lld) << 2: %lld\nb(%lld) >> 2: %lld\n", convertToBinary(a), convertToBinary(a << 2), convertToBinary(b), convertToBinary(a >> 2));
}

// 0000 0010
// 1111 1101
// 0000 0001
//------------
// 1111 1110

void swap(short int* p, short int* q) {
    *p ^= *q;
    *q ^= *p;
    *p ^= *q;
}

long long convertToBinary(int num) {
    long long result = 0;
    int i = 1;

    while (num != 0) {
        int rem = num % 2;
        num = num / 2;
        result += rem * i;
        i *= 10;
    }

    return result;
}

int convertToDecimal(long long bin) {
    int i = 0;
    int num = 0;

    while (bin != 0) {
        long long rem = bin % 10;
        bin /= 10;
        num += (int) rem << i++;
    }

    return num;
}