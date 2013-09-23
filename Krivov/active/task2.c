#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "csv.h"

int main(int argc, char *argv[]) {
	if (argc < 2) {
		perror("File must be written in the command line as the first argument");
		exit(1);
	}
	FILE *file = fopen(argv[1], "r");
	assert(file);
	int state, time_in_micros;
	double time_in_seconds;
	struct {
		pid_t pid;
		int time_in_micros;
		} long_process = {-1, 0};
	do {
		char command[101], time_string[101];
		if (csv_read(file, command, 100) == 0)  //there are no more commands
			break;
		state = csv_read(file, time_string, 100);
		sscanf(time_string, "%lf", &time_in_seconds);
		time_in_micros = (int) (1000*1000*time_in_seconds);
		pid_t pid;
		if ((pid = fork()) == 0) {
			assert(usleep(time_in_micros) == 0);
			execlp(command, command, (char *) NULL);
			printf("execlp error. Command:%s Delay: %s\n", command, time_string);
			exit(1);
		}
		assert(pid != -1);
		if (time_in_micros > long_process.time_in_micros) {
			long_process.time_in_micros = time_in_micros;
			long_process.pid = pid;
		}
	} while (state != EOF);
	int status;
	waitpid(long_process.pid, &status, 0);
	return 0;
}
