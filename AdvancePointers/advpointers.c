//
// Created by rishitg on 4/7/25.
//

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
/*
 * this function shows every time a pointer is passed
 * a new reference pointing to the same value is passed
 * that's why double pointer
*/

void PRNT(int i , int *ip, int **ipp);
void challenge_one(int i, int *ip, int **ipp);

int main(void) {
    time_t t;
    srand((unsigned) time(&t));
    int i = rand();
    int *ip = &i; //when passed in the function copy of this pointer which is pointing to the same element is passed
    int **ipp = &ip; //when this passed in the function original pointer can be passed

    printf("Value at %p: %d\n", &i, i);
    printf("Value at %p: %p\n", &ip, ip);
    printf("Value at %p: %p\n", &ipp, ipp);

    printf("\n\n");

    PRNT(i,ip,ipp);
    challenge_one(i,ip,ipp);

}

void PRNT(int i, int *ip, int **ipp) {
    printf("Value at %p: %d\n", &i, i);
    printf("Value at %p: %p\n", &ip, ip);
    printf("Value at %p: %p\n", &ipp, ipp);
}

void challenge_one(int i, int *ip, int **ipp) {
    printf("\nValue of num:\t%d\n", i);
    printf("Value of num with single pointer:\t%d\n", *ip);
    printf("Value of num with double pointer:\t%d\n", **ipp);

    printf("\nAddress of num:\t%p\n", &i);
    printf("Address of num with single pointer:\t%p\n", ip);
    printf("Address of num with double pointer:\t%p\n", *ipp);
}
