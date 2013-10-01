#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>

int named_pipe_test(char *fileName){
    if (mknod(fileName, S_IFIFO | 0666, 0) < 0) {
        perror("failed to create named pipe");
        return -1;
    }
    
    
    char outMessage[] = "asdfghjkasdf";
    int messageSize = (int)strlen(outMessage);
    char inMessage[messageSize];
    
    int isParent = fork();
    if (isParent < 0)
        perror("failed to create a child");

    if (isParent == 0) {
        int fd;
        ssize_t writtenSize;
        if ((fd = open(fileName, O_WRONLY)) < 0)
            perror("failed to open fd\n");
        
        if ((writtenSize = write(fd, outMessage, messageSize)) < 0)
            perror("write eror\n");
        else if (writtenSize != messageSize)
            perror("message was written, but not all");
        
        close(fd);
        printf("parent exit\n");
        
    }
    else{
        printf("child is here\n");
        int fd = open(fileName, O_RDONLY);
        ssize_t readSize;
        if (fd < 0) perror("failed to open fd");
        readSize = read(fd, &inMessage, messageSize);
        if (readSize != strlen(outMessage)) printf("not fully read\n");
        else printf("the message is %s\n", inMessage);
        close(fd);
        printf("child exit\n");
    }

    unlink(fileName);
    
    return 0;
}
