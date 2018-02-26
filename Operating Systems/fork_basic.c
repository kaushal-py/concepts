/*
Basic Program that runs a parent and a child process 
*/

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main() {
    
    printf("1. This line is only executed by the parent process\n");
    // make two process which run same
    // program after this instruction
    fork();

    printf("2. This statement is called after fork, so both parent and child execute this.\n");
 
    return 0;
}