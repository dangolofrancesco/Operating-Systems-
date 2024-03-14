#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void left();
void right();
int main()
{
    fprintf(stdout,"P1\n");
    if( fork() == 0 )
    {
        right();
        exit(0);
    }else {
        left();
        wait((int *) 0);
        fprintf(stdout,"P9\n");
        return 0;
    }
}
void right()
{
    fprintf(stdout,"P3\n");

    if(fork() == 0)
    {
        fprintf(stdout,"P6\n");
        exit(0);
    }else{
        wait((int *) 0);
        fprintf(stdout,"P8\n");
        exit(0);

    }
}

void left()
{   
    fprintf(stdout,"P2\n");

    if( fork() == 0 )
    {
        fprintf(stdout,"P5\n");
        exit(0);
    }

    fprintf(stdout,"P4\n");

    wait((int *) 0);

    fprintf(stdout,"P7\n");
    return;
}