#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>

struct process {
	char com_text[20];
	int delay;
};


process pread(FILE * f_in);

int main(int argc, char * argv[]){
	FILE * f_in = fopen(argv[1], "r");
	process tmp = pread(f_in);
	int pid;
    
	while(tmp.delay != -1){
		pid = fork();
		if (pid < 0)
			perror("Process can not be created\n");
		if (pid != 0)
//  FIXME: we should point here where to put status:
			watpid(pid, status, 0);
		else {
			usleep(tmp.delay);
			execlp(tmp.com_text, tmp.com_text, NULL);
		}
		tmp = pread(f_in);
	}
	fclose(f_in);
	return 0;
}

process pread(FILE * f_in){
	process cur;
	char temp;
	int time;
	int i = 0;
	process end = {"That's all", -1};
    
	while (1){
//  FIXME: any compiler should hate this:
		fscanf(f_in, "s", %temp);
//  FIXME: here should be ';', not ";"
		if(temp == ";")
			break;
		if(temp == EOF)
			return end;
		cur.com_text[i] = temp;
		i++;
	}
	fscanf(f_in, "%d", time);
	cur.delay = 1000000*time;
	getchar();
	return cur;
}
