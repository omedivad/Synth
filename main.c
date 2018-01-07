#include "header.h"

void init_hrt_attr(pthread_attr_t *rt_attr, struct sched_param *hrt_param, int n);
void init_allegro(void);


int main(void){
	
	// pthreads
	pthread_t osc, gra, hdlr,flt, ado;
	pthread_attr_t hrt_attr, rt_attr;
	struct sched_param hrt_param, rt_param;

	// initializing OSC1 and OSC2 data array
	init_CA(&wave_va);
	init_CA(&wave_va_2);

	init_CA(&wave_va_flt);
	init_CA(&wave_va_2_flt);

	// initialize semaphores
	sem_init(&wave, 0 , 1);
	sem_init(&wave_f_s, 0 , 1);
	sem_init(&wave_sel_s, 0 , 1);
	sem_init(&wave_sel_2_s, 0 , 1);
	sem_init(&amplitude_s, 0 , 1);
	sem_init(&amplitude_2_s, 0 , 1);
	sem_init(&pitch_s, 0 , 1);
	sem_init(&pitch_2_s, 0 , 1);

	// initialize graphic
    graphic_init();

    // set attr for rt threads
	init_hrt_attr(&hrt_attr, &hrt_param, 99);
	init_hrt_attr(&rt_attr, &rt_param, 80);

	//create threads

	pthread_create(&osc, &hrt_attr, osc_f, NULL);
	//perror("ER_osc");

	pthread_create(&gra, &hrt_attr, graphic_f, NULL);
	//perror("ER_gra");

   	pthread_create(&hdlr, &hrt_attr, handler_f, NULL);
	// perror("ER_hdlr");

	pthread_create(&flt, &hrt_attr, filter_f, NULL);
	perror("filter");

	pthread_create(&ado, &hrt_attr, audio_f, NULL);
	perror("audio");


	// destroy attr.s no longer useful
	ctrl_var = pthread_attr_destroy(&rt_attr);
	error_stamp(ctrl_var, 0, "b");
	ctrl_var = pthread_attr_destroy(&hrt_attr);
	error_stamp(ctrl_var, 0, "b_1");

	pthread_join(hdlr, NULL);

	return 0;
}