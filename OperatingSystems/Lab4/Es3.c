#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
void sigUsr1(){};
void parent(pid_t child);
void child();
int main (int argc,char **argv) {
    signal(SIGUSR1,sigUsr1);
    pid_t forked = fork();
    if(forked)
    {
        parent(forked);
    }else{
        child();
    }
        return 0;
}
void parent(pid_t child)
{
    int i=0;
    while(i < 10)
    {
        fprintf(stdout,"Parent: Woke Up\n");
        sleep(1);
        kill(child,SIGUSR1);
        pause();
        i++;
    }
}

void child()
{
    int i=0;
    while(i < 10)
    {
        pause();
        fprintf(stdout,"Child: Woke Up\n");
        sleep(1);
        kill(getppid(),SIGUSR1);
        i++;
    }
}