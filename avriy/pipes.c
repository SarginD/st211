#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>

int pipetest(){
    int fd[2];
    char *message = "Hello!";
    int messageSize = (int)strlen(message);
    char incomingMessage[messageSize];
    
    if (pipe(fd) < 0 ) {
        perror("failed to create a pipe");
        return -1;
    }
    
    if (fork()) {
        close(fd[0]);
        if (write(fd[1], message, messageSize) != messageSize ) {
            perror("failed to write all the message");
            return -1;
        }
    }
    else {
        close(fd[1]);
        if (read(fd[0], incomingMessage, messageSize) != messageSize) {
            perror("failed to read all the message");
            return -1;
        }
        printf("%s\n", incomingMessage);
    }
    
    
    if (close(fd[0])+close(fd[1]) < 0)
        perror("Cannot close");
    
    return 0;
}

