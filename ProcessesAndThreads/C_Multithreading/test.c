#include <stdio.h>     // printf()
#include <stdlib.h>    // size_t, NULL
#include <unistd.h>    // processes & pipes
#include <sys/types.h> // different data types
#include <string.h>    // 
#include <sys/wait.h>  // child proc exit status
#include <time.h>      // clock()
#include <pthread.h>   // mutex // unused

int main(){
    int childToHostPipeFD[2]; // 0 - write // 1 - read
    (void)pipe(childToHostPipeFD);
    printf("parent \n");

    while(1){}         
    return 0;
}
