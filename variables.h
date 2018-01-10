//-------------------------------------
//			Global Variables          -
//-------------------------------------
// Control variables
int end = 0;
int hold = 0;
// Synth control variable
int wave_sel = 0;
int wave_sel_2 = 0;
int filter_sel = 0;
int filter_sel_2 = 0;

// Values variables
float amplitude = 0;
float amplitude_2 = 0;
float pitch = 1;
float pitch_2 = 1;

// frequency Hz
float wave_f = 0;

// circular arrays OSC1, OSC2, filter1, filter2
// FILE "circular_array.c"
c_queue wave_va;
c_queue wave_va_2;
c_queue wave_va_flt;
c_queue wave_va_2_flt;

// semaphores
sem_t end_s;
sem_t wave_s;
sem_t wave_2;
sem_t pitch_s;
sem_t filter_s;
sem_t filter_2_s;
sem_t wave_f_s;
sem_t pitch_2_s;
sem_t wave_sel_s;
sem_t amplitude_s;
sem_t draw_wave_s;
sem_t wave_sel_2_s;
sem_t amplitude_2_s;
// synch thread
sem_t sync_1_s;
sem_t sync_2_s;