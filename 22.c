/* Write a program, open a file, call fork, and then write to the file by both the child as well as the 
parent processes. Check output of the file. */

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h> 
#include<fcntl.h>
#include<string.h>
void operate(int fd, int p){
	struct flock lock;
	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 0;
	lock.l_pid = getpid();
	fcntl(fd, F_SETLKW, &lock);
	if(p == 0){
		char * data = "hello from child process \n";
		write(fd, data, strlen(data));
	}
	else{
		char * data = "hello from parent process \n";
		write(fd, data, strlen(data));
	}
	lock.l_type = F_UNLCK;
	fcntl(fd, F_SETLK, &lock);
}

int main()
{
	char * filename = (char *)malloc(100);
	printf("enter the file name : ");
	scanf("%s", filename);
	int fd = open(filename, O_RDWR | O_CREAT, 0777);
	if(!fork())
		operate(fd, 0);
	else{
		sleep(3);
		operate(fd, 1);
		struct stat st;
		fstat(fd, &st);
		lseek(fd, 0L, SEEK_SET);
		int size = (int)st.st_size;
		char * data = (char *)malloc(size);
		read(fd, data, size);
		printf("following is the data\n%s", data);
	}	
	return 0;
}
