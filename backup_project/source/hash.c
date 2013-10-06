#include<stdio.h>
#include<string.h>

long int  hash(FILE *input)
{
	long int h = 0;
	char c;
	while ((c = fgetc(input)) != EOF)
		h = (h + (long int)c) % (2 >> sizeof(long int));
	return h;
}
