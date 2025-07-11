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
#include <unistd.h>

struct Data {
    int multiplier;
    int acc_bal;
};

int shared_variable = 0;

void* threadHello(void* arg);
void* final_amount(void* arg);
void* check_for_race(void* arg);
void* thread_detach(void* arg);

int main(int argc, char* argv[]) {
    // pthread_t thread;
    //
    // struct Data* data = (struct Data*) malloc(sizeof(struct Data));
    //
    // data->acc_bal = atoi(argv[1]);
    // data->multiplier = atoi(argv[2]);
    //
    // pthread_create(&thread, NULL, final_amount, (void*) data);
    //
    // int* save_amount = NULL;
    //
    // pthread_join(thread, (void**) &save_amount);
    //
    // printf("Final Calculated Amount: %d\n", *save_amount);
    // free(save_amount);
    // free(data);
    // pthread_exit(NULL);

    // pthread_t thread;
    // pthread_t thread2;
    // pthread_t thread3;
    //
    // pthread_create(&thread, NULL, check_for_race, NULL);
    // pthread_create(&thread2, NULL, check_for_race, NULL);
    // pthread_create(&thread3, NULL, check_for_race, NULL);
    //
    // pthread_join(thread, NULL);
    // pthread_join(thread2, NULL);
    // pthread_join(thread3, NULL);
    //
    // printf("Final Value of shared Value: %d\n", shared_variable);

    printf("Main Start\n");
    pthread_t thread;
    pthread_create(&thread, NULL, thread_detach, NULL);
    pthread_detach(thread);
    // sleep(1);
    printf("Main Exiting\n");
    pthread_exit(NULL);
    // return 0;
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

void * check_for_race(void *arg) {
    for (int i = 0; i < 10; i++) {
        int temp = shared_variable;
        usleep(1);
        temp++;
        shared_variable = temp;
        printf("Shared Variable: %d\n", shared_variable);
    }

    return NULL;
}

void * thread_detach(void *arg) {
    printf("Thread:%lu Started\n", pthread_self());
    sleep(2);
    printf("Thread:%lu Exited\n", pthread_self());
    return NULL;
}
