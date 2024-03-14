#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>


int main(int argc, char **argv)
{
    int fileToRead = open(argv[1],O_RDONLY);
    int fileToWrite = open(argv[2],O_CREAT | O_WRONLY | S_IRUSR | S_IWUSR);

    char buff[300];
    int count;

    if(fileToRead == -1 || fileToWrite == -1)
    {
        printf("error");
        return -1;
    }

    while(( count = read(fileToRead,buff,300) ) > 0)
    {
        write(fileToWrite,buff,count);
    }

    close(fileToRead);
    close(fileToWrite);
    return 0;
}