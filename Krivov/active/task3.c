#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <pthread.h>
#include <unistd.h>
#include <assert.h>

void *thread_write(void *arg) {
	pthread_setcancelstate(PTHREAD_CANCEL_ASYNCHRONOUS, NULL); 
	int *i = (int *) arg;
	char mas[1] = {'a'};
	int d[2];
	assert(!pipe(d));
	for (*i = 0; write(d[1], mas, 1) == 1; (*i)++)
		;
	return NULL;
}

void *thread_calculate(void *arg) {
	int *p_size = (int *) arg;
	int old_size = *p_size;
	assert(!sleep(1));
	while (old_size != *p_size) {
		old_size = *p_size;
		assert(!sleep(1));
	}
	return p_size;
}

int main(int argc, char *argv[])
{
	int result, size = 0;
	pthread_t thread_c, thread_w;
	result = pthread_create(&thread_w, NULL, thread_write, &size);
	if (result != 0) {
		perror("Creating the first thread");
		return 1;
	}
	result = pthread_create(&thread_c, NULL, thread_calculate, &size);
	if (result != 0) {
		perror("Creating the second thread");
		return 1;
	}
	result = pthread_join(thread_c, NULL);
	if (result != 0) {
		perror("Joining the second thread");
		return 1;
	}
	result = pthread_cancel(thread_w);
	if (result != 0) {
		perror("Cancelling the first thread");
		return 1;
	}
	printf("Final result is %d\n", size);
	return 0;
}
