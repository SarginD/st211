
#include <errno.h>
#include <unistd.h>
#include <stdio.h>


int main(int argc, char *argv[])
{
	double delay=0;
	int i;
	char* point;
	char buffer[100]={0};
	pid_t *pid, array_pid[100] = {},*pid0;
	pid = array_pid;
	pid0 = pid;
	if (argc == 2)
	{
		FILE* file;
		file = fopen(argv[1],"r");
		while (fscanf(file,"%s",buffer) != EOF)
		{
			point = buffer;
			while (*(point) != ';')
			point++;
			*point = NULL;
			point++;
			sscanf(point,"%lg",&delay);
			*pid = fork();
			if (*pid == 0)
			{
				usleep(delay);
				execlp(buffer,buffer, NULL);
				return 0;
			}
			pid++;
		}
		fclose(file);
		int* status;
		while (pid0 != pid)
		{
			waitpid(*pid0,status,0);
			pid0++;
		}
		waitpid(*pid,status,0);
	}
	else perror ("bad");
	return (0);
}
