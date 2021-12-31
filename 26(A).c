#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(int argc, char **argv){
	printf("Following are the arguments passed!\n");
	for(int i=0;i<argc;i++){
		printf("%s",argv[i]);
		printf("\n");
	}
	return 0;
}
