#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(){
    int pipe2;
    int num;
    int factorial=1;
    int x;

    pipe2=open("PIPE02", O_RDONLY);
    read(pipe2,&num, sizeof(int));
    close(pipe2);

    for(x=1;x<=num;x++){
        factorial=factorial*x;
    }
    pipe2=open("PIPE02",O_WRONLY);
    write(pipe2,&factorial,sizeof(int));
    close(pipe2);
}
