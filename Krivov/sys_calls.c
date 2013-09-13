#include <unistd.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>

int main(int arc, char **arv) {
	perror("error message");
	printf("getgid = %d\n", getgid());
	printf("getuid = %d\n", getuid());
	int d = -1;
	const char *s = (arc == 1 ? "script.sh" : arv[1]);

	if (-1 != (d = open(s, O_RDONLY))) {
		printf("file was opened\n");
		if (!close(d))
			printf("file was closed\n");
		else
			printf("file wasn't closed\n");
	}
	else
		printf("file wasn't opened\n");    
	return 0;
}
