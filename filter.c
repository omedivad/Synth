void *filter_f(void *arg){
	struct periodic_info info;
	make_periodic(SAMPL, &info);
	int hd, j, i;
	float tmp;
	c_queue wave_flt_l_1, wave_flt_l_2;

	init_CA(&wave_flt_l_1);
	init_CA(&wave_flt_l_2);

	//	only the first filter is commented, the others follow the same logic

	while(end == 0){

		/*	note that values from shared memory buffers are stored in local arrays due to the need of the filter to know the values of
			300 previous sample. In fact this operation would be lock shared memory buffer for a lot of time if performed directly on them */

		// storing shared memory buffers values into local buffers
		insert_CA(&wave_flt_l_1, extract_CA(&wave_va));
		insert_CA(&wave_flt_l_2, extract_CA(&wave_va_2));


			// osc 1 
			switch(filter_sel){
				// no filter
				case NFLT:
					// pass value from osc to filter buffer to filter to audio out buffer
					tmp = extract_CA(&wave_flt_l_1);
					insert_CA(&wave_va_flt, tmp);
					break;
				case HPF:
					// get head
					hd = get_tail(&wave_flt_l_1);
					//set temp to 0
					tmp = 0;
					// loop for the amount of prevoius sample the filter needs
					for(i = 0; i < HBL; i++){
						// inverse index, note that this forumla avoid calulated index to be negative
						j = ((hd - i) % BUFFER_LEN + BUFFER_LEN) % BUFFER_LEN;
						// the first value in the 
						// convolution
						if(j > 0){
							tmp += HB[i] * extract_n_CA(&wave_flt_l_1, j);
						}
					}
					// increase tail for next extraction
					increase_tail(&wave_flt_l_1);
					//insert filtered value in filter to audio_out
					insert_CA(&wave_va_flt, tmp);
					break;
				case LPF:
					hd = get_tail(&wave_flt_l_1);
					tmp = 0;
					for(i = 0; i < LBL; i++){
						// inverse index, note that this forumla avoid calulated index to be negative
						j = ((hd - i) % BUFFER_LEN + BUFFER_LEN) % BUFFER_LEN;
						//convolution product
						if(j > 0){
							tmp += LB[i] * extract_n_CA(&wave_flt_l_1, j);
						}
					}
					increase_tail(&wave_flt_l_1);
					insert_CA(&wave_va_flt, tmp);
					break;
			}

			// osc 1 
			switch(filter_sel_2){
				case NFLT:
					tmp = extract_CA(&wave_flt_l_2);
					insert_CA(&wave_va_2_flt, tmp);

					break;
				case HPF:
					hd = get_tail(&wave_flt_l_2);
					tmp = 0;
					for(i = 0; i < HBL; i++){
						// inverse index
						j = ((hd - i) % BUFFER_LEN + BUFFER_LEN) % BUFFER_LEN;
						if(j > 0){
							tmp += HB[i] * extract_n_CA(&wave_flt_l_2, j);
						}
					}
					increase_tail(&wave_flt_l_2);
					insert_CA(&wave_va_2_flt, tmp);
					break;
				case LPF:
					hd = get_tail(&wave_flt_l_2);
					tmp = 0;
					for(i = 0; i < LBL; i++){
						// inverse index
						j = ((hd - i) % BUFFER_LEN + BUFFER_LEN) % BUFFER_LEN;
						if(j > 0){
							tmp += LB[i] * extract_n_CA(&wave_flt_l_2, j);
						}
					}
					increase_tail(&wave_flt_l_2);
					insert_CA(&wave_va_2_flt, tmp);
					break;
			}
		// wait for task period
		wait_period(&info);
	}
}
