#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <allegro.h>

#include "variables.h"
#include "osc_f.c"

int main(void){
	pthread_t usr_hdlr;
	pthread_t osc;
	pthread_t filter;

	// task attributes
	pthread_attr_t osc_att;

	// initialize task attributes
	ctrl_var = pthread_attr_init(&osc_att);
	if(ctrl_var != 0){
		fprintf(stderr, "Error - pthread_create(), code: %d\n", ctrl_var);
	}

	ctrl_var = pthread_attr_setdetachstate(&osc_att, PTHREAD_CREATE_DETACHED, osc_f);
	if(ctrl_var != 0){
		fprintf(stderr, "Error - pthread_create(), code: %d\n", ctrl_var);
	}

	// create oscillator task
	ctrl_var = pthread_create(&osc, osc_att, );
	if(ctrl_var){
		fprintf(stderr, "Error - pthread_create(), code: %d\n", ctrl_var);
	}

	exit(EXIT_SUCCESS);
}