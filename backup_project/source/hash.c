#include <stdio.h>
#include "../headers/hash.h"
#include "../headers/bp_limits.h"

long int hash(FILE *input)
{
	long int h = 0;
	int c;
	while ((c = fgetc(input)) != EOF)
		h = (c + h) % MAX_HASH;
	return h;
}
