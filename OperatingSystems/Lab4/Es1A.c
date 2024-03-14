#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main (int argc,char **argv) {
    //  ./Es1 < inFile.txt
    //  ./Es1 < inFile.txt 1> evenFile.txt 2>oddFile.txt
    int numb=1;
    while(numb != 0)
    {
        fscanf(stdin,"%d",&numb);
        if(numb % 2 == 0)
        {
            fprintf(stdout,"%d è pari\n",numb);
        }else {
            fprintf(stderr,"%d è dispari\n",numb);
        }
    }
    // ls | wc -c --> B1
    // cat lab01e01.txt | wc -w  --> B2
    // ps -Uroot | wc -l 


    return 0;
}