//
// Created by rishitg on 3/7/25.
//

#include<stdio.h>
#include<stdarg.h>

double sumOfNums(int n, ...);

int main(void) {
    double sum = sumOfNums(3,1.1,2.2,3.3);
    printf("Sum => %.2lf\n", sum);
    return 0;
}

double sumOfNums(int n, ...) {
    va_list parg;
    if (n == 0) return 0;

    double sum = 0;
    // double value;

    va_start(parg,n);

    for (int i = 0; i < n; i++) {
        sum += va_arg(parg, double);
    }

    va_end(parg);

    return sum;
}
