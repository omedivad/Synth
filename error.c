void error_stamp(int err, int n, char *string){
	// pointer to log file
	if(err != n){
		FILE *fp;
		fp = fopen("log.txt", "w+");

		printf("Error: %s %d \n ", string, err);
		fprintf(fp, "Error: %d \n", string, err);
		fclose(fp);
	}
}

void all_error_stamp(char *string){
	if(all_ctrl_var != NULL){
		printf(" %s: %s \n", string, all_ctrl_var);
	}
}