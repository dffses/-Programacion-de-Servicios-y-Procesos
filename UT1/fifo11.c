#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>

int main() {
    int fifo1 , fifo2;
    int numero;
    int resultado;

    mkfifo("FIFO01", 0666);
    mkfifo("FIFO02", 0666);

    time_t t;
    srand((unsigned)time(&t));
    numero =rand()%11;

    printf("El proceso FIFO11 genera el numero %d en FIFO01\n",numero);

    fifo1 =open("FIFO01",O_WRONLY);
    write(fifo1, &numero, sizeof(int));
    close(fifo1);

    fifo2=open("FIFO02", O_RDONLY);
    read(fifo2, &resultado, sizeof(int));
    close(fifo2);

    printf("El factorial calculado por FIFO12 es: %d! = %d\n", numero, resultado);


}
