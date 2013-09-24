#include <stdio.h>	/* printf */
#include <sys/wait.h>	/* waitpid */
#include <errno.h>	/* perror */
#include <sys/types.h>	/* fork */
#include <unistd.h>	/* fork */
#include <assert.h>     /*assert*/
#include <stdlib.h>     /*atof*/



const int MAXLEN = 1000;

int read_f(FILE *input, char *program, float *delay)
{
	assert(input != NULL);
	assert(program != NULL);
	assert(delay != NULL);

	
	char buf[MAXLEN];
	char time[MAXLEN];
	float time_c;

	if (fgets(buf, MAXLEN, input) != 0)
	{
		
		int i = 0;
		while (buf[i] != ';')
		{
			program[i] = buf[i];
			i++;
		}
		program[i] = '\0';
		i++;

		int j = 0;
		while ((buf[i] != '\0') && (buf[i] != '\n'))
		{
			time[j] = buf[i];
			i++;
			j++;
		}
		time[j] = '\0';


		time_c = atof(time);
		delay[1] = time_c;

		return 1;
	}

	else
	{
		return 0;
	}
}
