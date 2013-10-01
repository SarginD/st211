
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define NUMBER_OF_THREADS 10

void *print_hello_world(void* tid){
    printf("Hello from thread %d\n", (int)tid);
    pthread_exit(NULL);
}


int main(int argc, const char * argv[])
{
    pthread_t threads[NUMBER_OF_THREADS];
    int status, i;
    
    
    for (int i = 0; i < NUMBER_OF_THREADS; i++) {
        printf("main is here, creating the thread %d\n", i);
        status = pthread_create(&threads[i], NULL, print_hello_world, (void *)i);
        
        if (status) {
            printf("Error while creating the thread");
            return -1;
        }
    }
    
    return 0;
}


