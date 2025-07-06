//
// Created by rishitg on 7/7/25.
//

#include <limits.h>
#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

void handler_alarm(int signum);
void handler_interrupt(int signum);

int score = 0;
int cnt = 0;

int main(void) {
    signal(SIGALRM, handler_alarm);
    signal(SIGINT, handler_interrupt);

    srand((unsigned int) (time) (NULL));

    int a = rand() % 100;
    int b = rand() % 100;

    while (true) {
        cnt++;
        system("clear");
        long ans = 0;
        printf("\nNumber 1:   %d\n", a);
        printf("Number 2: X %d\n", b);
        printf("Answer  :-------\n\t   ");

        alarm(5);
        scanf("%ld", &ans);
        alarm(0);
        if (ans == (long) a*b) {
            score++;
        }else printf("Oops Wrong Answer! No points\n");

        a = rand() % 10;
        b = rand() % 10;
    }
}

void handler_interrupt(int signum) {
    system("clear");
    if (signum == SIGINT) {
        printf("Good Game\nFinal Score: %d out of %d\n ", score, cnt);
    }
    exit(0);
}

void handler_alarm(int signum) {
    system("clear");
    if (signum == SIGALRM) {
        printf("No Answer!! Times Up\n");
    }

    raise(SIGINT);
}
