#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <fcntl.h>


int main (int argc, char *argv[])
{
  FILE *file =NULL;
  int i =0;
	char text [1000] ={0};  
	double time =0;      
	pid_t pid =0;
	int *state =NULL;
	if (argc <2) 
	{
		printf ("Error: file name");
		return 0;
	}
	file =fopen (argv[1], "r");
	if (file ==NULL)
		perror ("Error: open file");
	while (fscanf (file, "%s", text) !=EOF)
	{
		for (i =0; text[i] !=';'; i++);
		text[i] =0;
		sscanf (&(text[i+1]), "%lg", &time);
		pid =fork();
		if (pid ==0)
		{
			usleep (time);
			execlp (text, text, NULL);
			return 0;	
		}
	}
	waitpid (-1, NULL, 0);
	fclose (file);
	return 0;
}
