#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define BUFFER_SIZE 50

int main() {
    pid_t pid;
    int fd[2];
    
    
    char *mensaje[] = {"27", "45", "6", "+"};
    int num_elementos = sizeof(mensaje) / sizeof(mensaje[0]);

  
        pid = fork();

        if (pid == 0) {
          
            close(fd[1]); 
            
            int suma = 0;
            char buffer[BUFFER_SIZE];
            int bytes_leidos;

            
            for (int i = 0; i < num_elementos; i++) {
               
                memset(buffer, 0, sizeof(buffer));
                
                
                bytes_leidos = read(fd[0], buffer, sizeof(buffer) - 1);

                if (bytes_leidos > 0) {
                  
                    if (strcmp(buffer, "+") == 0) {
                        printf("Simbolo recibido: %s\n", buffer);
                        printf("Suma total es: %d\n", suma);
                    } else {
                        printf("Numero recibido para sumar: %s\n", buffer);
                      
                        suma += atoi(buffer);
                    }
                }
            }

            

        } else if (pid > 0) {
            
            close(fd[0]);

           
            for (int i = 0; i < num_elementos; i++) {
                write(fd[1], mensaje[i], strlen(mensaje[i]) + 1);
             
                sleep(10);
            }

            wait(NULL); 
        }
    
}
