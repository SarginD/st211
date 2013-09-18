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
	perror( "oops, somithing went wrong\n" );
	int wow = open( argv[1], 0_RDONLY );
	if (wow == -1)
		perror( "oops, you can not open this file\n" );
	else
	{
		printf( "succesfully opened\n" );
		if ( close(wow) == 0 )
			printf("succesfully closed\n");
		esle
			perror( "oops, can not open this file" )
	}
	return 0;
}
