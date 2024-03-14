#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc,char **argv)
{
    int i;
    int n = atoi(argv[1]);

    for(i=0; i < n; i++)
    {
        if(fork() == 0)
        {
            fprintf(stdout,"PID : %d \t",getpid());
            break;
        }
    }
}