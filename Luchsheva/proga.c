#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>

int main(int argc, char *argv[]) {
  FILE * fo;
  fo = fopen("id","wt");
  if( (fo=fopen("id","wt")) == 0) {
    perror("Can not open the file");
  }
  int id = 0;
  id = getuid();
  int idgr = 0;
  idgr = getgid();
  char str[20] = "User identity: "; 
  char strgr[20] = "Group identity: ";
  fprintf( fo, "%s %d \n%s %d\n", str, id, strgr, idgr);
  return 0;
}


