#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <time.h>

#define BUFFER_SIZE 50

int main() {
    pid_t pid;
    int fd[2];

    
    pipe(fd);

    pid = fork();

    if (pid == 0) {
        
        close(fd[0]);

        
        srand(time(NULL));

      
        int n1 = (rand() % 50) + 1;
        int n2 = (rand() % 50) + 1;

        char buffer[BUFFER_SIZE];

      
        sprintf(buffer, "%d", n1);
        write(fd[1], buffer, strlen(buffer) + 1);

        
        s
        printf(buffer, "%d", n2);
        write(fd[1], buffer, strlen(buffer) + 1);

        close(fd[1]);

    } else if (pid > 0) {
        
        close(fd[1]); 

        char buffer[BUFFER_SIZE];
        int num1, num2;

       
        read(fd[0], buffer, sizeof(buffer));
        num1 = atoi(buffer);

       
        read(fd[0], buffer, sizeof(buffer));
        num2 = atoi(buffer);

        close(fd[0]);

      
        printf("%d+%d=%d\n", num1, num2, num1 + num2);
        printf("%d-%d=%d\n", num1, num2, num1 - num2);
        printf("%d*%d=%d\n", num1, num2, num1 * num2);
        printf("%d/%d=%d\n", num1, num2, num1 / num2);

        wait(NULL);
    }

    return 0;
}
