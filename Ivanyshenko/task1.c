#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
int main ()
{
	printf ("uid is %d\n", getuid());
	printf ("gid is %d\n", getgid());
	int file = open("1.c", O_RDONLY);
	if (file == -1)
		perror("file wasn't open correctly");
	else if (close(file) == 0)
		printf ("file opened and closed correctly");
	     else 
		perror ("file wasn't closed correctly");

	return (0);
}
