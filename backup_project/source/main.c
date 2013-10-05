#include <stdio.h>
//#include "../headers/backup_tools.h"
#include "../headers/is_dir.h"
#include "../headers/bp_main_tools.h"
#include "../headers/bp_limits.h"

int main(int argc, char *argv[]) {
	char base[MAX_ADDRESS];
	bp_config_init(base);
	printf("%s\n", base);
	int i, j;
	for (j = 0; j <100; j++) {
		bp_revision_inc(&i);
		bp_write_date(i);
	}
	
	return 0;
}
