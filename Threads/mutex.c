//
// Created by rishitg on 13/7/25.
//

#include<stdio.h>
#include<pthread.h>

//static initialization of mutex lock
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t lock2;
int shared_var = 0;

void* do_process(void* arg);

int main(void) {
    pthread_t t1, t2;

    //dynamically initialized mutex lock
    if (pthread_mutex_init(&lock2, NULL) != 0) {
        printf("Mutex Not Initialized");
        return -1;
    }

    pthread_create(&t1, NULL, do_process, NULL);
    pthread_create(&t2, NULL, do_process, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Final Value of Shared Var: %d\n", shared_var);

    return 0;
}

void * do_process(void *arg) {
    pthread_mutex_lock(&lock);
    printf("Thread Aquired by: %lu\n", pthread_self());
    for (int i = 0; i < 100000; i++) {
        shared_var++;
    }
    printf("Thread Unlocked by: %lu\n\n", pthread_self());
    pthread_mutex_unlock(&lock);

    return NULL;
}