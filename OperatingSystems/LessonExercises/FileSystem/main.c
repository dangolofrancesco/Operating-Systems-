#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
int main(int argc, char **argv)
{
    char value[100];
    int file = open("test.txt", O_RDONLY);
    int i = 1;
    if(file == -1)
    {
        printf("error");
        return -1;
    }

    while(read(file,value,i) > 0)
    {
        i+=2;
        lseek(file,-1,SEEK_CUR);
        write(1,value,i);
    }
    
    return 0;
}
