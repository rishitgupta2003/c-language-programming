//
// Created by rishitg on 5/7/25.
//

#include<stdio.h>
#include <stdlib.h>

int sum(int a, int b);
int diff(int a, int b);

typedef int operation(int, int);

int main(int argc, char* argv[]) {
    operation *func = NULL;
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);

    func = &sum;
    printf("Sum: %d\n", (*func)(a,b));

    func = &diff;
    printf("Difference: %d\n", (*func)(a,b));

    void* p = NULL;
    int* q = NULL;

    if (p == q) printf("equal");

    return 0;
}

int sum(int a, int b) {
    return a + b;
}

int diff(int a, int b) {
    return a > b ? a-b : b-a;
}
