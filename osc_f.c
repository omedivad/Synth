void *osc_f(void *arg){	
	int p = 0;
	float x = 0;
	int end_l = 0;
	int sel, sel_2;
	struct periodic_info info;
	float amp, amp_2, freq, ff, ff_2, ptc, ptc_2;
	float val = 0;
	float val_2 = 0;

	srand(time(NULL));
	make_periodic(SAMPL, &info);

	// generating sample increment
	while (end_l == 0){
		if(hold == 1){
			x = x + (1.0 / 48000.0);
			p = 1;
		}
		if(hold == 0){
			x = 0;
			p = 0;
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
			ptc = pitch;
		sem_post(&pitch_s);
		sem_wait(&pitch_2_s);
			ptc_2 = pitch_2;
		sem_post(&pitch_2_s);

		ff = freq * ptc;
		ff_2 = freq * ptc_2;

		// wave generator
		switch(sel){
			case SIN:
				if(amp == 0){
					val = 0;
				}else{
					val = amp * sin(2 * PI * x * ff);
				}
				break;
			case SQR:
				if(sin(2 * PI * ff * x) > 0 && amp != 0){
					val = amp * 1;
				}else{
					val = 0;
				}
				break;
			case SAW:
				if(amp == 0){
					val = 0;
				}else{
					val = amp * fmod(x, 1 / ff) * ff;
				}
				break;
			case NSE:
				if(amp == 0){
					val = 0;
				}else{
					val = amp * (float)rand() / (float)(RAND_MAX / 1) * p;
				}
				break;
		}
		switch(sel_2){
			case SIN:
				if(amp_2 == 0){
					val_2 = 0;
				}else{
					val_2 = amp_2 * sin(2 * PI * ff_2 * x);
				}
				break;
			case SQR:
				if(sin(2 * PI * ff_2 * x) > 0 && amp_2 != 0){
					val_2 = amp_2 * 1;
				}else{
					val_2 = 0;
				}
				break;
			case SAW:
				if(amp_2 == 0){
					val_2 = 0;
				}else{
					val_2 = amp_2 * fmod(x, 1 / ff_2) * ff_2;
				}
				break;
			case NSE:
				if(amp_2 == 0){
					val_2 = 0;
				}else{
					val_2 = amp_2 * (float)rand() / (float)(RAND_MAX / 1) * p;
				}
				break;
		}
		// insert values into global arrays
		insert_CA(&wave_va, val);
		insert_CA(&wave_va_2, val_2);
		
		// end to local varialbe
		sem_wait(&end_s);
      		end_l = end;
    	sem_post(&end_s);

		wait_period(&info);
	}
}