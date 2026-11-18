#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

void tiempo_pasado(int signum){
      time_t tiempo=time(NULL);
    struct tm*fecha= localtime(&tiempo);
    char texto_fecha[30];
    strftime(texto_fecha, sizeof(texto_fecha), "%d/%m/%Y %H:%M:%S", fecha);
    printf("Señal de alarma recibida: %s\n", texto_fecha);
}

int main(){
int veces=0;
int segundos=0;

printf("¿Cuantas veces sonara la alarma?:\n");
scanf("%d",&veces);
printf("¿Cada cuantos segundos se repetira la alarma?:\n");
scanf("%d",&segundos);

signal(SIGALRM,tiempo_pasado);

printf("Alarma activada\n");

for (size_t i = 0; i < veces; i++)
{
    alarm(segundos);
    pause();
}
printf("Alarma desactivada\n");


}
