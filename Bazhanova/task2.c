#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

int main (int argc, char *argv[])
{
	char buf [100] = {0}; //buffer for commands in .cvs
	double time = 0;      //time delay
	int i = 0; 	      //smth counter
	pid_t pid = 0;
	int *state = NULL;
	FILE *file = NULL;
	if (argc < 2) 
	{
		printf ("Error: you don't enter the file name. Please, try again");
		return 0;
	}
	file = fopen (argv[1], "r");
	if (file == NULL)
		perror ("Can't open the file");
	while (fscanf (file, "%s", buf) != EOF)
	{
		for (i = 0; buf[i] != ';'; i++);
		buf[i] = 0;
		sscanf (&(buf[i+1]), "%lg", &time);
		pid = fork();
		if (pid == 0)
		{
			usleep (time);
			execlp (buf, buf, NULL);
			return 0;	
		}
	}
	waitpid (-1, state, 0);
	fclose (file);
	return 0;
}
