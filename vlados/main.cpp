#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[])
{
	printf("getuid = %d\n", getuid());
	printf("getgid = %d\n", getgid());
    
    int f1;
    
    if ((f1 = open(argv[1], O_RDWR, 0)) == -1)
        perror("Не могу открыть файл\n");
    else
        printf("Файл открылся\n");  
    return 0;
}
