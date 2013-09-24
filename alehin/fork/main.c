#include "read.h"
#include <malloc.h>


int main()
{
	int pid;
	int *status; 
	char program[MAXLEN];
	float *delay = (float *)malloc(sizeof(float));

	FILE *input = fopen("instruction", "r");
	assert(input != NULL);
	

	

	while (read_f(input, program, delay) != 0)
	{
		pid = fork();
		
		if (pid == -1) 
		{
			perror("Fork returned -1, process was not created\n");
		}
		else
		{
			if (pid == 0) //Doughter process
			{
				sleep(delay[1]);
				execve(program, NULL, NULL);
				perror("Program was not executed\n");
			}
			else  //Parent process
			{
				
			}
		}
	}
	
	waitpid(-1, status, 0);


	return 0;
}
	
