#include "csv.h"

int csv_read(char *statement, int maxlen) {
	assert(statement != NULL && maxlen > 0);
	int c;
	while ((c = getchar()) == ' ' || c == '\n')
		;
	if (c == ';') { 
		perror("csv_read: There is nothing before ';'\n"); 
		exit(1);
	}
	if (c == EOF)
		return 0;
	int i = 1;
	for (*statement++ = c; (c = getchar()) != ';' && c != '\n' && c != EOF; i++, *statement++ = c) //get real information
		if (i == maxlen) {  //memory is over
			if (c == ' ') { //If other symbols are all spaces
				while ((c = getchar()) == ' ')
					;
				if (c == '\n' || c == ';' || c == EOF) { //still have enough memory
					*statement = '\0';
					return c;
				}
				else {
					printf("csv_read: string is too big\n");
					exit(1);
				}
			}
			else {
				printf("csv_read: string is too big\n");
				exit(1);
			}
		}
	while (*--statement == ' ') 
		;
	*++statement = '\0';
	return c;
}
