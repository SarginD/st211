#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
int main (void)
{
	int counter = 0, fd[2],i;
	char buffer[100] = {0};
	pipe2(fd, O_NONBLOCK);
	while ((i = write(fd[1], buffer, 1)) != -1)
	{
		counter+=i;
	}
	printf ("%d\n",counter);
	return 0;
}
