#include "read.h"
#include <malloc.h>



int main(int argc, char *argv[])  // name of file with instruction // first string after name of program
{
	int *status; 
	char program[MAXLEN];
	float *delay = (float *)malloc(sizeof(float));

	FILE *input = fopen(argv[1], "r");  
	assert(input != NULL);
	

	

	while (read_f(input, program, delay) != 0)
	{
		int pid = fork();
		
		if (pid == -1) 
		{
			perror("Fork returned -1, process was not created\n");
		}
		else
		{
			if (pid == 0) //Doughter process
			{
				sleep(delay[0]);
				execve(program, NULL, NULL);
				perror("Program was not executed\n");
			}
			else  //Parent process
			{
				//return to fork
			}
		}
	}
	
	waitpid(-1, status, 0);


	return 0;
}
	
