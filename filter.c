void *filter_f(void *arg){
	struct periodic_info info;
	make_periodic(SAMPL, &info);
	int hd, j;
	float tmp;
	int end_l = 0;

	while(end_l == 0){

		sem_wait(&sync_1_s);

		// osc 1 
		switch(filter_sel){
			case NFLT:
				insert_CA(&wave_va_flt, extract_CA(&wave_va));
				break;
			case HPF:
				hd = get_tail(&wave_va);
				tmp = 0;
				for(int i=0; i<=HBL; i++){
					// inverse index
					j = hd - i % BUFFER_LEN;
					tmp += HB[i] * extract_n_CA(&wave_va, j);
				}
				increase_tail(&wave_va);
				insert_CA(&wave_va_flt, tmp);
				break;
			case LPF:
				hd = get_tail(&wave_va);
				tmp = 0;
				for(int i=0; i<=LBL; i++){
					// inverse index
					j = hd - i % BUFFER_LEN;
					tmp += LB[i] * extract_n_CA(&wave_va, j);
				}
				increase_tail(&wave_va);
				insert_CA(&wave_va_flt, tmp);
				break;
		}

		// OSC 2
		switch(filter_sel_2){
			case NFLT:
				insert_CA(&wave_va_2_flt, extract_CA(&wave_va_2));
				break;
			case HPF:
				hd = get_tail(&wave_va_2);
				tmp = 0;
				for(int i=0; i<=HBL; i++){
					// inverse index
					j = hd - i % BUFFER_LEN;
					tmp += HB[i] * extract_n_CA(&wave_va_2, j);
				}
				increase_tail(&wave_va_2);
				insert_CA(&wave_va_2_flt, tmp);
				break;
			case LPF:
				hd = get_tail(&wave_va_2);
				tmp = 0;
				for(int i=0; i<=LBL; i++){
					// inverse index
					j = hd - i % BUFFER_LEN;
					tmp += LB[i] * extract_n_CA(&wave_va_2, j);
				}
				increase_tail(&wave_va_2);
				insert_CA(&wave_va_2_flt, tmp);
				break;
		}

		sem_wait(&end_s);
      		end_l = end;
    	sem_post(&end_s);

    	sem_post(&sync_2_s);

		wait_period(&info);
	}
}