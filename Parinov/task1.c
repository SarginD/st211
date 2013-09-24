#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
int main()
{
printf ("Your ID is %d\n", getuid());
printf ("Group ID is %d\n", getgid());
int test = open("script.sh", O_RDONLY);
if (test == -1)
perror("Sluchilas beda\n");
else
printf("Vse ontlichno\n")
return 0;
}
