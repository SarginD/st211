#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

int read_s(FILE *input, char *command, char *time) {
        char buf[50]={0};
	char pt;
//  FIXME: parser has issue: it adds last line 2 times
        if(fgets(buf, sizeof(buf), input) == NULL)
	return -1;
        int i = 0;
        pt = buf[i];
        while ((pt == ' ') || (pt == '\t')) pt = buf[++i];
        while (pt != ';') {

               	*command=pt;
              	command++;
                pt = buf[++i];
                }
        *command = '\0';
        pt=buf[++i];
        while ((pt != '\n') && (pt != '\0') && (pt != ' ') && ( pt != EOF)) {
           
		*time=pt;
                time++;
                pt = buf[++i];
                }
        *time = '\0';

        return 0;
        }

int main(int argc, char *argv[]){
	if (argc == 1) {
 		perror("Write filename in the command line when you start the programm");
		exit(1);
                }
	int c;
	FILE *input = fopen(argv[1],"r");
	char command[50], time_char[50];
	double time_sec;
	pid_t pid, pid_longest;
	double time_longest = 0;
	do {
		c = read_s(input, command, time_char);
		if (c == -1) break;
		sscanf(time_char, "%lf", &time_sec);
		if ((pid = fork()) == 0) {
			assert(usleep(1000*1000*time_sec) == 0);
	//		printf("Command = %s Time = %s\n", command, time_char);
//  FIXME: wrong order of commands execution here! ls;4\n pwd;3 first executes ls, then pwd

			execlp(command, command, (char*) NULL);
			exit(1);
			}
		if (time_sec > time_longest) {
			time_longest = time_sec;
			pid_longest = pid;
			}
		} while (c != -1);
	int status;
	waitpid(pid_longest, &status, 0);
	fclose(input);
	return 0;
	}
