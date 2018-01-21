// print generic error to log.txt and to standard output
void error_stamp(int err, int n, char *string){
	if(err != n){
		FILE *fp;
		fp = fopen("log.txt", "a");
		if (fp == NULL){
			printf("Cannot open log.txt\n");
		}
		printf("%s \n Error: %d \n ", string, err);
		fprintf(fp, "%s \n Error: %d \n", string, err);
		fclose(fp);
	}
}

// print allegro error to log.txt and to standard output
void all_error(char * string){
	FILE *fp;
	fp = fopen("log.txt", "a");
	if (fp == NULL){
		printf("Cannot open log.txt\n");
	}
	printf("%s \n", string);
	fprintf(fp, "%s \n", string);
	sem_wait(&end_s);
		end = 1;
	sem_post(&end_s);
}
