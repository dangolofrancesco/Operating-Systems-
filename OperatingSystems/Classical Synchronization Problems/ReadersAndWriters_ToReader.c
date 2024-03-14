#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h> 
#include <unistd.h> 
#include <ctype.h> 
#include <pthread.h> 
#include <stdlib.h> 
#include <semaphore.h>
#define SIZE 100
sem_t meR,w,meW;
int nR=0;
sem_init(&meR,0,1);
sem_init(&w,0,1);
sem_init(&meW,0,1);
int reader()
{
    sem_wait(&meR);
    nR++;
    if(nR == 1)
    {
        sem_wait(&w);
    }
    sem_post(&meR);
    //read
    sem_wait(&meR);
    nR--;
    if(nR == 0)
    {
        sem_post(&w);
    }
    sem_post(&meR);

}

int writer()
{
    sem_wait(&meW);
    sem_wait(&w);
    //write
    sem_post(&w);
    sem_post(&meW);
}