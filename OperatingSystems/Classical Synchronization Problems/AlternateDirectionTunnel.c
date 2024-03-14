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

sem_t s1,s2,busy;

init(busy,1);
init(s1,1);
init(s2,1);
int nS1=0;
int nS2=0;

s1()
{
    wait(s1);
    nS1++;

    if(nS1 == 1)
    {
        wait(busy);
    }
    signal(s1);
    // flow from left to right
    wait(s1);
    nS1--;

    if(nS1 == 0)
    {
        signal(busy);
    }
    signal(s1);
}

s2()
{
    wait(s2);
    nS2++;
    if(nS2 == 1)
    {
        wait(busy);
    }
    signal(s2);

    wait(s2);
    nS2--;
    if(nS2 == 0)
    {
        signal(busy);
    }
    signal(s2);
}