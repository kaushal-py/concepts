/*
A shared global variable used by processes 
*/

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int a;

int main() {

    a =10;

    printf("a=%d\n", a);    
    // make two process which run same
    // program after this instruction
    int pid = fork();
    a++;
    if(pid == 0) printf("== Child Process ==\n");
    else printf("== Parent Process ==\n");
    printf("a=%d\n", a);    
 
    return 0;
}