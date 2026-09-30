#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>


void main(){

    pid_t p_p1, p_p2, p_p3;

    p_p2=fork();

   
    if(p_p2==0){
        p_p3=fork();
        p_p2=getpid();
       
        if (p_p3==0)
        {
            p_p2=getppid();
            p_p3=getpid();
            printf("Soy el proceso P3( y mi pid es: %d  y el pid de mi padre es: %d\n",p_p3,p_p2);
            
        }else
        {
        
        wait(NULL);
        printf("Soy el proceso P2 y mi pid es: %d  y el pid de mi padre es: %d\n",p_p2,getppid());
            
        }
        
    }
    else{
        wait(NULL);
        printf("Soy el proceso P1 y mi pid es: %d y el pid de mi hijo es: %d\n",getpid(),p_p2);

    }

}
