#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#define N 200
void send(int *);
void receive(int *);
int main()
{
    int sender,receiver;
    int fd[2];

    pipe(fd);

    sender = fork();

    if(sender != 0)
    {
        receive(fd);
    }else
    {
        receiver = fork();

        if(receiver == 0)
        {
            send(fd);
        }
    }
    waitpid(sender,0,0);
    waitpid(receiver,0,0);
    return 0;
}
void send(int* fd)
{
    char str[N];
    close(fd[0]); //non legge e chiudiamo quell'opzione 
    int n,lstring;
    while(1)
    {
        fprintf(stdout,"Inserisci una stringa: ");
        fflush(stdout);

        scanf("%s",str);

      

        lstring = strlen(str)+1;

        fprintf(stdout,"Sender: %s %d\n",str,lstring);
        fflush(stdout);

        write(fd[1],&lstring,1);
        write(fd[1],str,lstring);


        if(strcmp(str,"end") == 0)
        {
            close(fd[1]);
            return;
        }
        sleep(1);
    }
}

void receive(int* fd)
{
    int n,i;
    char str[N];
    close(fd[1]);
    while(1)
    {
        read(fd[0],&n,1);
        read(fd[0],str,n);
     

        fprintf(stdout,"Receiver: %s %d %d\n",str,n,strlen(str));
        fflush(stdout);
        
        if(strcmp(str,"end") == 0)
        {
            close(fd[0]);
            return ;
        }
        for(i=0; i < strlen(str); i++)
        {
            str[i] = toupper(str[i]);
        }
        fprintf(stdout,"Stringa inserita: %s\n",str);
    }
}