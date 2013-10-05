int backup_folder(int revision, const char *path, const char *base);
//Backups folder from path to base with right revision. Returns 0 if at least one file or folder from the path was processed correctly otherwise returns 1.
int backup_file(int revision, const char *path, const char *base);
//Backups file from path to base with right revision. Returns 0 if file was processed correctly otherwise returns 1.
