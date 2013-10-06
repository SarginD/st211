#include "../headers/csv.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int csv_read(FILE *file, char *statement, int maxlen) {
	if (statement == NULL || maxlen <= 0)
		return -1;
	int c;
	while ((c = fgetc(file)) == ' ' || c == '\n')
		;
	if (c == ';') { 
		perror("csv_read: There is nothing before ';'\n"); 
		return -1;
	}
	if (c == EOF)
		return 0;
	int i = 1;
	for (*statement++ = c; (c = fgetc(file)) != ';' && c != '\n' && c != EOF; i++, *statement++ = c) //get real information
		if (i == maxlen) {  //memory is over
			if (c == ' ') { //If other symbols are all spaces
				while ((c = fgetc(file)) == ' ')
					;
				if (c == '\n' || c == ';' || c == EOF) { //still have enough memory
					*statement = '\0';
					return c;
				}
				else {
					perror("csv_read: string is too big\n");
					return -1;
				}
			}
			else {
				perror("csv_read: string is too big\n");
				return -1;
			}
		}
	while (*--statement == ' ') 
		;
	*++statement = '\0';
	return c;
}
