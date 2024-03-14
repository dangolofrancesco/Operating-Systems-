#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#define MAXC 100
int compare (const void *a, const void *b)
{
    const int *ia = (const int *)a; // casting pointer types 
    const int *ib = (const int *)b;
    return *ia  - *ib; 
}
void sorting(char *name_filer, char *name_filew)
{
    FILE *fpr,*fpw;
    int n,i;
    int *arr;
    fpr = fopen(name_filer,"r");
    fpw = fopen(name_filew,"w");


    if(fpr == NULL || fpw == NULL)
    {
        fprintf(stdout,"error detected:");
        return;
    }

    fscanf(fpr,"%d",&n);
    arr = (int *) malloc((sizeof(int) * n));
    
    for(i=0;i < n; i++)
    {
        fscanf(fpr,"%d",arr + i);
    }
    qsort((int *)arr, n, sizeof(int), compare);                          

    for(i=0; i < n;i++)
    {
        fprintf(fpw,"%d\n",arr[i]);
    }

    free(arr);
    pthread_exit();


}
void strsInArray(char* str,char *arr[],int n)
{
    char buff[MAXC];
    int i=0,s=0,c;

    while(str[c] != '\0')
    {
        arr[s][i++]= str[c];
        if(str[c] == ' '){
            i=0;
            s++;
        }
        c++;
    }
}
int main(int argc, char *argv[])
{
    int n = atoi(argv[1]);
    char **fw, **fr;
    int i;

    fw = (char **)malloc(sizeof(char *) *n);
    fr = (char **)malloc(sizeof(char *) *n);

    for(i=0; i < n; i++)
    {
        fw[i] = (char *) malloc(sizeof(char) * MAXC);
        fr[i] = (char *) malloc(sizeof(char) * MAXC);
    }
    strsInArray(argv[2],fr,n);
    strsInArray(argv[3],fw,n);

    sorting("./test1.txt","./nuovo_test1.txt");

    for(i=0; i < n; i++)
    {
        pthread_create(NULL,NULL,sorting,argv[2][i],argv[3][i]);
    }


    for(i=0; i < n; i++)
    {
        free(fr[i]);
        free(fw[i]);
    }
    free(fw);
    free(fr);
    
    return 0;
}