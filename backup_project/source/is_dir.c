#include "../headers/is_dir.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
int is_dir(const char *path) {
	if (path == NULL)
		return -1;
	struct stat my_stat;
	if (stat(path, &my_stat) != 0)
		return -1;
	return S_ISDIR(my_stat.st_mode);
}

