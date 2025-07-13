//
// Created by rishitg on 13/7/25.
//

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t lock2 = PTHREAD_MUTEX_INITIALIZER;

void* resource1(void* arg);
void* resource2(void* arg);

int main(void) {
    pthread_t t1, t2;

    pthread_create(&t1, NULL, resource1, NULL);
    pthread_create(&t2, NULL, resource2, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}

void* resource1(void* arg) {
    while (1) {
        pthread_mutex_lock(&lock);
        printf("Thread %lu acquired Resource 1\n", pthread_self());
        sleep(1);  // Simulate work

        if (pthread_mutex_trylock(&lock2) == 0) {
            printf("Thread %lu acquired Resource 2\n", pthread_self());
            // Work done
            sleep(1);
            pthread_mutex_unlock(&lock2);
            pthread_mutex_unlock(&lock);
            printf("Thread %lu finished work\n", pthread_self());
            break;
        } else {
            printf("Thread %lu couldn't acquire Resource 2, releasing Resource 1 and retrying\n", pthread_self());
            pthread_mutex_unlock(&lock);
            sleep(1);  // Backoff
        }
    }
    return NULL;
}

void* resource2(void* arg) {
    while (1) {
        pthread_mutex_lock(&lock2);
        printf("Thread %lu acquired Resource 2\n", pthread_self());
        sleep(1);  // Simulate work

        if (pthread_mutex_trylock(&lock) == 0) {
            printf("Thread %lu acquired Resource 1\n", pthread_self());
            // Work done
            sleep(1);
            pthread_mutex_unlock(&lock);
            pthread_mutex_unlock(&lock2);
            printf("Thread %lu finished work\n", pthread_self());
            break;
        } else {
            printf("Thread %lu couldn't acquire Resource 1, releasing Resource 2 and retrying\n", pthread_self());
            pthread_mutex_unlock(&lock2);
            sleep(1);  // Backoff
        }
    }
    return NULL;
}
