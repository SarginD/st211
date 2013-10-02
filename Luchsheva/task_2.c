#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

const int SEC_TO_USEC = 1000000, COM_SIZE = 20;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s cmd_file\n", argv[0]);
        return 1;
    }
    char command[256], *pch;
    double time;
    FILE *command_time = fopen(argv[1],"r");
    while(fscanf(command_time,"%s", command) != EOF) {
        pch = strchr(command, ';');
        *pch = '\0';
        time = atoi(pch+1);     
        int pid_t = fork();
        if (pid_t == 0) {
            usleep(time * SEC_TO_USEC);
            execlp(command, command, NULL);
        }
    }
    fclose(command_time);
    return 0;
}
