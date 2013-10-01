#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

int read_s(FILE *input, char *command, char *time ) {
	char buf[50],pt;
	fgets(buf, sizeof(buf), input);
	int i = 0;
	pt = buf[i];
//	while ((pt == ' ') || (pt == '\t')) pt = buf[++i];
//	if (pt == '\n')
	while (pt != ';') {
//  FIXME: address issue here

		*command++=pt;
		pt = buf[++i];
		}
	*command = '\0';
	pt=buf[++i];
	while ((pt != '\n') && (pt != '\0') && (pt != ' ') && ( pt != EOF)) {
		*time++=pt;
		pt = buf[++i];
		}
	*time = '\0';
					
	return pt;
	}

int main(int argc, char *argv[]){
	if (argc == 1) {
		perror("Write filename in the command line when you start the programm");
		exit(1);
                }
	FILE *input = fopen(argv[1],"r");
	char command[500], time_char[50];
	double time_sec;
	pid_t pid, pid_longest;
	double time_longest = 0;
	read_s(input, command, time_char);
	do { 
		sscanf(time_char, "%lf", &time_sec);
		if ((pid = fork()) == 0) {
			assert(usleep(1000*1000*time_sec) == 0);
//			printf("Command =  %s    Time = %s\n", command, time_char);
			execlp(command, command, (char*) NULL);
			exit(1);
			}
		if (time_sec > time_longest) {
			time_longest = time_sec;
			pid_longest = pid;
			}
		read_s(input, command, time_char);
		} while (!feof(input));
	int status;
	waitpid(pid_longest, &status, 0);
	fclose(input);
	return 0;
	}
