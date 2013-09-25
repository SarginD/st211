#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

const int COM_SIZE = 30;

struct process
    {
        // command's name
        char com[COM_SIZE];
        // [time] = [microseconds]
        long time;
    };

struct longest_proc
    {
        //its pid
        int proc_id;
        /* [time] = [microseconds]
           we should wait 'till this process ends working at the end of the programm*/
        long time_to_wait;
    };

process parse(char statement[COM_SIZE]); 

int main(int argc, char** argv)
{
    // there should be at least the file as an argument
    assert(argc >= 2);
    FILE* f_in = fopen(argv[1], "r");
    assert(f_in);
    // Declaration part
    char command[COM_SIZE] = "";
    process exec = {};
    longest_proc pr = {};
    int t_pid = 0;

    while (fscanf(f_in, "%s", command) != EOF)
    {
        exec = parse(command);
        t_pid = fork();
        if (t_pid == 0)
        {
            usleep(exec.time);
            int error = execlp(exec.com, exec.com, NULL);
            assert(error != -1);
        }
        if (pr.proc_id == 0)
        {
            pr.proc_id = t_pid;
            pr.time_to_wait = exec.time;
        }
        else if (pr.time_to_wait < exec.time)
        {
            pr.proc_id = t_pid;
            pr.time_to_wait = exec.time;
        }
    }

    int* status;
    waitpid(pr.proc_id, status, 0);             

    return 0;
}

process parse(char statement[COM_SIZE])
{
    process temp = {};
    double time_sec = 0;
    long time_msec = 0, i = 0;
    char ret_com[COM_SIZE], time[COM_SIZE];
    // getting the command
    for (i; statement[i] != ';'; ++i)
        ret_com[i] = statement[i];
    ++i;
    int diff = strlen(ret_com) + 1;
    // getting the delay time in microsecs
    for (i; statement[i] != '\0'; ++i)
        time[i - diff] = statement[i];
    sscanf(time, "%lf", &time_sec);
    time_msec = (long) 1000000*time_sec;

    strcpy(temp.com, ret_com);
    temp.time = time_msec;
    return temp;
}

    
