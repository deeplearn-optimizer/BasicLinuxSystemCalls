/*Write a program to create three child processes. The parent should wait for a particular child (use 
waitpid system call).*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>

int main(){
	printf("Enter the size of arguments!\n");
	int size = 0;
	scanf("%d", &size);
	char ** args = (char **)malloc((size+1) * sizeof(char *));
	for(int i = 0;i<size;i++)
	{
		char * word = (char *)malloc(20);
		printf("ennter %d argument with max length of 20 : ",(i+1));
		scanf("%s", word);
		args[i] = word;
	}
	args[size] = NULL;
	printf("calling the other program!\n");
	execv("./final", args);			
	return 0;
}

