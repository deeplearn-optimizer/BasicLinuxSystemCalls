
//Write a program to display the environmental variable of the user (use environ). 
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

extern char **environ;
int main()
{
	char **s = environ;
	for(;*s;s++)
		printf("%s\n", *s);
	return 0;
}
