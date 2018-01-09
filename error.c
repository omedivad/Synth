void error_stamp(int err, int n, char *string){
	if(err != n){
		FILE *fp;
		fp = fopen("log.txt", "w+");
		if (fp == NULL){
			printf("Cannot open log.txt\n");
		}
		printf("%s \n Error: %d \n ", string, err);
		fprintf(fp, "%s \n Error: %d \n", string, err);
		fclose(fp);
	}
}

void all_error(char * string){
	FILE *fp;
	fp = fopen("log.txt", "w+");
	if (fp == NULL){
		printf("Cannot open log.txt\n");
	}
	printf("%s \n", string);
	fprintf(fp, "%s \n", string);
    sem_wait(&end_s);
      end = 1;
    sem_post(&end_s);
}