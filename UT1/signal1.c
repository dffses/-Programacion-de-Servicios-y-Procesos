#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

void designar_fecha(int signum){
    time_t tiempo=time(NULL);
    struct tm*fecha= localtime(&tiempo);
    char texto_fecha[30];
    strftime(texto_fecha, sizeof(texto_fecha), "%d/%m/%Y %H:%M:%S", fecha);
    printf("Fin del proceso %d: %s\n",getpid(), texto_fecha);
}

int main(){
 time_t tiempo=time(NULL);
    struct tm*fecha= localtime(&tiempo);
    char texto_fecha[30];
    strftime(texto_fecha, sizeof(texto_fecha), "%d/%m/%Y %H:%M:%S", fecha);

    signal(SIGINT, designar_fecha);
    pid_t pid =getpid();
    

    printf("Inicio del proceso %d: %s\n", pid, texto_fecha);

    pause();
}
