#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>


void main(){

    pid_t p2,p3,p_padre;

    p2=fork();

    if(p2==0){
        p2=getpid();
        p_padre=getppid();
        printf("Soy el proceso P2 y mi pid es: %d\n",p2);
        printf("Y yo soy su padre y mi pid es: %d\n",p_padre);
        sleep(3);
        exit(0);
    }

    p3=fork(); 

    if(p3==0){
        p3=getpid();
        p_padre=getppid();
        printf("Soy el proceso P3 y mi pid es: %d\n",p3);
        printf("Y yo soy su padre y mi pid es: %d\n",p_padre);
        sleep(1);
        exit(0);
    }

    wait(NULL);
    wait(NULL);

    printf("Todos mis hijos han terminado\n");
    printf("Soy el padre y mi pid es: %d\n",getpid());
    printf("Soy el proceso hijo p2 y mi pid es: %d\n",p2);
    printf("Soy el proceso hijo p3 y mi pid es: %d\n",p3);

}
