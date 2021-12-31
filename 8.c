/*Write a program to open a file in read only mode, read line by line and display each line as it is read. 
Close the file when end of file is reached.*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(){
	char * file = (char *)malloc(20); 
	printf("enter file name\n");
	scanf("%s", file);
	int fd1 = open(file,O_RDONLY);
	if(fd1 == -1)
		return 0;
	
	char temp;
        int index =0;
        char * buffer = (char *)malloc(1000);
        while(read(fd1, &temp, 1)>0)
                buffer[index++] = temp;
        write(1, buffer, index);
        return 0;
}
