#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(int argc, char ** argv){
	if(argc != 3){
		printf("Usage : ./a.out file1 file2\n");
		return 0;
	}
	int choice;
	printf("Enter 0 for soft link and 1 for hard link\n");
	scanf("%d", &choice);
	int ans = (choice)?link(argv[1], argv[2]):symlink(argv[1], argv[2]);
	if(ans==0)
		printf("Link file created successfully\n");
	else
		printf("Link file cannot be creted, please try again later.\n");
	return 0;
}
