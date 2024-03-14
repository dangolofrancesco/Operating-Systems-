#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#define N 200

int main()
{
    int child;
    int i;
    int msg;
    int fd1[2],fd2[2];

    pipe(fd1);
    pipe(fd2);
    child = fork();
    

    if(child == 0)
    {
        close(fd2[0]);
        close(fd1[1]);
        while(1)
        {
            read(fd1[0],&msg,4);

            if(msg == 0)
            {
                fprintf(stdout,"child stopped\n");
                fflush(stdout);

                close(fd1[0]);
                close(fd2[1]);
                return 0;
            }

            fprintf(stdout,"i'm the child PID=%d\n",getpid());
            fflush(stdout);

            write(fd2[1],&msg,4);
        }
    }else
    {
        close(fd2[1]);
        close(fd1[0]);
        i=0;
        while(i < 10)
        {
            i++;

            fprintf(stdout,"i'm the father PID=%d\n",getpid());
            fflush(stdout);
        
            write(fd1[1],&i,4);

            read(fd2[0],&msg,4);
        }

        i=0;
        write(fd1[1],&i,4);
    }

    close(fd2[0]);
    close(fd2[1]);
    waitpid(child,0,0);

    return 0;
}