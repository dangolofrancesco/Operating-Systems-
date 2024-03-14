#include "pthread.h"
#include "stdio.h"
#include "unistd.h"
#include "math.h"
#include <stdlib.h>

void waitRandomTime(int max)
{
    sleep((int) (rand() % max) + 1);
}

void *Ffunc()
{
    fprintf(stdout,"C\n");

    waitRandomTime(10);
    fprintf(stdout,"F\n");

    return ( (void * ) 1);
}

void *Efunc()
{
    waitRandomTime(10);
    fprintf(stdout,"E\n");
    return ( (void * ) 2);
}


int main()
{
    pthread_t f,e;

    fprintf(stdout,"A\n");
    fflush(stdout);

    fprintf(stdout,"B\n");

    pthread_create(&e,NULL,Efunc,NULL);

    pthread_create(&f,NULL,Ffunc,NULL);


    fprintf(stdout,"D\n");

    pthread_join(e,NULL);
    pthread_join(f,NULL);

    fprintf(stdout,"G\n");

 
    return 0;
}