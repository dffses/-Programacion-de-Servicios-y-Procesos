#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

//Existen 2 procesos uno padre y otro hijo


//El proceso padre ejecuta el print Inicio, uno despues del fork, el de soy el padre y el de Fin
//El proceso hijo ejecuta uno despues del fork, soy el hijo y el fin


// La frase de Inicio aparece 1 vez  por el padre
//La frase de Despues del fork sale 2 veces una del padre y otra del hijo
//Soy el hijo 1 vez por el hijo
//Soy el padre 1 vez por el padre
//Fin aparece 2 veces una por el padre y otra por el hijo



void main(){


    printf("Inicio\n");

pid_t pid = fork();

printf("Después del fork\n");

if (pid == 0) {

 printf("Soy el hijo\n");

} else {

 printf("Soy el padre\n");

}

printf("Fin\n");


}
