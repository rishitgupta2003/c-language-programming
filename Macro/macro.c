//
// Created by rishitg on 4/7/25.
//

#include<stdio.h>
#define PRNT(x, y) \
    printf("Value 1: %d\n", x);\
    printf("Value 2: %d\n", y);\
    printf("MAX: %d\n", MAX(x,y));

#define PI 3.14
#define CIRCLE_AREA(x) PI * (x) * (x)
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define WARNING(...) fprintf(stderr, __VA_ARGS__);
#define SWAP(x,y) \
    *(x) = *(x)^*(y);\
    *(y) = *(y)^*(x);\
    *(x) = *(x)^*(y);


int main(void) {
    int x = 10;
    int y = 20;

    PRNT(x, y);

    //Printing in-build macros
    printf( "__LINE__ = %d\n", __LINE__ ); //Shows current Line
    printf( "__FILE__ = %s\n", __FILE__ ); //Shows which file is being compiled
    printf( "__DATE__ = %s\n", __DATE__ ); //Shows current Data
    printf( "__TIME__ = %s\n", __TIME__ ); //Shows current Time
    printf( "__STDC__ = %d\n", __STDC__ ); //Shows 1 if using ANSI C Standard Compiler

    printf("X: %d\tY: %d\n", x,y);
    SWAP(&x,&y);
    printf("X: %d\tY: %d\n", x,y);

    return 0;
}