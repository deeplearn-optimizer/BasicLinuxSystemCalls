/*
Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10 
bytes (use lseek) and write again 10 bytes.     
a. check the return value of lseek   
b. open the file with od and check the empty spaces in between the data
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

int main()
{	
	char * filename = (char *)malloc(100);
	char temp;
	printf("please enter the file name\n"); 
	scanf("%s", filename);		
	int fd = open(filename, O_RDWR|O_CREAT, 0777);
	if(fd == -1){
		printf("cannot open the file please review what happened!");
		return 0;
	}
	for(int i = 0;i<10;i++){
		temp = '1';
		write(fd, &temp, 1);
	}
	
	for(int i = 0;i<10;i++){
		temp = ' ';
		write(fd, &temp, 1);
	}
	
	for(int i = 0;i<10;i++){
		temp = '2';
		write(fd, &temp, 1);
	}
	
	lseek(fd, 0L, SEEK_SET);
	char * buffer = (char *)malloc(31);
	read(fd, buffer, 30);
	printf("\nThe file contents are : %s\n", buffer);
	
	return 0;
}
