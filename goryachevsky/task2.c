#include <stdio.h>
#include <errno.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
	double delay=0;
	int i;
	char* point;
	char buff[100]={0};
	pid_t *pid,*pid0, a_pid[100] = {};
	pid = a_pid;
	pid0 = pid;
	if (argc == 2)
	{
		FILE* file;
		file = fopen(argv[1],"r");
		while (fscanf(file,"%s",buff) != EOF)
		{
			point = buff;
			while (*(point) != ';')
			point++;
			*point = '\0';
			point++;
			sscanf(point,"%lg",&delay);
			*pid = fork();
			if (*pid == 0)
			{
				usleep(delay);
				execlp(buff,buff, NULL);
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
	else perror ("it is very, very bad (oh, my God!!!)");
	return (0);
}
