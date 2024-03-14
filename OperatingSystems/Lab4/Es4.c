#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/wait.h>
#include <string.h>
#include <ctype.h>
#define FILE_NAME "./fileShared.txt"
void sigUsr1(){};
void consumer(pid_t child);
void producer();
int main (int argc,char **argv) {
    char msg[100];
    int cpid;
    int i,senderPID;
    int status;

    signal(SIGUSR1,sigUsr1);
    signal(SIGUSR2,sigUsr1);

    
    int forkedP,forkedC;

    forkedC = fork();
    if(forkedC == 0)
    {
        while(1)
        {
            pause();
            FILE* fp = fopen(FILE_NAME,"r");

            if(fp == NULL)
            {
                fprintf(stdout,"errore file non trovato");
                exit(0);
            }

            
            fscanf(fp,"%d %s",&senderPID,msg);

            fclose(fp);

            if(strcmp(msg,"end") == 0)
            {
                exit(0);
            }

            for(i=0; i < strlen(msg); i++)
            {
                msg[i] = toupper(msg[i]);
            }

            fprintf(stdout,"La stringa vale: %s\n",msg);
            fflush(stdout);

            sleep(1);
            kill(senderPID,SIGUSR1);
        }




    }else {

        forkedP = fork();
        if( forkedP == 0)
        {
            producer(forkedC);
        }
      
    }
    
    fprintf (stdout, "Sender   PID %d\n", forkedP);
    fprintf (stdout, "Receiver PID %d\n", forkedC);

    cpid = wait(&status);
    if (WIFEXITED(status)) {
        printf("Terminated PID %d  Status %d\n", cpid, WEXITSTATUS (status));
    }

    cpid = wait(&status);
    if (WIFEXITED(status)) {
        printf("Terminated PID %d  Status %d\n", cpid, WEXITSTATUS (status));
    }
    return 0;
}

void producer(pid_t forkedC)
{

    char msg[100];

    while(1)
    {
        FILE *fp=fopen(FILE_NAME,"w");

        if(fp == NULL)
        {
            fprintf(stdout,"errore");
            exit(0);
        }
        fprintf(stdout,"inserisci string: ");
        fflush (stdout);

        scanf("%s", msg);

        fprintf(fp,"%d %s",getpid(),msg);  
        fclose(fp); 
    
        kill(forkedC,SIGUSR1);

        if(strcmp(msg,"end") == 0)
        {
            break;
        }
    
        pause();

    }

    exit(0);



}