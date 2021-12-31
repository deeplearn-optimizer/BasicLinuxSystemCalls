/*Write a program to perform mandatory locking.    
a. Implement write lock    
b. Implement read lock */

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main()
{
	struct flock lock;
	int fd;
	fd = open("db", O_RDWR|O_CREAT, 0777);
	lock.l_type = F_WRLCK;
	lock.l_start = 0;
	lock.l_len = 0;
	lock.l_pid = getpid();
	printf("Before entering into critical section!\n");
	fcntl(fd, F_SETLKW, &lock);
	printf("inside critical seciton");

	printf("unlocked!");
	lock.l_type = F_UNLCK;
	fcntl(fd, F_SETLK, &lock);
	
	lock.l_type = F_RDLCK;
	fcntl(fd, F_SETLKW, &lock);
	printf("inside critical seciton");
	getchar();
	printf("unlocked!");
	lock.l_type = F_UNLCK;
	fcntl(fd, F_SETLK, &lock);
	getchar();
	printf("finish");
	return 0;
}
