#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#define MAX_ADRESS 200

int backup_folder(int revision, const char *path, const char *base)
{
	FILE *frevision, *finfo;
	struct dirent *dpath;
        DIR *dirpath;
	char str[MAX_ADRESS], str0[MAX_ADRESS];

	dirpath = opendir(path);
	while((dpath = readdir(dirpath)) != NULL)
	{
	    printf("%s\n", dpath->d_name);
		if((strcmp(dpath->d_name, ".") != 0) && (strcmp(dpath->d_name, "..") != 0))
		{
			printf("%s was readed\n", dpath->d_name);
			strcpy(str, path);
			strcat(str, dpath->d_name);
			printf("str = %s\n", str); // str is contained path/name
			switch(is_dir(str))
			{
				case 1:
				{

					strcpy(str0, base);
					strcat(str0, dpath->d_name);
					strcat(str0, "/"); // str0 is contained base/name/

					printf("\n");

					if((mkdir(str0, 0777)) != 0)
					{
						printf("Error in mkdir()\n");
						printf("%s\n", str);
						continue;
					}

					strcpy(str, base);
					strcat(str, dpath->d_name);
//					strcat(str, (revision+'0'));
					strcat(str, ".info"); // str is contained base/name№.info

					if((finfo = fopen(str, "a")) == NULL) printf("Error in the opening of base\n");

					strcpy(str, base);
					strcat(str, dpath->d_name);
					strcat(str, ".revision"); // str is contained base/name.revision

					if((frevision = fopen(str, "a")) == NULL) printf("Error in the opening of path\n");

					fprintf(frevision, " %d", revision);
					fclose(frevision);

					strcpy(str, path);
					strcat(str, dpath->d_name);
					strcat(str, "/");  // str is contained path/name/

					if(backup_folder(revision, str, str0) == 1)
					{	printf("file %s.info\n", dpath->d_name);
						fprintf(finfo, "%s\n", str);
					}

					fclose(finfo);
					break;
				}
				case -1:
				{
					printf("%s Error. It isn't a folder or a file\n", dpath->d_name);
					closedir(dirpath);
					return 0;
				}
			}

		}
	}
	closedir(dirpath);
	return 1;
}


