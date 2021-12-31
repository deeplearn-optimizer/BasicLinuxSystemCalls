/*Write a program to create an orphan process.*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h> 

int main()
{
	if(!fork()){
		printf("This is the child process with the parent process id = %d and id  = %d\n", getppid(), getpid());
		sleep(20);
		printf("Ok so this is the child process after sleep and my parent process id is %d\n", getppid());
		getchar();
	}
	else{
		printf("This is the parent process with id = %d and exiting!\n", getpid());
		exit(0);
	}
	
	return 0;
}
