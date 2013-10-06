#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include "csv.h"
#include <dirent.h>
#include <unistd.h>
#include <hash.h>
#include "fcopy.h"

int recover_file(int revision, const char *path, const char *base, const char *filename) {
        FILE *fdata, *forigin;
        sruct dirent *dpath;
        DIR *dirpath;
        char str[MAX_ADRESS], str0[MAX_ADRESS];
        strcpy(str0, filename);
        strcat(str0, ".data");
        int state,i = 0;
	long int hash1, hash2;

        dirpath = opendir(base);
        while ((dpath = readdir(dirpath)) != NULL) {
                strcpy(str, d_name);
                strcat(str, ".data");
                if (strcmp(str0, str) == 0) i = 1;
        }

        strcpy(str0, path);
        strcpy(str0, filename);

        if ((forigin = fopen(str0 = NULL)) printf("Error in opening original file\n");
	hash1 = hash(forigin);
        dirpath = opendir(base);

	if ((fdata = fopen(str0, "a") == NULL) printf("Error in creating or opening of the base\n");
	if (i == 0) {
	fprintf(fdata, "%s;%s;%s", revision, hash1, revision);
	fcopy(str0, str);
	}
	else {
			do { 
				char hash1_c[10001], revision1_c[101], revision2_c[101];
				csv(fdata, revision1_c, 100);
				csv(fdata, hash1_c, 100);
				state = csv(fdata, revision2_c, 100);
			} while ( state != EOF);
	}
		hash2 = (long int) (hash1_c);
		if (hash1 == hash2) {
			fprintf(fdata, "/n%s;%s;%s", revision, hash2, revision2_c);
			}
		else {
			fcopy(str0, str);
			fprintf(fdata, "/n%s;%s;%s", revivion, hash1, revision);
		}
	return 0;
}
