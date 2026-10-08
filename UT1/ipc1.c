#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int fd[2];
    char buffer[50];

    pid_t pid;

    pipe(fd);
    pid=fork();

    if(pid==0){
      
        close(fd[1]);
        printf("Soy el proceso hijo con pid:  %d \n", getpid());
        read(fd[0],buffer, 37);
        printf("\t Mensaje del padre: %s \n",buffer);
    }else
    {
        close(fd[0]);
        write(fd[1], "Fecha/hora: Mon Oct 10 18:38:39 2022", 37);  
        wait(NULL);    
    }
    
}
