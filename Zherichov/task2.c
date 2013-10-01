#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char* argv[])
{


  if (argc!=2)
  {
    printf("Invalid params!\n");
    return -1;
  }

	
	
int time=0;
int i;

char name[100]={0};
char* seek;

pid_t pids[100] = {};
pid_t *pid;
pid=pids;
pid_t *start_pid= pid;

FILE* file;

file = fopen(argv[1],"r");
while (fscanf(file,"%s",name) != EOF)
	{//searchin for delimiter
	seek = name;
	while (*(seek) != ';')	seek++;
	*seek = NULL;
	seek+=1;
			
	sscanf(seek,"%d",&time);
	*pid = fork();
	if (*pid == 0)
	{
		usleep(time);
		execlp(name,name, NULL);
		return 0;
	}
	pid++;
	}
	fclose(file);
	
pid_t *indpid=start_pid;


//Waiting for all chids to close
while (indpid != pid)
{
	waitpid(*indpid,&i,0);
	indpid++;
}
	waitpid(*pid,&i,0);


  return 0;
}