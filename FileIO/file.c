#include<stdio.h>
#include<stdlib.h>

int main(void){
    FILE *pfile = NULL;
    char* str = (char*) malloc(37*sizeof(char));

    char *filename = "textfile.txt";
    pfile = fopen(filename, "r");

    if(pfile == NULL){
        printf("%s doesn't exists", filename);
        return -1;
    }

    int c;

    int cnt = 1;

    while((c = fgetc(pfile)) != EOF){
        if(c == '\n'){
            ++cnt;
        }
    }

    // if(fgets(str, 37, pfile) != NULL){
    //     printf("%s", str);
    // }

    printf("Line in %s: %d\n", filename, cnt);

    fclose(pfile);
    pfile = NULL;
    
    return 0;
}