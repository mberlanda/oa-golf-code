#include <stdlib.h>
#include <stdio.h>

int* parents;

int countlines(FILE* fp)
{
    if (fp == NULL) return 0;

    int lines = 1;
    char chr;

    chr = getc(fp);
    while(chr != EOF){
        if(chr == '\n') lines++;
        chr = getc(fp);
    }
    return lines;
}

void init_server()
{
    printf("Reading configuration\n");
    fflush(stdout);

    FILE *fp;
    fp=fopen("training.txt", "r");
    int n = countlines(fp);
    printf("Lines count: %d\n", n);
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    // int* pparents = malloc(sizeof(int)*(n+1));
    int pparents[n+1];
    parents = pparents;

    fp=fopen("training.txt", "r");
    while((read = getline(&line, &len, fp)) != -1){
        int x, y;
        sscanf(line, "%d,%d", &x, &y);
        pparents[x] = y;
    }
}

int main(){
    init_server();
    printf("Size of parents: %lu\n", sizeof(*parents));
    printf("Parents: %d", *parents);
}