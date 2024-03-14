#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>

int main (int argc,char **argv) {
  pid_t pid;  
  int i = 0,c=0,num_par=0;
  char buff[500];
  char **v;
  char commandToExecute[500];
  int numByteRead;
 
  //AL MASSIMO 1 COMANDO CON 98 PARAMETRI
  v = (char **)malloc(100 * sizeof( char *) );

  setbuf(stdout,0);

  int fileToRead = open(argv[1],O_RDONLY);

    if(fileToRead == -1)
    {
        fprintf(stdout,"error file not found");
        return -1;
    }
    while(( numByteRead = read(fileToRead,buff,500) ) > 0)
    {
        for(i=0; i < numByteRead; i++)
        {
            if(buff[i] != ' ' && buff[i] != '\n')
            {
                commandToExecute[c++] = buff[i];
            }else{
                commandToExecute[c] = '\0';
                v[num_par]= (char *) malloc( c * sizeof(char));

                strcpy(v[num_par],commandToExecute);
                num_par++;

                c = 0;
            }

            if(buff[i] == '\n')
            {
                v[num_par] = NULL;
                if((pid = fork()) == 0)
                {
                    fprintf(stdout,"Command executed: %s\n",v[0]);
                    execvp(v[0],v);
                }

                for(int b=0; b < num_par; b++)
                {
                    free(v[b]);
                }

                waitpid(pid,NULL,0);

                num_par=0;                
            }
        }
    }

    close(fileToRead);
  return (0);
} 