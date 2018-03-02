#include "osc_f.h"
#include "periodic.h"
#include "audio_var.h"
#include "circular_array.h"
#include "variables.h"
#include "wave_gen.h"
#include "time_press.h"

void *osc_f(void *arg){
	// float x = 0;
	struct periodic_info info;
	double ff_1, ff_2;
	float val_1 = 0;
	float val_2 = 0;
	float all_2 = 0;

	// make task periodic from file "periodic.c"
	make_periodic(SAMPL, &info);

	// generating sample increment
	while (end == 0){

		// return sample time from "wave_gen.c"
		all_2 = get_time_press(hold);

		// get frequency considering pitch

		// multiply frequency 1 for pitch 1
		ff_1 = wave_f * pitch;
		// multiply frequency 2 for pitch 2
		ff_2 = wave_f * pitch_2;

		// generating waves
		// FILE "wave_gen.c"
		wave_gen_f(wave_sel, amplitude, all_2, ff_1, &val_1);
		wave_gen_f(wave_sel_2, amplitude_2, all_2, ff_2, &val_2);

		// insert values into global arrays FILE "cirular_array.c"
		// OSC1
		insert_CA(&wave_va, val_1);
		//OSC2
		insert_CA(&wave_va_2, val_2);

		// wait period setted in make_periodic() at the beginning of this file
		// FILE "periodic.c"
		wait_period(&info);
	}
}
