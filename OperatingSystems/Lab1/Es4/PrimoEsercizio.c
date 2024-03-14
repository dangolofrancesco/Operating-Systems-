#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv)
{
    FILE *fileRead = fopen(argv[1],"r");
    FILE *fileToWrite = fopen(argv[2],"w+");
    char line1[300];
    if(fileRead == NULL || fileToWrite == NULL)
    {
        printf("Error");
        return -1;
    }

    while(fgets(line1,300,fileRead) != NULL)
    {
        fprintf(fileToWrite,"%s",line1);
    }

    fclose(fileRead);
    fclose(fileToWrite);


    return 0;
}