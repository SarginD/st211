#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int file =0;
    printf("User ID is %d\n", getuid());
    printf("Group ID is %d\n", getgid());
    file = open("1.txt", O_RDONLY,0);
    if (file == -1)
        perror("Error!\n");
    if ( close(file) != 0)
        printf("Error!\n");
    return 0;
}

