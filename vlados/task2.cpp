#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char * argv[])
{
        if (argc == 2){
        FILE *file = fopen(argv[1],"r");
        char line[1024];
        char *x[1024] = {0};
        char *buf;
        int time = 0;
        while(fscanf(file,"%s", line) != EOF) {
            buf = strtok(line, ";");
            int i = 0;
            while(buf){
                x[i++] = buf;
                buf = strtok(NULL, ";");
            }
            time = (atoi(x[1])*1000000);
            int pid_t = fork();
            if (pid_t == 0) {
                usleep(time);
                execlp(x[0], x[0], NULL);
            }
        }
        }else
            printf("ERROR: Нужен аргумент!"); 
        return 0;
    
}