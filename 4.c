//Write a program to open an existing file with read write mode. Try O_EXCL flag also. 

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main()
{
	int fd = open("example_file.txt", O_CREAT|O_EXCL|O_RDWR, 0777);
	if(fd == -1)
		printf("the file is not created!");
	else
		printf("the file is created!");
	getchar();
	return 0;
}
