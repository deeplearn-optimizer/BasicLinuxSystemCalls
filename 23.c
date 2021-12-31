/* Write a program to create a Zombie state of the running program. */

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>

int main()
{
	if(!fork()){
		printf("Killing the child process\n");
		exit(0);
	}
	else{
		sleep(10);
		printf("Parent process now is alive");
	}
	return 0;
}
