#include<stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<unistd.h>

int main()
{
	int a;

	a=open("core.txt", O_WRONLY | O_CREAT | O_TRUNC , S_IREAD | S_IWRITE);
	if ( a == -1)
	perror("open failed on output file");
	printf("User's ID is %ld\nReal Group's ID is %ld\n", getuid(), getgid());
	return 0;
}
