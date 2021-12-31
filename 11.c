/*
Write a program to open a file, duplicate the file descriptor and append the file with both the 
descriptors and check whether the file is updated properly or not.   
a. use dup    
b. use dup2    
c. use fcntl 
*/



#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
	char * filename = (char *)malloc(100);
	printf("enter the file name\n");
	scanf("%s", filename);
	int fd = open(filename, O_RDWR | O_CREAT, 0777);
	
	
	//using dup
	
	int fd2  = dup(fd);
	
	int size;
	printf("enter the buffer size\n");
	scanf("%d", &size);
	
	char * buffer = (char *)malloc(100);
	printf("enter the data to be written!\n");
	scanf("%s",buffer);
	
	write(fd2 , buffer, size);
	lseek(fd, 0L, SEEK_SET);
	
	char * buffer2 = (char *)malloc(100);
	read(fd2, buffer2, size);
	
	printf("%s", buffer2);	
	
	
	//using dup2
	
	int fd3 = dup2(fd,7);
	printf("the new fd is %d\n", fd3);
	
	char * buffer3 = (char *)malloc(size);
	lseek(fd3, 0L, SEEK_SET);
	read(fd3, buffer3, size);
	
	printf("DATA READ FROM FD 3 is %s\n", buffer3);
	
	
	//using fcntl
	
	int fd4 = fcntl(fd,F_DUPFD);
	printf("the new fd is %d\n", fd4);
	
	char * buffer4 = (char *)malloc(size);
	lseek(fd4, 0L, SEEK_SET);
	read(fd4, buffer4, size);
	
	printf("DATA READ FROM FD 4 is %s\n", buffer4);
		
	return 0;
}
