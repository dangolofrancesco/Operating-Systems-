#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h> 
#include <unistd.h> 
#include <ctype.h> 
#include <pthread.h> 
#include <stdlib.h> 
#include <semaphore.h>
#define HUNGRY 1
#define EATING 2
#define THINKING 3

int state[N];
sem_t sem[N], mutex;
init(sem[0],0); ... init(sem[N],0);
init(mutex,1);


philosopher()
{
    while(1)
    {
        thinking();
        takeForks(i);
        eat();
        putforks(i);
    }
}

takeForks(int i)
{
    wait(mutex);
    state[i]=HUNGRY 
    test(i);
    signal(mutex); 
    wait(sem[i]);   
}
putForks(int i)
{
    wait(mutex);
    state[i] = THINKING;
    test(i+1);
    test(i-1);
    signal(mutex);
}
test(int i)
{
    if(state[i] == HUNGRY && state[i-1] != EATING && state[i+1] != EATING)
    {
        state[i] = EATING;
        signal(sem[i]);
    }
}