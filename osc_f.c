#include "time_press.c"
#include "wave_gen.c"

void *osc_f(void *arg){
	float x = 0;
	int end_l = 0;
	int sel, sel_2;
	struct periodic_info info;
	double amp, amp_2, freq, ff, ff_2, ptc, ptc_2;
	double val = 0;
	double val_2 = 0;
	double all_2 = 0;

	srand(time(NULL));
	make_periodic(SAMPL, &info);

	// generating sample increment
	while (end_l == 0){

		sem_wait(&hold_s);
			all_2 = get_time_press(hold);
		sem_post(&hold_s);

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

		// generating waves
		// FILE "wave_gen.c"
		wave_gen_f(sel, amp, all_2, ff, &val);
		wave_gen_f(sel_2, amp_2, all_2, ff_2, &val_2);

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
