#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    int temp = open("stuff.cpp", O_RDONLY);
    if (temp == -1)
        perror("Oh my gosh! The file wasn't opened properly!");
    printf( "User ID is %d\n", getuid() );
    printf( "Group ID is %d\n", getgid() );
    if ( close(temp) == 0)
        printf("The file was closed correctly\n");
    else
        printf("Something wrong with closing the file :C\n");
    return 0;
}
