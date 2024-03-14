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

sem_t r,w,meR,meW;
int nW=0,nR=0;
init(r,1);
init(w,1);
init(meR,1);
init(meW,1);
void reader()
{
    wait(r);
        wait(meR);
        nR++;
        if(nR == 1)
        {
            wait(w);
        }
        signal(meR);
    signal(r);

    wait(meR);
        nR--;
        if(nR == 0)
        {
            signal(w);
        }
    signal(meR);
}

void writer()
{
    wait(meW);
        nW++;
        if(nW == 1)
        {
            wait(r);
        }
    signal(meW);

    wait(w);

    signal(w);

    wait(meW);
        nW--;
        if(nW == 0)
        {
            signal(r);
        }
    signal(meW);

}