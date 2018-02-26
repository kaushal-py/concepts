/*
Make two workers using fork 
*/

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int a;
int childCount = 0;

int main() {
    int pid;
    pid = fork();

    if(pid == 0){
        for(int i=0; i<10000000; i++){
            printf("%d\n", i);
        }
    }
    else{
        for(int i=0; i<10000000; i++){
            printf("%d\n", i);
        }        
    }    
    return 0;
}