// Here all global constants and variables are setted

//-------------------------------------
//			Global Constants          -
//-------------------------------------

// Waves code definition
#define SIN_C 0
#define SQR_C 1
#define TRN_C 2
#define SWT_C 3
#define NSE_C 4

// Filters code definition
#define HPF_C 0
#define LPF_C 1
#define BPF_C 2

// Sampling constants ms
#define SAMPL 20.833333333333332
// #define SAMPL 22.675736961451246
#define S_F 48000
// #define S_F 44100

// Pi
#define PI 3.14159265359



//-------------------------------------
//			Global Variables          -
//-------------------------------------

// Control variables
int wave_sel = 0;
int wave_sel_2 = 0;
int filter_sel = 1;
int filter_sel_2 = 0;

// Error handler variables
int ctrl_var = 0;
int all_ctrl_var = 0;
int i=1;

// Values variables
float amplitude;
float amplitude_2;
int pitch = 1;
int pitch_2 = 1;

int hold = 0;

// frequency Hz
float wave_f = 440;

// global clock
long long unsigned int global_t;

int end = 0;

// circular arrays (OSC1, OSC2)
c_queue wave_va;
c_queue wave_va_2;

c_queue wave_va_flt;
c_queue wave_va_2_flt;

sem_t wave;
sem_t wave_2;
sem_t wave_f_s;
sem_t wave_sel_s;
sem_t wave_sel_2_s;
sem_t amplitude_s;
sem_t amplitude_2_s;
sem_t pitch_s;
sem_t pitch_2_s;
sem_t filter_s;
sem_t filter_2_s;

// audio
static char *device = "default";                       //soundcard
snd_output_t *output = NULL;