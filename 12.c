//Write a program to find out the opening mode of a file. Use fcntl. 
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h> 
#include<sys/types.h>
#include<sys/stat.h>

int main(){
	
	char * filename = (char *)malloc(20);
	printf("enter the file name!");
	scanf("%s",filename);
	
	int fd1 = open(filename, O_RDONLY);
	if(fd1 == -1){
		printf("cannot open file!");
		return 0;
	}
	int fd2 = open(filename, O_RDWR);
	int fd3 = open(filename, O_WRONLY);
	
	printf("0 for readonly, 1 for write only, 2 for read and write\n");
	printf("The file descripter %d is opened in %d mode\n", fd1, fcntl(fd1, F_GETFL)-32768);
	printf("The file descripter %d is opened in %d mode\n", fd2, fcntl(fd2, F_GETFL)-32768);
	printf("The file descripter %d is opened in %d mode\n", fd3, fcntl(fd3, F_GETFL)-32768);

	return 0;

}
