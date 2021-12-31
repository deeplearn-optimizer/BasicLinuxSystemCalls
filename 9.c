/*Write a program to print the following information about a given file.
   a. inode
   b. number of hard links 
   c. uid    
   d. gid    
   e. size    
   f. block size    
   g. number of blocks    
   h. time of last access    
   i. time of last modification    
   j. time of last change
    */
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h> 
#include<stdlib.h>
#include<sys/types.h> 
#include<sys/stat.h>
#include<fcntl.h>
int main()
{	
	struct stat st;
	char * file = (char *)malloc(100);
	struct timespec * ts;
	printf("enter the file name\n");
	scanf("%s", file);
	int fd = open(file, O_RDWR);
	if(fd == -1)
		printf("file cannot be opened!");
	else{
		fstat(fd, &st);
		printf(": Inode number : %ld\n", st.st_ino);
		printf(": Nunber of hard blocks %ld\n", st.st_nlink);
		printf(": Number of uid %d\n", st.st_uid);
		printf(": Number of gid %d\n", st.st_gid);
		printf(": size of file %ld\n", st.st_size);
		printf(": size of file %ld\n", st.st_blocks);
		
		ts = &st.st_mtim;
		printf(": last modification time %lld.%.9ld\n", (long long)ts->tv_sec, ts->tv_nsec);
		
		ts = &st.st_ctim;
		printf("last access time %lld.%.9ld\n", (long long)ts->tv_sec, ts->tv_nsec);
		
	}
	return 0;
}
