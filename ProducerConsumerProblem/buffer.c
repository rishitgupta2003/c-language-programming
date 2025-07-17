//
// Created by rishitg on 15/7/25.
//

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int *buffer;
int *capacity;
volatile int cnt = 0;
int in = 0;
int out = 0;

extern pthread_mutex_t lock;
extern pthread_cond_t not_empty;
extern pthread_cond_t not_full;

void set_buffer_size(int size) {
    buffer = (int*) malloc(size * sizeof(int));
    capacity = (int*) malloc(sizeof(int));
    *capacity = size;
}


void handle_interrupt(int signum) {
    printf("\n\tInterrupt Detected!!\tLeaving");
    printf("\nBuffer Contents:\t");

    int* ptr = buffer;
    for (int i = 0; i < (*capacity); i++) {
        printf("%d\t", *ptr);
        ptr++;
    }

    free(buffer);
    free(capacity);

    exit(0);
}