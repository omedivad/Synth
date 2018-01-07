void *filter_f(void *arg){
	struct periodic_info info;
	make_periodic(SAMPL, &info);
	int hd, j;
	float tmp;

	while(end == 0){

		// osc 1 
		switch(filter_sel){
			case 0:
				insert_CA(&wave_va_flt, extract_CA(&wave_va));
				break;
			case 1:
				hd = get_tail(&wave_va);
				tmp = 0;
				for(int i=0; i<=HBL; i++){
					// inverse index
					j = hd - i % BUFFER_LEN;

					if (j >= 0){  //  bounds check for input buffer
						tmp += HB[i] * extract_n_CA(&wave_va, j);
					}
				}
				increase_tail(&wave_va);
				insert_CA(&wave_va_flt, tmp);
				break;
			case 2:
				hd = get_tail(&wave_va);
				tmp = 0;
				for(int i=0; i<=LBL; i++){
					// inverse index
					j = hd - i % BUFFER_LEN;

					if (j >= 0){  //  bounds check for input buffer
						tmp += LB[i] * extract_n_CA(&wave_va, j);
					}
				}
				increase_tail(&wave_va);
				insert_CA(&wave_va_flt, tmp);
				break;
		}

		// OSC 2
		switch(filter_sel_2){
			case 0:
				insert_CA(&wave_va_2_flt, extract_CA(&wave_va_2));
				break;
			case 1:
				hd = get_tail(&wave_va_2);
				tmp = 0;
				for(int i=0; i<=HBL; i++){
					// inverse index
					j = hd - i % BUFFER_LEN;

					if (j >= 0){  //  bounds check for input buffer
						tmp += HB[i] * extract_n_CA(&wave_va_2, j);
					}
				}
				increase_tail(&wave_va_2);
				insert_CA(&wave_va_2_flt, tmp);
				break;
			case 2:
				hd = get_tail(&wave_va_2);
				tmp = 0;
				for(int i=0; i<=LBL; i++){
					// inverse index
					j = hd - i % BUFFER_LEN;

					if (j >= 0){  //  bounds check for input buffer
						tmp += LB[i] * extract_n_CA(&wave_va_2, j);
					}
				}
				increase_tail(&wave_va_2);
				insert_CA(&wave_va_2_flt, tmp);
				break;
		}

		wait_period(&info);
	}
}