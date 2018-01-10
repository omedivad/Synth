double wave_gen_f(int sel, double amp, double all_2, double ff, double *val){

	switch(sel){
		case SIN:
			if(amp == 0){
				*val = 0;
			}else{
				*val = amp * sin(2 * PI * all_2 * ff);
			}
			break;
		case SQR:
			if(sin(2 * PI * ff * all_2) > 0 && amp != 0){
				*val = amp * 1;
			}else{
				*val = 0;
			}
			break;
		case SAW:
			if(amp == 0){
				*val = 0;
			}else{
				*val = amp * fmod(all_2, 1 / ff) * ff;
			}
			break;
		case NSE:
			if(amp == 0){
				*val = 0;
			}else{
				if(all_2 > 0)
					all_2 = 1;
				*val = amp * (float)rand() / (float)(RAND_MAX / 1) * all_2;
			}
			break;
	}
}