#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <assert.h>


int main(int argc, char *argv[])
{
	double time, max_time;
	char* ptr = NULL;
	int* status = NULL;
	char str[100]={0};
	pid_t pid, max_pid;
	max_time = 0;
	max_pid = -1;
	if (argc < 2)
	{
		perror("File wasn't written in command line");
		return 0;
	}
	FILE* file = fopen(argv[1],"r");
	assert(file != NULL);
	while (fscanf(file,"%s",str) != EOF)
	{
		ptr = str;
		while (*(ptr) != ';')
		{
			assert(*(ptr) != '\0'); 
			ptr++;
		}
		*ptr = '\0';
		ptr++;
		sscanf(ptr,"%lf",&time);
		if ((pid = fork()) == 0)
		{
			usleep((int)time*1000*1000);
			execlp(str,str, NULL);
			return 0;
		}
		assert(pid != -1);
		if(time > max_time) 
		{
			max_pid = pid;
			max_time = time;
		}
	}
	fclose(file);
	waitpid(max_pid, status, 0);
	return 0;
}
