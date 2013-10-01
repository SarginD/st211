#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main ()
{
	int my_id = 0, group_id = 0;
	int my_notes = 0;
	my_notes = open ("note.txt", O_RDWR);
	if (my_notes == -1)
		perror ("Error: can't open the file");
	my_id = getuid();
	group_id = getgid();
	printf ("my id is %d. \n group id is %d. \n", my_id, group_id);
	if (my_notes !== -1)
		if (close (my_notes == 0))
			printf ("Closed correctly");
		else 
			printf ("Some problems with closing the file");
	return 0;

}
