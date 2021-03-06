#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

const int Translation_in_seconds = 1000000;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("There aren't pass of file\n");
        return -1;
    }
double time;
char command[256], *pch;
    FILE *delay = fopen(argv[1],"r");
    while(fscanf(delay,"%s", command) != EOF) {
        pch = strchr(command, ';');
        *pch = '\0';
        time = atoi(pch+1);
//   FIXME: paren process ends while children is alive
        int pid_t = fork();
        if (pid_t == 0) {
            usleep(time * Translation_in_seconds);
            execlp(command, command, NULL);
        }
    }
    fclose(delay);
    return 0;
}
