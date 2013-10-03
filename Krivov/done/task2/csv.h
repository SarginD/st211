#include <stdio.h>
int csv_read(FILE *file, char *statement, int maxlen); 
/*Reads one statement from file, writes it to statement, returns ending symbol (EOF, '\n' or ';')
Can also return 0 if there are no more statements. In this case nothing was written to statement.*/
