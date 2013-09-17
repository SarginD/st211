#include <stdio.h>

int main ()
{
	int my_id = 0, group_id = 0;
	FILE *my_notes;
	my_notes = fopen ("note.txt", "wr");
	perror (my_notes);
	my_id = getuid();
	group_id = getgid();
	printf ("my id is %d. \n group id is %d. \n", my_id, group_id);
	return 0;

}
