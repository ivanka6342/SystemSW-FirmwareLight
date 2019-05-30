#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

#define SEND_TELEMETRY_PERIOD_SEC 3
#define ARG_SIZE 6

char *arg_arr[] = {"usercpu", "syscpu", "idlecpu", "usedram", "totalMem", "net"};
const char *script_name = "./example.sh";

void my_delay (unsigned int sec)
{
        clock_t temp = clock() + sec*CLOCKS_PER_SEC;
        while (clock() < temp);
}

int main(){
    int pipe_fd[2]; // [0] - write to pipe(for child) // [1] - read from pipe(for parent)
    while(-1 == pipe(pipe_fd));
    pid_t cpid;

    while(1){
        my_delay(SEND_TELEMETRY_PERIOD_SEC);

        for (int i = 0; i < ARG_SIZE; i++){
            cpid = fork();

        // error        
            if (cpid < 0){
                (void)printf("Process creation failed: fork\n");
                close(pipe_fd[0]);
                close(pipe_fd[1]);
                break;
            }
        // child part
            else if (cpid == 0){
                close(pipe_fd[1]); // close unused host-read end
                dup2(STDOUT_FILENO, pipe_fd[0]);

                execl(script_name, script_name, arg_arr[i], NULL);
            }   
        // host part
            else {
                close(pipe_fd[0]); // Close unused child-write end
                
                (void)printf("parent proc\n");
                //wait(NULL);

                char buff[20];
                size_t nbytes = sizeof(buff);
                ssize_t bytes_read;
            
                bytes_read = read(pipe_fd[0], buff, nbytes);

                (void)printf("parent get string: %s\n", buff);
            }
        }
    }
    return 0;
}
