#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int file =0;
    int user_id = getuid();
    int group_id = getgid();
        printf("Номер пользователя = %d\n Номер группы = %d\n", user_id, group_id);
    file = open("newpr.c", O_RDONLY,0);
    if ( close(file) != 0)
        printf("File  is absent\n");
    if (file == -1)
        perror("File is absent\n");
    return 0
    ;
}
