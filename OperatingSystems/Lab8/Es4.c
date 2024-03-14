#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>


sem_t semA,semB,semC,semD,semE,semF,semG,semH,semI;

void* threadA(void *arg)
{
    while(1)
    {
        sem_wait(&semA);
        fprintf(stdout,"A\n");
        sleep(2);
        sem_post(&semB);
        sem_post(&semC);
        sem_post(&semD);
    }

    return NULL;
}
void* threadB(void *arg)
{
    while(1)
    {
        sem_wait(&semB);
        fprintf(stdout,"B\n");
        sleep(2);
        sem_post(&semI);
    }
    return NULL;
}
void* threadC(void *arg)
{
    while(1)
    {
        sem_wait(&semC);
        fprintf(stdout,"C\n");
        sleep(1);
        sem_post(&semE);
        sem_post(&semF);
    }
    return NULL;
}
void* threadD(void *arg)
{
    while(1)
    {
        sem_wait(&semD);
        fprintf(stdout,"D\n");
        sleep(1);
        sem_post(&semH);
    }
    return NULL;
}
void* threadE(void *arg)
{
    while(1)
    {
        sem_wait(&semE);
        fprintf(stdout,"E\n");
        sleep(1);
        sem_post(&semG);
    }
    return NULL;
}
void* threadF(void *arg)
{
    while(1)
    {
        sem_wait(&semF);
        fprintf(stdout,"F\n");
        sleep(1);
        sem_post(&semG);
    }
    return NULL;
}
void* threadG(void *arg)
{
    while(1)
    {
        sem_wait(&semG);
        sem_wait(&semG);
        fprintf(stdout,"G\n");
        sleep(2);
        sem_post(&semI);
    }
    return NULL;
}
void* threadH(void *arg)
{
    while(1)
    {
        sem_wait(&semH);
        fprintf(stdout,"H\n");
        sleep(2);
        sem_post(&semI);
    }
    return NULL;
}

void* threadI(void *arg)
{
    while(1)
    {
        sem_wait(&semI);
        sem_wait(&semI);
        sem_wait(&semI);

        fprintf(stdout,"I\n");
        fprintf(stdout,"\n\n");
        sleep(2);
        sem_post(&semA);
    }
    return NULL;
}
int main()
{
    pthread_t tidA,tidB,tidC,tidD,tidE,tidF,tidG,tidH;
    sem_init(&semA,0,1);
    sem_init(&semB,0,0);
    sem_init(&semC,0,0);
    sem_init(&semD,0,0);
    sem_init(&semE,0,0);
    sem_init(&semF,0,0);
    sem_init(&semG,0,0);
    sem_init(&semH,0,0);
    sem_init(&semI,0,0);
    pthread_create(&tidA,NULL,threadA,NULL);
    pthread_create(&tidB,NULL,threadB,NULL);
    pthread_create(&tidC,NULL,threadC,NULL);
    pthread_create(&tidD,NULL,threadD,NULL);
    pthread_create(&tidE,NULL,threadE,NULL);
    pthread_create(&tidF,NULL,threadF,NULL);
    pthread_create(&tidG,NULL,threadG,NULL);
    pthread_create(&tidH,NULL,threadH,NULL);
    
    threadI(NULL);


    sem_destroy(&semA);
    sem_destroy(&semB);
    sem_destroy(&semC);
    sem_destroy(&semD);
    sem_destroy(&semE);
    sem_destroy(&semF);
    sem_destroy(&semG);
    sem_destroy(&semH);

    return 0;
}