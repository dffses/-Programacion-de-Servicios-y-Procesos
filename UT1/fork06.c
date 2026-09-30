#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>


void main(){
    pid_t  p_p1,p_p2,p_p3;

    p_p2=fork();
    if(p_p2==-1){
        printf("Error al crear el proceso p2");
    exit(-1);
    }
    if(p_p2==0){
        sleep(10);
        printf("Soy el proceso p2 Despierto\n");
        
    }else
    {
        wait(NULL);
         p_p3=fork();
    if(p_p3==-1){
        printf("Error al crear el proceso p3");
        exit(-1);
    }
    if(p_p3==0){
        p_p3=getpid();
        p_p1=getppid();
        printf("Soy el proceso p3 y mi pid es: %d y el pid de mi padre es: %d\n",p_p3,p_p1 );
        
    }else
    {
        wait(NULL);
        printf("Soy el padre y he terminado de esperar\n");
    
    }
        }

}
