/*
A shared global variable used by processes 
*/

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int a;
int childCount = 0;

int main() {
    int pid;

    for(int i=0; i<10; i++){
    // while(1){
        pid = fork();
        if(pid == -1) break;
        if(pid == 0){
            // childCount++;
            printf("Child created\n");
        }
        else printf("Pid=%d\n",pid);
        sleep(1);
    }
    // printf("\n\n===============\n");
    // printf("Child count = %d\n", childCount);
    return 0;
}