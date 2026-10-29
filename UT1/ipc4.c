#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <time.h>

int main(){

    int pipe1[2];
    int pipe2[2];

    pipe(pipe1);
    pipe(pipe2);

    if (fork() == 0) {
        
        int num;
        int fact = 1;
        int i;

        
        read(pipe1[0], &num, sizeof(int));

        
        for (i = 1; i <= num; i++) {
            fact = fact * i;
        }

        
        write(pipe2[1], &fact, sizeof(int));

    } else {
      
        int numero;
        int resultado;

        time_t t;
        srand((unsigned) time(&t));
        numero = rand() % 11;

        printf("El proceso padre genera el numero %d en el pipe1\n", numero);

        // Enviar número al hijo
        write(pipe1[1], &numero, sizeof(int));

        // Leer resultado del hijo
        read(pipe2[0], &resultado, sizeof(int));

        printf("El factorial calculado por el proceso hijo: %d! = %d\n", numero, resultado);

        wait(NULL);
    }
}
