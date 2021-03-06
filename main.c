#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include "audio.h"
#include "circular_array.h"
#include "variables.h"
#include "osc_f.h"
#include "filter.h"
#include "handler.h"
#include "command.h"
#include "audio.h"
#include "graphic.h"
#include "all_init.h"
#include "variables_init.h"
#include "rt_attr_task.h"
#include "error.h"

void init_hrt_attr(pthread_attr_t *rt_attr, struct sched_param *hrt_param, int n);
void init_allegro(void);

int main(void){
	int ctrl_var = 0;
	variables_init();
	// pthreads
	pthread_t osc, gra, hdlr, flt, ado, comm;
	pthread_attr_t hrt_attr, rt_attr, hrtd_attr;
	struct sched_param hrt_param, rt_param, hrtd_param;

	// initializing output array OSC1, OSC2, filter1, filter2 
	// FILE "circular_array.c"
	init_CA(&wave_va);
	init_CA(&wave_va_2);
	init_CA(&wave_va_flt);
	init_CA(&wave_va_2_flt);


	// initialize semaphores
	sem_init(&end_s, 0 , 1);
	sem_init(&hold_s, 0 , 1);
	sem_init(&pitch_s, 0 , 1);
	sem_init(&wave_f_s, 0 , 1);
	sem_init(&filter_s, 0 , 1);
	sem_init(&samples_s, 0 , 1);
	sem_init(&pitch_2_s, 0 , 1);
	sem_init(&wave_sel_s, 0 , 1);
	sem_init(&filter_2_s, 0 , 1);
	sem_init(&amplitude_s, 0 , 1);
	sem_init(&draw_wave_s, 0 , 1);
	sem_init(&wave_sel_2_s, 0 , 1);
	sem_init(&amplitude_2_s, 0 , 1);

	// initialize graphic
	// FILE "circular_array.c"
	all_init();

	// set attr for rt threads
	init_hrt_attr(&hrt_attr, &hrt_param, 99);
	init_hrt_attr_d(&hrtd_attr, &hrtd_param, 2);
	init_hrt_attr(&rt_attr, &rt_param, 90);

	//create threads
	ctrl_var = pthread_create(&osc, &hrt_attr, osc_f, NULL);
	error_stamp(ctrl_var, 0, "OSCs thread");

	// create tasks
	ctrl_var = pthread_create(&hdlr, &hrt_attr, handler_f, NULL);
	error_stamp(ctrl_var, 0, "Handler thread");

	ctrl_var = pthread_create(&flt, &hrt_attr, filter_f, NULL);
	error_stamp(ctrl_var, 0, "Filters thread");

	ctrl_var = pthread_create(&gra, &rt_attr, graphic_f, NULL);
	error_stamp(ctrl_var, 0, "Graphical thread");

	ctrl_var = pthread_create(&ado, &hrt_attr, audio_f, NULL);
	error_stamp(ctrl_var, 0, "Audio thread");

	ctrl_var = pthread_create(&comm, &hrtd_attr, command_f, NULL);
	error_stamp(ctrl_var, 0, "Command thread");

	// destroy attr.s no longer useful
	ctrl_var = pthread_attr_destroy(&rt_attr);
	error_stamp(ctrl_var, 0, "RT HEADSHOT MISSED");
	
	ctrl_var = pthread_attr_destroy(&hrt_attr);
	error_stamp(ctrl_var, 0, "Hrt HEADSHOT MISSED");

	ctrl_var = pthread_attr_destroy(&hrtd_attr);
	error_stamp(ctrl_var, 0, "Hrtd HEADSHOT MISSED");

	// wait for task to terminate
	pthread_join(osc, NULL);
	pthread_join(gra, NULL);
	pthread_join(hdlr, NULL);
	pthread_join(flt, NULL);
	pthread_join(ado, NULL);

	return 0;
}
