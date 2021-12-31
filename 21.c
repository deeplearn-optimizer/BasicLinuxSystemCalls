// Write a program, call fork and print the parent and child process id. 

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	if(!fork())
		printf("The child process id is : %d\n", getpid());	
	
	else
		printf("The parent process id is : %d\n", getpid());	
	return 0;
	
}
