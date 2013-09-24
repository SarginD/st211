#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    printf( "UID is %d\n", getuid() );

    printf( "GID is %d\n", getgid() );

    int file = open("111.c", O_RDONLY);

    if (file == -1)
        perror("The file wasn't opened. Error.\n");
        
    if (file != -1)

        if ( close(file) == 0 )
            printf("The file was closed correctly\n");
        else
            printf("Сlosing the file was wrong\n");
    return 0;
}
