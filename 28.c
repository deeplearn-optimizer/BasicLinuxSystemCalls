//Write a program to get maximum and minimum real time priority. 

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sched.h>

int main(){

	int mini = sched_get_priority_min(SCHED_RR);
	int maxi = sched_get_priority_max(SCHED_FIFO);
	printf("The minimum real time priority is %d\n", mini);
	printf("The maximum real time priority is %d\n", maxi);
	return 0;
}
