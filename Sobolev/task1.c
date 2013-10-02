#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

int main ( int argc, char *argv[] )
{
	printf( "The user id is %d\n", getuid() );
	printf( "The group id is %d\n",getgid() );
	int wow = open( argv[1], O_RDONLY );
	if (wow == -1)
	{
		perror( "oops, you can not open this file\n" );
		return 0;
	}
	else
	{
		printf( "succesfully opened\n" );
		if ( close(wow) == 0 )
			printf("succesfully closed\n");
		else
			perror( "oops, can not close this file" );
	}
	return 0;
}
