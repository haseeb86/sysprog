#include <stdio.h>
#include <unistd.h>


int GLOBAL1 = 10;
static int GLOBAL2 = 20;

int main()
{
	int local_process = 30;
	pid_t pid;

	if( (pid = fork()) > 0)  //Parent process
	{
		printf("Parent: initial value of GLOBAL1=%d\n", GLOBAL1);	
		printf("Parent: initial value of static GLOBAL2=%d\n", GLOBAL2);	
		printf("Parent: initial value of local var=%d\n", local_process);	
		GLOBAL1 = 11;
		GLOBAL2 = 21;
		local_process = 31;
		printf("Parent: modified value of GLOBAL1=%d\n", GLOBAL1);	
		printf("Parent: modified value of static GLOBAL2=%d\n", GLOBAL2);	
		printf("Parent: modified value of local var=%d\n", local_process);	
	}
	else    //Child Process
	{
		printf("child: initial value of GLOBAL1=%d\n", GLOBAL1);	
		printf("child: initial value of static GLOBAL2=%d\n", GLOBAL2);	
		printf("child: initial value of local var=%d\n", local_process);	
		GLOBAL1 = 15;
		GLOBAL2 = 25;
		local_process = 35;
		printf("child: modified value of GLOBAL1=%d\n", GLOBAL1);	
		printf("child: modified value of static GLOBAL2=%d\n", GLOBAL2);	
		printf("child: modified value of local var=%d\n", local_process);	
	}	

	sleep(1);
	return 0;
}
