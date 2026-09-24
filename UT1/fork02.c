#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>


void main(){
    pid_t pid, pid_hijo, pid_padre;
    pid_hijo=getpid();
    pid =fork();

      if (pid==-1)
    {
        printf("Error");
        exit(-1);
    }
    if (pid==0)
    {

        pid_hijo=getpid();
        pid_padre=getppid();
        printf ("Soy el hijo y mi nombre es IAN NARANJO CAIZA\n");
        sleep(5);

    }else{
        wait(NULL);
        pid_padre=getpid();

        printf("MI hijo tiene el pid: %d\n",pid_hijo);
        printf("Soy el padre y tengo el pid: %d\n",pid_padre);


    }
    exit(0);
}
