/*Write a program to create five new files with infinite loop. Execute the program in the background 
and check the file descriptor table at /proc/pid/fd.*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void main()
{
	int nums;
	printf("Enter the number of files to create : ");
	scanf("%d", &nums);
	for(int i=0;i<nums;i++){
		char * filename = (char *)malloc(100);
		printf("Please enter the file %d name : ", (i+1));
		scanf("%s", filename);
		int fd = open(filename,O_CREAT|O_RDWR,0777);
		printf("Opened %s with file discripter value %d\n", filename, fd);
		free(filename);
	}
	printf("enter CTRL + C to stop the program!");
	while(1);
	
}
