#include<stdio.h>
#include<stdlib.h>

int main(void){
    FILE* filePointer = NULL;
    filePointer = fopen("textWrite.txt", "w");

    fputs("DCU Started\n", filePointer);
    fputs("Movies Chronological Order\n", filePointer);
    fputs("1. Creature Commandos\n", filePointer);
    fputs("2. Superman\n", filePointer);
    fputs("3. Peacemaker Season 2\n", filePointer);

    fclose(filePointer);
    filePointer = NULL;

    return 0;
}