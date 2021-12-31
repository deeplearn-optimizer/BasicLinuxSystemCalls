#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>

struct Node{
	int train;
	int price;
};
int main()
{
	char * file_name = (char *)malloc(100);
	printf("Enter the file name : ");
	scanf("%s", file_name);
	int fd = open(file_name, O_RDWR|O_CREAT, 0777);
	if(fd < 0){
		printf("file cannot be created please try again later\n");
		return 0;
	}
	for(int i = 0 ;i<3;i++){
		struct Node temp;
		printf("Enter train number please : ");
		scanf("%d", &(temp.train));
		printf("Enter ticket face please : ");
		scanf("%d", &(temp.price));
		write(fd, &temp, sizeof(temp));
	}
	return 0;
}
