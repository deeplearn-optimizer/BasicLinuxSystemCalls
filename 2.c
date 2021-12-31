/*Write a simple program to execute in an infinite loop at the background. Go to /proc directory and 
identify all the process related information in the corresponding proc directory.  */


#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

void main()
{
	printf("open proc fd to see info!");
	int pid = getpid();
	printf(" Following is the pid %d ", pid);
	getchar();
}
