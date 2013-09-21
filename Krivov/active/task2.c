#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <sys/types.h>
#include "csv.h"

int main() {
	int state;
	do {
		pid_t pid;
		char command[101], time_string[101];
		if (csv_read(command, 100) == 0)  //there are no more commands
			break;
		state = csv_read(time_string, 100);
		if ((pid = fork()) == 0) {
			double time_in_seconds;
			sscanf(time_string, "%lf", &time_in_seconds);
			int time_in_micros = (int) (1000*1000*time_in_seconds);
			assert(usleep(time_in_micros) == 0);
			execlp(command, command, (char *) NULL);
			printf("execlp error. Command:%s Delay: %s\n", command, time_string);
			exit(1);
		}
		assert(pid != -1);
	} while (state != EOF);
	return 0;
}
