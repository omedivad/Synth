#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_primitives.h>
#include "circular_array.h"
#include "variables.h"
#include "error.h"

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
