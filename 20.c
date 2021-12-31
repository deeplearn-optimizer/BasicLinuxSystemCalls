/*Find out the priority of your running program. Modify the priority with nice command. */

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<sched.h>
#include<sys/time.h>
#include<sys/resource.h>


int main()
{
	pid_t id = getpid();
	int pr = getpriority(PRIO_PROCESS, id);
	printf("The priority of the process is : %d\n", pr);
	label:
	printf("Enter the process priority to set : ");
	scanf("%d", &pr);
	if((pr < -19) || (pr > 20)){
		printf("Please enter a valid priority in range -20 to 19\n");
		goto label;
	}
	int ans = setpriority(PRIO_PROCESS, id, pr);
	if(ans == 0)
		printf("process priority updated successfully \n");
	else
		printf("cannot set the process priority : ");
	return 0;	
}


