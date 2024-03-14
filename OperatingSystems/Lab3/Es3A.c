#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main (int argc,char **argv) {
  int i = 0,c=0;
  char buff[500];
  char commandToExecute[500];
  int numByteRead;
 
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
            if(buff[i] != '\n')
            {
                commandToExecute[c++] = buff[i];
            }else {
                commandToExecute[c] = '\0';
                fprintf(stdout,"Command executed: %s\n",commandToExecute);
                
                sleep(3);
                system(commandToExecute);
                c = 0;
            }
        }
    }

    close(fileToRead);
  return (0);
} 