#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include "../headers/bp_limits.h"
#include "../headers/is_dir.h"


int backup_folder(int revision, const char *path, const char *base)
{
	FILE *frevision, *finfo;
	struct dirent *dpath, *dsearch;
    	DIR *dirpath, *dirsearch;
	char str[MAX_ADRESS], str0[MAX_ADRESS];
	char int_to_str[10];
	int state = 1;

	if((dirpath = opendir(path)) == NULL)
	{
		printf("Error in opendir\n);
		return 1;
	}
 
	while((dpath = readdir(dirpath)) != NULL)
	{
		if((strcmp(dpath->d_name, ".") != 0) && (strcmp(dpath->d_name, "..") != 0))
		{
			strcpy(str, path); 	
			strcat(str, dpath->d_name); // str contain path/name
			printf("%s was readed\n", str);  
			switch(is_dir(str)) // What is it (path/name)?
			{
				case 1:	// It's a folder
				{

					strcpy(str0, base); 
					strcat(str0, dpath->d_name);
					strcat(str0, "/"); // str0 contain base/name/
					if(is_dir(str0) == -1)
					{
                        			if((mkdir(str0, 0777)) != 0)
                        			{
                            				printf("Error in mkdir(). Folder %s wasn't backuped\n", str0);
                            				printf("%s\n", str);
                            				continue;
                        			}
						printf("Folder %s was backuped\n", str0);
                    			}
					else printf("%s have already exist\n", str0);
					state = 0;
					strcpy(str, base);
					strcat(str, dpath->d_name);
                    			strcat(str, ".");
					sprintf(int_to_str, "%d", revision);
					strcat(str, int_to_str);
					strcat(str, ".info"); // str contain base/name.№.info

					assert((finfo = fopen(str, "a")) != NULL)

					strcpy(str, base);
					strcat(str, dpath->d_name);
					strcat(str, ".revision"); // str contain base/name.revision

					assert((frevision = fopen(str, "a")) != NULL) // Notice a number of the revision		
					fprintf(frevision, " %d", revision);
					fclose(frevision);

					strcpy(str, path);
					strcat(str, dpath->d_name);
					strcat(str, "/");  // str contain path/name/

					//A creation of the list
                    			assert((dirsearch = opendir(str))!=0);
                   			while ((dsearch=readdir(dirsearch)) != 0)
                        			if((strcmp(dsearch->d_name, ".") != 0) && (strcmp(dsearch->d_name, "..") != 0))
                            				fprintf(finfo, "%s%s\n", str, dsearch->d_name);
                    			closedir(dirsearch);


					backup_folder(revision, str, str0);
					fclose(finfo);
					break;
				}
				case -1: // Couldn't processed
				{
					printf("%s Error. Couldn't processed\n", dpath->d_name);
					closedir(dirpath);
					break;
				}
				case 0: // It's file
				{
					if(backup_file(str) == 1)
					{
						printf("File %s was backuped\n", str);
						state = 0;
					}
					else printf("File %s wasn't backuped\n", str);
					break;
				}
			}

		}
	}
	closedir(dirpath);
	return state;
}
