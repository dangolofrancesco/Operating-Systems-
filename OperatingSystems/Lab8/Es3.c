#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

sem_t semA,semBCD,semEF,semG,semH,semI;

void* threadA(void *arg)
{
    sem_wait(&semA);
    fprintf(stdout,"A\n");
    sleep(2);
    sem_post(&semBCD);
    sem_post(&semBCD);
    sem_post(&semBCD);

    return NULL;
}
void* threadB(void *arg)
{
    sem_wait(&semBCD);
    fprintf(stdout,"B\n");
    sleep(2);
    sem_post(&semI);
    return NULL;
}
void* threadC(void *arg)
{
    sem_wait(&semBCD);
    fprintf(stdout,"C\n");
    sleep(2);
    sem_post(&semEF);
    sem_post(&semEF);
    return NULL;
}
void* threadD(void *arg)
{
    sem_wait(&semBCD);
    fprintf(stdout,"D\n");
    sleep(2);
    sem_post(&semH);
    return NULL;
}
void* threadE(void *arg)
{
    sem_wait(&semEF);
    fprintf(stdout,"E\n");
    sleep(2);
    sem_post(&semG);
    return NULL;
}
void* threadF(void *arg)
{
    sem_wait(&semEF);
    fprintf(stdout,"F\n");
    sleep(2);
    sem_post(&semG);
    return NULL;
}
void* threadG(void *arg)
{
    sem_wait(&semG);
    sem_wait(&semG);
    fprintf(stdout,"G\n");
    sleep(2);
    sem_post(&semI);
    return NULL;
}
void* threadH(void *arg)
{
    sem_wait(&semH);
    fprintf(stdout,"H\n");
    sleep(2);
    sem_post(&semI);
    return NULL;
}

void* threadI(void *arg)
{
    sem_wait(&semI);
    sem_wait(&semI);
    sem_wait(&semI);

    fprintf(stdout,"I\n");
    fprintf(stdout,"\n\n");
    sleep(2);
    sem_post(&semA);
    return NULL;
}
int main()
{
    pthread_t tidA,tidB,tidC,tidD,tidE,tidF,tidG,tidH,tidI;
    sem_init(&semA,0,1);
    sem_init(&semBCD,0,0);
    sem_init(&semEF,0,0);
    sem_init(&semG,0,0);
    sem_init(&semH,0,0);
    sem_init(&semI,0,0);
    while(1)
    {
        pthread_create(&tidA,NULL,threadA,NULL);
        pthread_create(&tidB,NULL,threadB,NULL);
        pthread_create(&tidC,NULL,threadC,NULL);
        pthread_create(&tidD,NULL,threadD,NULL);
        pthread_create(&tidE,NULL,threadE,NULL);
        pthread_create(&tidF,NULL,threadF,NULL);
        pthread_create(&tidG,NULL,threadG,NULL);
        pthread_create(&tidH,NULL,threadH,NULL);
        pthread_create(&tidI,NULL,threadI,NULL);
    }

 
    sem_destroy(&semA);
    sem_destroy(&semBCD);
    sem_destroy(&semEF);
    sem_destroy(&semG);
    sem_destroy(&semH);
    sem_destroy(&semI);


    return 0;
}