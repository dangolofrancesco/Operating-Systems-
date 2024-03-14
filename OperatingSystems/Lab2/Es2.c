#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc,char **argv)
{
    int n = atoi(argv[1]);
    int t = atoi(argv[2]);
    int i;
    for(i=0; i< n; i++)
    {
        if( !fork() )
        {
            fprintf(stdout,"PPID: %d, PID: %d\n", getppid(),getpid());
        }else {
            //father 
            if( !fork() )
            {
                fprintf(stdout,"PPID: %d, PID: %d\n", getppid(),getpid());
            }else {
                exit(0);
            }
        }
    }
    printf("Leaf PID: %d\n", getpid());
    sleep(t);
    return 0;
}