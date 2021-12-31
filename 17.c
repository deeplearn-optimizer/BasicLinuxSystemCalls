/*Write a program to simulate online ticket reservation.  Implement write lock  Write a program to open a file, store a ticket number and exit.  Write a separate program, to 
open the file, implement write lock, read the ticket number, increment the number and print 
the new ticket number then close the file.*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

struct Node{
	int train;
	int price;
};

void read_data(int fd){
	struct flock lock;
	lock.l_type = F_RDLCK;
	lock.l_whence = SEEK_SET;
	int record = 0;
	
	printf("Enter the record to lock\n");
	scanf("%d", &record);
	if(record > 3 || record < 1){
		printf("please enter a valid record\n");
		return;
	}
	
	struct Node temp;
	lock.l_start = (record - 1)*sizeof(temp);
	lock.l_len = sizeof(temp);
	lock.l_pid = getpid();
	
	
	printf("Please wait\n");
	fcntl(fd,F_SETLKW,&lock);
	
	printf("Aquired lock\n");
	
	lseek(fd, lock.l_start, SEEK_SET);
	read(fd, &temp, sizeof(temp));
	printf("Following are the details\n");
	printf("______________________\n");
	printf("| Train  number | %d |\n", temp.train);
	printf("______________________\n");
	printf("| Ticket number | %d |\n",temp.price);
	printf("______________________\n");
	lseek(fd, 0L, SEEK_SET);
	lock.l_type = F_UNLCK;
	fcntl(fd, F_SETLK, &lock);
	char y;
	printf("\nPress Y ");
	scanf("%c", &y);
	printf("\nTransaction completed, Thank you [:-)] \n");
	printf("Transaction completed!");
	return;
}

void write_data(int fd){
	struct flock lock;
	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_SET;
	int record;
	
	printf("Enter the record to lock\n");
	scanf("%d", &record);
	if(record > 3 || record < 1){
		printf("please enter a valid record\n");
		return;
	}
	
	struct Node temp;
	lock.l_start = (record - 1)*sizeof(temp);
	lock.l_len = sizeof(temp);
	lock.l_pid = getpid();
	
	printf("Please wait\n");
	fcntl(fd,F_SETLKW,&lock);
	printf("Aquired lock\n");
	
	lseek(fd, lock.l_start, SEEK_SET);
	printf("Enter train number please : ");
	scanf("%d", &(temp.train));
	printf("Enter ticket face please : ");
	scanf("%d", &(temp.price));
	
	write(fd, &temp, sizeof(temp));
	lseek(fd, 0L, SEEK_SET);
	
	lock.l_type = F_UNLCK;
	fcntl(fd, F_SETLK, &lock);
	
	char y;
	printf("\nPress Y ");
	scanf("%c", &y);
	printf("\nTransaction completed, Thank you [:-)] \n");
	return;
	
	
}

int main()
{	
	printf("WELCOME to UNIX ticket booking system\n");
	char * file_name = (char *)malloc(100);
	printf("Please enter file name\n");
	scanf("%s", file_name);
	int fd = open(file_name, O_RDWR);
	if(fd == -1){
		printf("file cannot be opened\n");
		return 0;
	}
	printf("\nALL SET LETS START!\n");
	
	while(1){
		int choice;
		printf("\nEnter choice : 1 for read, 2 for write and 3 for quit : ");
		scanf("%d", &choice);
		if(choice == 1){
			read_data(fd);		
		}
		else if(choice == 2){
			write_data(fd);
		}
		else{
			printf("BYE BYE!");		
			return 0;
		}	
	}
	return 0;
}
