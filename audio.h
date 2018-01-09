//-------------------------------------
//			Global Constants          -
//-------------------------------------
// Waves code definition
#define SIN 0
#define SQR 1
#define SAW 2
#define NSE 3
#define TRN 4

// Filters code definition
#define NFLT 0
#define HPF	 1
#define LPF	 2

// Pi
#define PI 3.14159265359

// buffer lenght
#define BUFFER_LEN 600
#define BUFFER_LEN_AUDIO 2

// Sampling constants ns 1000000000.0 / 48000.0
#define SAMPL 20833.333333333332

// frequency
#define F_SAMPL 48000

#define AUDIO_FRAG 8

ALLEGRO_AUDIO_STREAM *stream;
ALLEGRO_AUDIO_DEPTH chan_conf = ALLEGRO_CHANNEL_CONF_2;
ALLEGRO_AUDIO_DEPTH depth = ALLEGRO_AUDIO_DEPTH_FLOAT32; 
int samples = BUFFER_LEN;
int frequency = 48000;