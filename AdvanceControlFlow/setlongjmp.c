//
// Created by rishitg on 2/7/25.
//

#include<stdio.h>
#include<setjmp.h>

void first_function();
void second_function(void);

jmp_buf jumpBuffer;

int main(void) {
    if (setjmp(jumpBuffer) == 0) {
        printf("Value: 0\n");
        first_function();
        printf("This will not print either");
    } else {
        printf("LongJmp Hit\n");
    }
}

void first_function() {
    printf("First Function\n");
    second_function();
}

void second_function(void) {
    printf("Second Function\n");
    longjmp(jumpBuffer, 10);
}
