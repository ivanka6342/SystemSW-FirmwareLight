#include <stdio.h>     // printf()
#include <stdlib.h>    // size_t, NULL
#include <unistd.h>    // processes & pipes
#include <sys/types.h> // different data types
#include <string.h>    // 
#include <sys/wait.h>  // child proc exit status
#include <time.h>      // clock()

#define SEND_TELEMETRY_PERIOD_SEC 3
#define ARG_SIZE 6
char *argArr[] = {"usercpu", "syscpu", "idlecpu", "usedram", "totalMem", "net"};
const char *scriptName = "./example.sh";

void my_delay (unsigned int Sec)
{
       clock_t ticks1 = clock(), ticks2 = ticks1;
       while ( ( ticks2/CLOCKS_PER_SEC - ticks1/CLOCKS_PER_SEC ) < Sec)
           ticks2 = clock();
}

// мб мьютексы вставить для синхрона очередности этих процессов
int main(){
    int childToHostPipeFD[2]; // 0 - write // 1 - read
    pid_t cpid;
    // mb create pid_t childPid and save to it from "else if (cpid == 0){"

    while(1){
        if (pipe(childToHostPipeFD) == -1)
            continue;

        printf("\n");
        my_delay(SEND_TELEMETRY_PERIOD_SEC);

        for (int i = 0; i < ARG_SIZE; i++){
            cpid = fork();

            // error        
            if (cpid < 0){
                printf("Process creation failed: fork\n");
                close(childToHostPipeFD[0]);
                close(childToHostPipeFD[1]);
                break;
            }

            // FILE *file = fdopen(fd, "w");
            // stdout descriptor = fileno(stdout) = 1
            // childToHostPipeFD[0], childToHostPipeFD[1] = 3, 4
            // child part
            else if (cpid == 0){
                close(childToHostPipeFD[1]); // close unused host-read end
                
                write(childToHostPipeFD[0], "123456789", 10);
                execl(scriptName, scriptName, argArr[i], NULL);
            }

            // host part
            else {
                close(childToHostPipeFD[0]); /* Close unused child-write end */
                
                printf("parent proc\n");
                wait(NULL);                  // Wait for child 

                char buff[10];
                size_t nbytes = sizeof(buff);
                ssize_t bytes_read;
            
                bytes_read = read(childToHostPipeFD[1], buff, nbytes);

                printf("parent get string: %s\n", buff);
            }
        }
    }

    return 0;
}
