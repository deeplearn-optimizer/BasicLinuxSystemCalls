
/*Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to 
verify whether the data is available within 10 seconds or not (check in $man 2 select).*/

#include <stdio.h> 
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h> 
#include <sys/stat.h> 

int main()
{
	fd_set rdfs;
	struct timeval tv;
	int retval;
	
	FD_ZERO(&rdfs);
	FD_SET(0, &rdfs);
	
	tv.tv_sec = 10;
	tv.tv_usec = 0;
	
	retval = select(1, &rdfs, NULL, NULL, &tv);
	if(retval)
		printf("the data was available within 10 seconds!");
	else
		printf("the data was not available within 10 seconds!");
 
	return 0;
}
