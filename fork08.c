#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void main()
{
    pid_t pid1, pid2;
    
    printf("CCC \n");
    pid1 = fork();
    
    if (pid1 == 0)
    {
      
        printf("BBB \n");
    }
    else
    {
      
        pid2 = fork();
        
        if (pid2 == 0)
        {
          
            printf("AAA \n");
        }
        else
        {
            
            wait(NULL);
            wait(NULL);
        }
    }
    
    exit(0);
}



//       Proceso Padre
//        (PID 1000)
//       ╱          ╲
//      ╱            ╲
//  Hijo 1          Hijo 2
//(PID 1001)      (PID 1002)
