#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdio.h>

int main()
{
    int state = open("script.sh", O_RDONLY);
    if (state == -1)
        perror("The file wasn't opened");
    int user_id = getuid();
    int group_id = getgid();    
    printf("User_ID = %d\nGroup_ID = %d\n", user_id, group_id);
    if (state != -1)
        if ( close(state) == 0 )
            printf("The file was closed\n");
        else
	    printf("Error\n");
    return 0;
}
