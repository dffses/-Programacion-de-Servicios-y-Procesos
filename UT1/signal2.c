#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
int segundos=0;
void terminar_proceso(int signum){
    
    segundos=segundos+5;
    printf("Han trascurrido %d segundos\n",segundos);
}

int main(){
    signal(SIGALRM, terminar_proceso);
    while (1){
        alarm(5);
        pause();
    }  

}
