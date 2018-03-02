#include <math.h> 
#include "wave_gen.h"
#include "audio.h"
#include "circular_array.h"
#include "variables.h"

void wave_gen_f(int sel, double amp, double all_2, double ff, float *val){

	// generating waves according to wave selected by user. 'sel' is the selected wave variable
	switch(sel){
		case SIN:
			// generating sine wave
			if(amp == 0){
				*val = 0;
			}else{
				*val = amp * sin(2 * PI * all_2 * ff);
			}
			break;
		case SQR:
			// generating sqare wave
			if(sin(2 * PI * ff * all_2) > 0 && amp != 0){
				*val = amp * 1;
			}else{
				*val = 0;
			}
			break;
		case SAW:
			// generating sawtooth wave
			if(amp == 0){
				*val = 0;
			}else{
				*val = amp * fmod(all_2, 1 / ff) * ff;
			}
			break;
		case NSE:
			// generating white noise
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