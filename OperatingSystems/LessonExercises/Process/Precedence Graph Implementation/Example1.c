#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc,char **argv)
{
    fprintf(stdout,"S1\n");

    if ( fork() == 0 )
    {
        fprintf(stdout,"S3\n");
        exit(0);
    }
    fprintf(stdout,"S2\n");
    wait(NULL);
    fprintf(stdout,"S4\n");

    if(fork() == 0)
    {
        fprintf(stdout, "S6\n");
        exit(0);
    }
    fprintf(stdout,"S5\n");

    wait(NULL);

    fprintf(stdout,"S7\n");
    return 0;
}