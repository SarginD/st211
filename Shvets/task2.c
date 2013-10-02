#include <stdio.h> 
#include <unistd.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char* argv[])
{
     double delay==0;
     char name[100]={0};
     int i;
     char* seek
     pid_t *pid, ar_pid[50] = {},*pid0;
     pid = ar_pid;
     pid0 = pid;
     if ( argc == 2 )
          {
                        FILE* file;
                        file = fopen(argv[1],"r");
                        while (fscanf(file,"%s",name) != EOF)
                            {
                                  seek = name;
                                  while (*(seek) != ';')
                                  point++;
                                  *seek = NULL;
                                  sscanf(point,"%lg",&delay);
                                 *pid = fork();
                                  if (*pid == 0)
                                  {
				                              usleep(delay);
			                               	execlp(name,name, NULL);
			                               	return 0;
			                            }
			                            pid++;
			                       }
            fclose(file);
            while (pid0 != pid)
                {
                    waitpid(*pid0,status,0);
                    pid0++;
                }
            waitpid(*pid,status,0);
          }
    else { perror("Error"); }
    return (0); 
    
}
