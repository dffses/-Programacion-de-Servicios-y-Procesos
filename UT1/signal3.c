#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

void contar_salidas(int signum){
    time_t tiempo = time(NULL);
    struct tm *fecha = localtime(&tiempo);
    char texto_hora[20];
    strftime(texto_hora, sizeof(texto_hora), "%H:%M:%S", fecha);

    FILE *fichero = fopen("salidas.txt", "a");
    fprintf(fichero, "Señal SIGINT recibida a las %s\n", texto_hora);
    fclose(fichero);

}

int main(){
    signal(SIGINT, contar_salidas);
    while (1)
    {
        pause();
    }
    
}
