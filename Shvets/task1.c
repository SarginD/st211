#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <errno.h>
#include <unistd.h>

int main()
  {
    int file =0;
    printf("User ID is %d\n", getuid());
    printf("Group ID is %d\n", getgid());
    file = open("666.txt", O_RDONLY,0);
    if (file == -1)
        perror("Mistake!\n");
    if ( close(file) != 0)
        printf("Mistake!\n");
    return 0;
  }
