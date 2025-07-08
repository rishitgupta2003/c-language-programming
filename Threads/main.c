//
// Created by rishitg on 7/7/25.
//

/*
 *                  THREADS
 * Thread operations:
 * 1. Thread creation
 * 2. Thread Termination
 * 3. Synchronization (Joins, Blocking)
 * 4. Scheduling
 * 5. Data Management
 * 6. Process Interaction
 */

#include<stdio.h>
#include<pthread.h>
#include <stdlib.h>

struct Data {
    int multiplier;
    int acc_bal;
};

void* threadHello(void* arg);
void* final_amount(void* arg);

int main(int argc, char* argv[]) {
    pthread_t thread;

    struct Data* data = (struct Data*) malloc(sizeof(struct Data));

    data->acc_bal = atoi(argv[1]);
    data->multiplier = atoi(argv[2]);

    pthread_create(&thread, NULL, final_amount, (void*) data);

    int* save_amount = NULL;

    pthread_join(thread, (void**) &save_amount);

    printf("Final Calculated Amount: %d\n", *save_amount);
    free(save_amount);
    free(data);
    pthread_exit(NULL);
}

void* threadHello(void* arg) {
    printf("Thread - %lu: Hello World!!\n", pthread_self());
    return NULL;
}

void* final_amount(void *arg) {
    const struct Data* data = (struct Data *) arg;
    int* result = malloc(sizeof(int));
    *result = data->multiplier * data->acc_bal;

    return result;
}