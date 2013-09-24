#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>


int main ()
{
	int my_id = 0, group_id = 0;
	int my_notes = 0, bad = 0;
	my_notes = open ("note.txt", "O_RDWR");
	bad = open ("note2.txt", "O_RDONLY");
	my_id = getuid();
	group_id = getgid();
	printf ("my id is %d. \n group id is %d. \n", my_id, group_id);
	if (my_notes != -1)
		perror ("Can't open the file");
	else
		close (my_notes);
	if (bad == -1)
		perror ("The file is OK");
	close(bad);
	return 0;

}
