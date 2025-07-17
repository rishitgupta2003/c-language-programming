//
// Created by rishitg on 15/7/25.
//

#include<stdio.h>
#include<pthread.h>
#include<signal.h>

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t not_empty = PTHREAD_COND_INITIALIZER;
pthread_cond_t not_full = PTHREAD_COND_INITIALIZER;

void* producer(void* arg);
void* consumer(void* arg);
void set_buffer_size(int n);
void handle_interrupt(int signum);

int main(void) {
    signal(SIGINT, handle_interrupt);

    int n;
    printf("Enter Buffer Size: ");
    scanf("%d", &n);

    set_buffer_size(n);

    pthread_t t1, t2;
    pthread_create(&t1, NULL, producer, NULL);
    pthread_create(&t2, NULL, consumer, NULL);

    pthread_detach(t1);
    pthread_detach(t2);

    pthread_exit(NULL);
}

