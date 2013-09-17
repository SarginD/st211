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
	int wow = open( argv[1], 0_TEXT );
	if (wow == -1)
		perror( "oops, you can not open this text" );
	else
		printf( "succesfully opened" );
	return 0;
}
