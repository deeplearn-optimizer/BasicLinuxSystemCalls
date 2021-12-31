/*Write a program to find the type of a file.    
a. Input should be taken from command line.    
b. program should be able to identify any type of a file. 
*/

#include <stdio.h> 
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h> 
#include <sys/stat.h> 

int main(int argc, char ** argv){

	if(argc == 1){
		printf("please enter the filename in command line!\n");
		return 0;
	}
	int fd = open(argv[1], O_RDWR);
	if(fd == -1){
		printf("file does not exist!");
		return 0;
	}
	struct stat st;
	fstat(fd,&st);
	if(S_ISDIR(st.st_mode)){
		printf("the file is a directory");
	}
	else if(S_ISLNK(st.st_mode)){
		printf("the file is a link file");
	}
	else if(S_ISFIFO(st.st_mode)){
		printf("the file is a fifo file");
	}
	else if(S_ISBLK(st.st_mode)){
		printf("the file is a block device file");
	}
	else if(S_ISCHR(st.st_mode)){
		printf("the file is a char device file");
	}
	else if(S_ISREG(st.st_mode)){
		printf("the file is a normal file");
	}
	else{
		printf("the file is a socket file");
	}
	return 0;
}
