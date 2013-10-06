int recover_folder(int revision, const char *path, const char *base);
//Backups folder from path to base with right revision. Returns 0 if at least one file or folder from the path was processed correctly otherwise returns 1.
int recover_file(int revision, const char *path, const char *base);
//Recovers file from base to psth with right revision. Returns 0 if file was processed correctly otherwise returns 1.
