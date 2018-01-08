void *osc_f(void *arg){	
	struct periodic_info info;
	struct timeval tv, tv_1; 
	long long unsigned time_start;
	float global_t;
	// global clock
	float val, val_2;
	float freq, ff, ff_2;
	int sel = 0;
	int sel_2 = 0;
	int amp, amp_2, ptc, ptc_2;
	float x = 0;
	double gloabal_t = 0;

	make_periodic(SAMPL, &info);

	printf("osc thread started \n");

	gettimeofday(&tv, NULL);
	time_start = (unsigned long long)(tv.tv_sec) * 1000 + (unsigned long long)(tv.tv_usec) / 1000;

	// generating sample increment
	while (end == 0){

		if(hold == 1){
			x = x + (1.0 / 48000.0);
			gettimeofday(&tv_1, NULL);
			global_t = (float)(((unsigned long long)(tv_1.tv_sec) * 1000 + (unsigned long long)(tv_1.tv_usec) / 1000) - time_start) / 1000;

 			printf("%lf time\n", global_t);

		}
		if(hold == 0){
			x = 0;
			// gettimeofday(&tv, NULL);
			// time_start = (unsigned long long)(tv.tv_sec) * 1000 + (unsigned long long)(tv.tv_usec) / 1000;
  			global_t = 0;

		}
		
		// copying global data to local variables
		
		sem_wait(&wave_f_s);
			freq = wave_f;
		sem_post(&wave_f_s);
		sem_wait(&wave_sel_s);
			sel = wave_sel;
		sem_post(&wave_sel_s);
		sem_wait(&wave_sel_2_s);
			sel_2 = wave_sel_2;
		sem_post(&wave_sel_2_s);
		sem_wait(&amplitude_s);
			amp = amplitude;
		sem_post(&amplitude_s);
		sem_wait(&amplitude_2_s);
			amp_2 = amplitude_2;
		sem_post(&amplitude_2_s);
		sem_wait(&pitch_s);
			ptc = ptc;
		sem_post(&pitch_s);
		sem_wait(&pitch_2_s);
			ptc_2 = pitch_2;
		sem_post(&pitch_2_s);

		ff = freq * pitch;
		ff_2 = freq * pitch_2;

		// wave generator
		switch(sel){
			case 0:
				val = amp * sin(2 * PI * x * ff);
				break;
			case 1:
				if(sin(2 * PI * ff * x) > 0){
					val = 1;
				}else{
					val = 0;
				}
				break;
			case 2:
				val = amp * fmod(x, 1 / ff) * ff;
				break;
		}
		switch(sel_2){
			case 0:
				val_2 = amp_2 * sin(2 * PI * ff_2 * x);
				break;
			case 1:
				if(sin(2 * PI * ff_2 * x) > 0){
					val_2 = amp_2 * 1;
				}else{
					val_2 = amp_2 * 0;
				}
				break;
			case 2:
				val_2 = amp_2 * fmod(x, 1 / ff_2) * ff_2;
				break;
		}

		// inser values into global arrays
		insert_CA(&wave_va, val);
		insert_CA(&wave_va_2, val_2);
		

		wait_period(&info);
	}
}