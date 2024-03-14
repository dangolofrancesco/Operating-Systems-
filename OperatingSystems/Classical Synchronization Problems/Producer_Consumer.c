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

int v1()
{
    sem_t full,empty,producer,consumer;

    sem_init(&full,0,0);
    sem_init(&producer,0,0);
    sem_init(&consumer,0,0);
    sem_init(&empty,0,SIZE);
    int producer()
    {
        while(TRUE)
        {
            sem_wait(&empty);
            sem_wait(&producer);
            enqueue(val);
            sem_signal(&producer);
            sem_signal(&full);

        }
    }

    int consumer()
    {
        while(TRUE)
        {
            sem_wait(&full);
            sem_wait(&consumer);
            dequeue(&val);
            sem_signal(&consumer)
            sem_signal(&empty);
        }
    }
}