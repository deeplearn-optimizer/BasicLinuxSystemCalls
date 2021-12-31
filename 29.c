/*Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,  
SCHED_RR). */

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<sched.h>


int main()
{
	pid_t my_pid = getpid();
	char temp;
	int policy;
	printf("My process if is %d\n", my_pid);

	
	int s = sched_getscheduler(my_pid);
	switch(s){
		case SCHED_RR:
			printf("Round robin schedluling policy\n");
		break;
		case SCHED_FIFO:
			printf("FIFO scheduling policy\n");
		break;
		default:
			printf("Normal scheduling policy is being used!\n");
	}
	
	LABEL:
	printf("Enter the scheduling policy that you want to use 1 for FIFO and 2 for RR : ");
	scanf("%d", &policy);
	if(policy < 0 || policy > 2)
	{
		printf("please enter a valid scheduling policy!");
		goto LABEL;
	}
	
	struct sched_param param;
	printf("Enter the scheduling priority that you want to have for this process : ");
	scanf("%d", &(param.sched_priority));	
	s = (policy == 1)?SCHED_FIFO:SCHED_RR;
		
	if (sched_setscheduler(getpid(), s, &param) != 0) {
    		perror("sched_setscheduler");
		exit(EXIT_FAILURE);  
	}
	else
		printf("policy was updated!\n");
		
	sleep(10);
	return 0;	
}
