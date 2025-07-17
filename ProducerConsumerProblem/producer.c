//
// Created by rishitg on 15/7/25.
//

#include<stdio.h>
#include<pthread.h>

extern int* buffer;
extern int* capacity;
extern int in;
extern int cnt;

extern pthread_mutex_t lock;
extern pthread_cond_t not_empty;
extern pthread_cond_t not_full;

void* producer(void* arg) {
    int temp;
    for (;;) {

        pthread_mutex_lock(&lock);

        printf("Enter Produced Item Value: ");
        scanf("%d", &temp);

        while (*capacity == cnt) {
            pthread_cond_wait(&not_full, &lock);
        }

        buffer[in] = temp;
        in = (in + 1) % (*capacity);
        cnt++;


        pthread_cond_signal(&not_empty);
        pthread_mutex_unlock(&lock);
    }
}