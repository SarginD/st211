#include <stdio.h>
//#include <process.h>
//#include <conio.h>
#include <string.h>
//#include <dos.h>

typedef struct{
	char str[100];
	int i;
} file;

// FIXME: every program should return something!
void main(){
	FILE *f;
	file temp;
	char ch;
	file a[100];
	int pid[100];
	char string[100]="";
	int n=0;
	int i=0, j=0;
	int pause[100];
//	clrscr();
	printf("\n");
//  FIXME: you should take argument from command line
	f=fopen("aaa.txt","rt");
	printf("reading information from file...\n");
	while (ch!=EOF) {
		do{
//  FIXME: please provide working file example for these parser

			ch=fgetc(f);
			if (ch!=' ')
				i=10*i+ch-48;
		}while (ch!=' ');
		do{
			ch=fgetc(f);
			if((ch!=EOF)&&(ch!='\n'))
				string[n]=ch;
			//printf("%s",ch);
			n++;
		}while ((ch!='\n')&&(ch!=EOF));
		a[j].i=i;
		strcpy(a[j].str, string);
		for(n=0;n<100;n++)
			string[n]=NULL;
		n=0;
		pause[j]=i;
		j++;
		i=0;
		printf("%c",ch);
	}//while
	printf("finished reding from file\n");
	for(n=0;n<j;n++)
		for(i=0;i<=n;i++)
			if(a[i].i>a[n].i){
				temp=a[i];
				a[i]=a[n];
				a[n]=temp;
			}//if
	printf("finished sorting array\n");
	for(n=0;n<j;n++)
	    printf("%s with delay %d\n", a[n].str, a[n].i);
	for(n=0;n<j;n++){
	    pid[n]=fork();
	    if(pid[n]==0)
	        break;
	}
	for(n=0;n<j;n++){
	    if(pid[n]==0){
		sleep(a[n].i);
		execlp(a[n].str, a[n].str, NULL);
	    }
	}
	for(n=0;n<j;n++){
	    if(pid[n]>0){
//  FIXME: you should use waitpid here
		wait(0);
	    }
	}
}
