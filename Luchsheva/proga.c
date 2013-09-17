#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
  FILE * fo = fopen("id.txt","wt");
  if (fo == 0) 
    perror("Can not open the file");
  int id = getuid();
  int idgr = getgid();
  char str[] = "User identity:"; 
  char strgr[] = "Group identity:";
  fprintf( fo, "%s %d \n%s %d\n", str, id, strgr, idgr);
  fclose(fo);
  close( open("id.txt", O_RDONLY) );
  return 0;
}


