#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main (int argc, char **argv)
{
	printf("UID = %d; PID = %d \n",getuid(),getpid());
	int file = open("1.txt",O_RDONLY);
	if (file<0) 
	{
		perror("Error opening file");
		return -1;
	}
	else
	{
		printf("Opened successfully! \n");
		close(file);
	}
	return 0;
}
