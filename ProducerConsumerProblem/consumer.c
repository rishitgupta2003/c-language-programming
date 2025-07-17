//
// Created by rishitg on 15/7/25.
//

#include<stdio.h>
#include<pthread.h>
#include <unistd.h>

extern int* buffer;
extern int* capacity;
extern int cnt;
extern int out;

extern pthread_mutex_t lock;
extern pthread_cond_t not_empty;
extern pthread_cond_t not_full;


void* consumer(void* arg) {
    for (;;) {

        pthread_mutex_lock(&lock);

        while (cnt == 0) {
            pthread_cond_wait(&not_empty, &lock);
        }
        printf("Value Retrieved: %d\n", buffer[out]);
        out = (out + 1) % (*capacity);
        cnt--;


        pthread_cond_signal(&not_full);
        pthread_mutex_unlock(&lock);
    }
}
