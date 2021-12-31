//Deamon process!

#include<unistd.h>
#include<sys/stat.h>
#include<stdio.h>
#include<stdlib.h>

int main(){

	if(!fork())
	{
		setsid();
		chdir("/");
		umask(0);
		while(1)
		{
			sleep(2);
			printf("Child Pid %d\n",getpid());
			printf("Daemon process running\n");
		
		}	
	}
	else
	exit(0);
}
