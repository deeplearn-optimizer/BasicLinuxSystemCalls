//Write a program to copy file1 into file2 

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(){
	char * file1,* file2;
	file1 = (char *)malloc(20);
	file2 = (char *)malloc(20);
	struct stat st;
	printf("please enter file name 1\n");
	scanf("%s", file1);
	
	
	int fd1 = open(file1, O_RDWR);
	if(fd1 == -1){
		printf("File not created!\n");
		fd1 = creat(file1, 0777);
		int size;
		printf("Please enter the size of file!\n");
		scanf("%d", &size);
		char * buffer = (char *) malloc(size);
		printf("Please enter the data\n");
		scanf("%s", buffer);
		write(fd1, buffer, size);
		getchar();	
	}
	
	fd1 = open(file1, O_RDWR);
	fstat(fd1, &st);
	int size = (int)st.st_size;
	printf("the file size is %ld\n", st.st_size);
	
	char * buffer = (char *)malloc(size);
	read(fd1, buffer, size);
	printf("data is %s\n", buffer);
	
	printf("please enter file name 2\n");
	scanf("%s", file2);
	int fd2 = open(file2, O_RDWR|O_CREAT,0777);
	if(fd2 == -1){
		printf("the file cannot be written!");
		return 0;
	}
	
	write(fd2,buffer,size);
	printf("done!");
	return 0;
}
