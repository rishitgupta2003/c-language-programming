//
// Created by rishitg on 30/6/25.
//

#include <stdbool.h>
#include <stdint.h>
#include<stdio.h>
#include <stdlib.h>

//define my options
#define PRINT_NAME 0x01 //0000 0001
#define PRINT_AGE 0x02 //0000 0010

typedef struct Data DataObj;
typedef struct Data* DataPtr;

struct Box {
    bool isOpaque: 1;
    bool isBorder: 1;
    unsigned int borderStyle: 2;
    unsigned int possibleColor: 3;
};


struct Data {
    unsigned int data: 4;
    unsigned int counter: 4;
}__attribute__((packed)); //this will closely pack (no alignment and padding)

struct PersonalInfo {
    char name[100];
    int age;
};

void printInfo(uint8_t options, struct PersonalInfo* obj);
inline int setBit(int num, int setBit);
inline int resetBit(int num, int resetBit);
inline int toggleBit(int num, int resetBit);
inline int countSetBit(int num);
inline int* countBits(int n);

extern int num;

int main(void) {
    printf("BitManipulationDone");
}

int setBit(int num, int setBit) {
    num |= (1 << setBit);
    return num;
}

int resetBit(int num, int resetBit) {
    num &= ~(1 << resetBit);
    return num;
}

int toggleBit(int num, int resetBit) {
    num ^= (1 << resetBit);
    return num;
}

void printInfo(uint8_t options, struct PersonalInfo* obj) {
    if (options & (PRINT_AGE | PRINT_NAME)) {
        printf("{Name: %s\tAge: %d}\n", obj->name, obj->age);
    }

    else if (options & PRINT_NAME) {
        printf("Name: %s\n", obj->name);
    }

    else if (options & PRINT_AGE) {
        printf("Age: %d\n", obj->age);
    }
}

int countSetBit(int n) {
    int cnt = 0;
    while(n > 0) {
        if((n & 1) == 1){
            cnt++;
        }
        n >>= 1;
    }
    return cnt;
}

int * countBits(int n) {
    int* res = (int*) malloc((int)((n+1)*sizeof(int)));
    int* p = res;
    for(int i = 0; i <= n; i++){
        *p = countSetBit(i);
        p++;
    }

    return res;
}