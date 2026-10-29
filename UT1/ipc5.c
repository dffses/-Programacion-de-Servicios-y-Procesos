#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int pipe1[2];
    int pipe2[2];

    pipe(pipe1);
    pipe(pipe2);

    if (fork() == 0) {
        
        int dni;
        char letra_recibida;

        
        printf("Introduce el número de tu DNI: ");
        scanf("%d", &dni);

       
        write(pipe1[1], &dni, sizeof(int));

      
        read(pipe2[0], &letra_recibida, sizeof(char));

        
        printf("la letra del NIF es %c\n", letra_recibida);

    } else {
        
        int dni_recibido;
        
        char letra[] = "TRWAGMYFPDXBNJZSQVHLCKE";

      
        read(pipe1[0], &dni_recibido, sizeof(int));

        
        dni_recibido %= 23;
        char letra_calculada = letra[dni_recibido];

        
        write(pipe2[1], &letra_calculada, sizeof(char));

        wait(NULL);
    }
}
