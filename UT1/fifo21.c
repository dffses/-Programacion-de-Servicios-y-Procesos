#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>

int main() {
    int pipe2;
    int numero;
    int resultado;

    mkfifo("PIPE02",0666);

    time_t t;
    srand((unsigned)time(&t));
    numero=rand()%11;

    printf("EL proceso FIFO21 genera el numero %d en PIPE02\n", numero);

    pipe2=open("PIPE02",O_WRONLY);
    write(pipe2,&numero,sizeof(int));
    close(pipe2);

    pipe2=open("PIPE02",O_RDONLY);
    read(pipe2,&resultado,sizeof(int));
    close(pipe2);

    printf("El factorial calculado por FIFO22 es: %d! = %d\n",numero, resultado);
}
