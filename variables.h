//-------------------------------------------
//			Global Variables          		-
//-------------------------------------------
//------------ Control variables ------------
// used to kill threads
int end = 0;
// used to know it a button is still pressed
int hold = 0;
//--------- Synth control variables ---------
// store number relative to OSC1 wave type
int wave_sel = 0;
// store number relative to OSC2 wave type
int wave_sel_2 = 0;
// store number relative to OSC1 filter type
int filter_sel = 0;
// store number relative to OSC2 filter type
int filter_sel_2 = 0;

//---------- Synth vales variables ----------
// OSC1 amplitude (0 to 1)
float amplitude = 0;
// OSC2 amplitude (0 to 1)
float amplitude_2 = 0;
// OSC1 pitch (0 to 4)
float pitch = 1;
// OSC2 pitch (0 to 4)
float pitch_2 = 1;

// frequency Hz
float wave_f = 0;

// control draw wave
int draw_wave = 0;

// circular arrays aka shared buffers
// FILE "circular_array.c"
// buffer osc1 to filter1
c_queue wave_va;
// buffer osc2 to filter2
c_queue wave_va_2;
// buffer filter1 to out
c_queue wave_va_flt;
// buffer ilter2 to out
c_queue wave_va_2_flt;

// semaphores for global(shared) variables
sem_t end_s;
sem_t hold_s;
sem_t pitch_s;
sem_t filter_s;
sem_t wave_f_s;
sem_t samples_s;
sem_t pitch_2_s;
sem_t filter_2_s;
sem_t wave_sel_s;
sem_t amplitude_s;
sem_t draw_wave_s;
sem_t wave_sel_2_s;
sem_t amplitude_2_s;

/*	Truly, some of these semaphores are not needed, beacause there is only one thread that write on the relative shared resource,
	and one that read. However, sem have been implemented for possible future implementation */