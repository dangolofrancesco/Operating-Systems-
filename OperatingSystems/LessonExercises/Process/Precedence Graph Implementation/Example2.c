#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void right();
void left();


int main(int argc,char **argv)
{
    fprintf(stdout,"S1\n");

    pid_t pid = fork();

    if(pid == 0)
    {
        right();
    }else {
        left();
    
        while( wait(NULL) != pid );

        fprintf(stdout,"S7\n");
    }
    return 0;
}

void left()
{
    fprintf(stdout,"S2\n");

    fprintf(stdout,"S4\n");

    return;
}

void right()
{
    fprintf(stdout,"S3\n");
    pid_t pid = fork();
    if( pid == 0 )
    {
        fprintf(stdout,"S6\n");
        exit(0);
    }
    fprintf(stdout,"S5\n");
    while( wait(NULL) != pid );

    exit(0);
}