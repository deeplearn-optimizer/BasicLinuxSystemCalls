/*Write a program to execute ls -Rl by the following system calls  a. execl  b. execlp  c. execle d. execv  e. execvp*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{
	char * binaryPath = "/bin/ls";
	char * arg1 = "-lh";
	char * arg2 = ".";
	char *args[] = {binaryPath, "-rl", ".",NULL};
	char *args2[] = {"ls", "-rl", ".",NULL};
	
	execl(binaryPath, arg1, arg2, NULL);
	execlp("ls","ls","-rl",".",NULL);
	execv(binaryPath,args);
	execvp("ls", args2);
	execle(binaryPath, binaryPath, "-rl", ".",NULL, NULL);
	return 0;
}
