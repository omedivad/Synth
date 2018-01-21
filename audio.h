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
#define BUFFER_LEN 4096


// Sampling constants ns 1000000000.0 / 48000.0
#define SAMPL 20833.333333333332

// #define SAMPL 22675.736961451246
// frequency
#define F_SAMPL 48000.0
// #define F_SAMPL 44100.0

// define number of audio fragments for the audio channel, used in all_init.c in function: al_create_audio_stream()
#define AUDIO_FRAG 2

// crete pointer to allegro audio stream
ALLEGRO_AUDIO_STREAM *stream;
// set number og channel for streaming
ALLEGRO_AUDIO_DEPTH chan_conf = ALLEGRO_CHANNEL_CONF_1;
// set audio channel type of data (float: value between -1 and 1)
ALLEGRO_AUDIO_DEPTH depth = ALLEGRO_AUDIO_DEPTH_FLOAT32; 
// set number of samples for audio channel
int samples = BUFFER_LEN - 1024; // allow to change the buffer from control screen (for future developement)