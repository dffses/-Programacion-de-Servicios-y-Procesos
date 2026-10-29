#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main() {
    int fifo1, fifo2;
    int num;
    int factorial=1;
    int x;

    fifo1=open("FIFO01", O_RDONLY);
    read(fifo1, &num, sizeof(int));
    close(fifo1);

    for(x=1;x<=num;x++){
        factorial=factorial*x;
    }

    fifo2 = open("FIFO02", O_WRONLY);
    write(fifo2, &factorial, sizeof(int));
    close(fifo2);
}
