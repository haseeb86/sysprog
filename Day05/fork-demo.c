#include <stdio.h>
#include <unistd.h>

int main()
{
	pid_t pid;

	//Clone
	
	if( (pid = fork()) > 0)  //Parent process
	{
		printf("This is printed from the context of Parent Process\n");
	}
	else    //Child Process
	{
		printf("This is printed from the context of child Process\n");
	}	

	return 0;
}
