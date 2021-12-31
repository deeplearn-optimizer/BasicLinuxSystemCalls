/*Write a program to create three child processes. The parent should wait for a particular child (use 
waitpid system call).*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h> 
#include<sys/wait.h>

int main(){
	pid_t arr[3] = {0};
	for(int i=0;i<3;i++){
		pid_t pid = fork();
		if(pid == 0){
			sleep(10 + i*2);
			exit(0);
		}
		arr[i] = pid;
	}
	
	for(int i=0;i<3;i++){
		int retval = 0;
		waitpid(arr[i], &retval, 0);
		printf("child process %d terminated\n", arr[i]);
	}
	
	printf("Done, all processes terminated!\n");
	return 0;
}
