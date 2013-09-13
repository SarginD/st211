#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

const int MAXLEN = 50;


int main()
{
	char name[MAXLEN];
	char word[MAXLEN];
	unsigned short int my_id = getuid();
	unsigned short int gr_id = getgid(); 
	printf("Your real identifier is %d\n", my_id);
	printf("Group real identifier is %d\n", gr_id);

	printf("Print name of file to open\n");
 	scanf("%s", name);

 
	int input = open(name, O_WRONLY, S_IWGRP);
	if (input == -1)
	{
		perror("File doesn't exist\n");
		return 0;
	}
	else
	{
		printf("What do you want to write in file (put the word)\n");
		scanf("%s", word);
		input = write(input, word, strlen(word));
	}

	if (input < 0)
	{
		perror("Error, the word wasn't written in file\n");
	}
	else
	{
		printf("Succesfull\n");
	}	 


	return 0;
}
