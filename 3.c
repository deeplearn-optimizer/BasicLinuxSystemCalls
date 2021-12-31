//Write a program to create a file and print the file descriptor value. Use creat ( ) system call

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main()
{
	char * filename = (char *)malloc(100);
	printf("Please enter the file name : ");
	scanf("%s", filename);
	
	int fd = creat("example_file.txt", 0777);
	if(fd == -1)
		printf("the file is not created!");
	else
		printf("the file is created! and the fd value id %d\n", fd);
	getchar();
	return 0;
}
