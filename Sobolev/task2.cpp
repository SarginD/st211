#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>
#include <wait.h>
#include <string.h>

struct process {
	char com_text[20];
	int delay;
};


process p_read(FILE * f_in);

int main(int argc, char * argv[]) {
	FILE * f_in = fopen(argv[1], "r");
	process p_arr[20];
	int i = 0;

	p_arr[i] = p_read(f_in);
	while (p_arr[i].delay != -1) {
		i++;
		p_arr[i] = p_read(f_in);
	}

	const int com_num = i;

	for (int j = 0; j < com_num; j++) {
		for (int i = 0; i < com_num - 1 - j; i++) {
			if (p_arr[i].delay > p_arr[i + 1].delay) {
				process swap = p_arr[i + 1];
				p_arr[i + 1] = p_arr[i];
				p_arr[i] = swap;
			}
		}
	}

	for (int i = 0; i < com_num; i++) {
		printf("%s %d\n", p_arr[i].com_text, p_arr[i].delay);
	}
	int cur_delay = p_arr[0].delay;
	for (int i = 0; i < com_num; i++) {
		int pid = fork();
//		printf("%s\n", p_arr[i].com_text);
		if (pid == 0) {
			usleep(cur_delay);
			execlp(p_arr[i].com_text, p_arr[i].com_text, NULL);
			int * status;
			waitpid(p_arr[i].delay, status, 0);
		}
		if (i != com_num - 1)
			cur_delay = p_arr[i + 1].delay - p_arr[i].delay;
	}
	fclose(f_in);
	return 0;
}

process p_read(FILE * f_in) {
	process cur;
	double time;
	int i = 0;
	char buf[10] = {};
	process end = {"That is all", -1};

	while (1) {
		char temp = getc(f_in);
		
		if (temp == '\n')
			temp = getc(f_in);
		if (temp == ';')
			break;
		if (temp == EOF)
			return end;
		buf[i] = temp;
		i++;
	}
	strcpy(cur.com_text, buf);
	fscanf(f_in, "%lf", &time);
	cur.delay = 1000000*time;
	return cur;
}
