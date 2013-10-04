#include "../headers/bp_main_tools.h"
#include "../headers/bp_limits.h"
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>


int bp_config_init(char *base) {
	if (access(CONFIG_FILE_NAME, F_OK|R_OK|W_OK)) {
		FILE *config_file = fopen(CONFIG_FILE_NAME, "w");
		assert(config_file != NULL);
		char base_a_adr[MAX_ADDRESS];
		assert(!realpath(DEFAULT_BASE, base_a_adr)); 
		assert(fprintf(config_file, "%s\n", base_a_adr) > 0);
		assert(!fclose(config_file));
		strcpy(base, base_a_adr);
		strcat(base, "/");
	}	
	else {
		FILE *config_file = fopen(CONFIG_FILE_NAME, "r");
		assert(config_file != NULL);
		assert(fscanf(config_file, "%s", base) == 1);
		strcat(base, "/");
		assert(!fclose(config_file));
	}
	if (access(REVISION_FILE_NAME, F_OK|R_OK|W_OK)) {
		FILE *r_file;
		assert((r_file = fopen(REVISION_FILE_NAME, "w")) != NULL);
		assert(fprintf(r_file, "0") > 0);
		assert(!fclose(r_file));
	}	
	return 0;
}
int bp_revision_inc(int *revision) {
	FILE *r_file = fopen(REVISION_FILE_NAME, "r");
	assert(r_file != NULL);
	assert(fscanf(r_file, "%d", revision) == 1);
	(*revision)++;
	assert(fclose(r_file) == 0);
	assert((r_file = fopen(REVISION_FILE_NAME, "w")) != NULL);
	assert(fprintf(r_file, "%d", *revision) > 0);
	assert(fclose(r_file) == 0);
	return 0;
}	
int bp_write_date(int revision) {
	FILE *rd_file = fopen(DATE_OF_REVISION_FILE_NAME, "a");
	assert(rd_file != NULL);
	time_t c_time = time(NULL);
	assert(c_time != ((time_t) -1));
	assert(fprintf(rd_file, "%d;%s", revision, ctime(&c_time)) > 0);
	assert(fclose(rd_file) == 0);
	return 0;
}
