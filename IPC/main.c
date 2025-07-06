//
// Created by rishitg on 6/7/25.
//

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

void handler_dividebyzero(int signum);
void handler_alarm(int signum);

//Comment out the code which is not needed to run each SIGNAL properly.
//Need to explore sigaction

int main(int argc, char* argv[]) {
    signal(SIGFPE, handler_dividebyzero); //Handling Divide by 0
    signal(SIGALRM, handler_alarm); //Handling Alarm so program doesn't terminate

    // fork();
    printf("pid: %d\n", getpid());

    /*
     * SIGSTOP -> Stop the current Execution of program
     * kill -s SIGCONT <processId> //to re-execute the remaining instructions after stop
     */

    printf("Testing SIGSTOP\n");
    raise(SIGSTOP);
    printf("I am Back\n");

    /*
     * Need to catch SIGALRM or process Terminates
     * signal (SIGALRM, alarmHandler)
     */

    printf("Checking Alarm\n");
    alarm(5);
    for (int i = 0; i < 10; i++) {
        printf("%d\n", i+1);
        sleep(1);
    }



    int num = atoi(argv[1]);
    int num2 = atoi(argv[2]);

    printf("Num/Num2: %d\n", num/num2);

    return 0;
}

void handler_dividebyzero(int signum) {
    if (signum == SIGFPE) {
        printf("Divide By Zero (Float Point Error: [SIG value: %d])\n", signum);
        exit(0);
    }

    printf("Received: %d", signum);
}

void handler_alarm(int signum) {
    if (signum == SIGALRM) {
        printf("Alarm Caught [SIG value: %d]\n", signum);
    }

}