int bp_config_init(char *base); //Prepares base configureation file and revision file. Writes absolute address to base. Writes 0 to revisions. Returns 0 on success, otherwise returns 1
int bp_revision_inc(int *revision); //Prepares reviews configuration file. Writes current number of revision to revision. Imcrements number of revisions in revision configuration file. S0F1.
int bp_write_date(int revision); //Writes information about date(from *date) of new revision(from revision) to revision_date file. S0F1
