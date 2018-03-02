#include <allegro5/allegro_audio.h>
#include "variables_init.h"
#include "circular_array.h"
#include "variables.h"
#include "graph_v_c.h"

void variables_init()
{
	// variables.h
	end = 0;
	hold = 0;
	wave_sel = 0;
	wave_sel_2 = 0;
	filter_sel = 0;
	filter_sel_2 = 0;
	amplitude = 0;
	amplitude_2 = 0;
	pitch = 1;
	pitch_2 = 1;
	wave_f = 0;
	draw_wave = 0;

	// audio_var.h
	chan_conf = ALLEGRO_CHANNEL_CONF_1;
	depth = ALLEGRO_AUDIO_DEPTH_FLOAT32; 
	samples = BUFFER_LEN - 1024;

	// graph_v_c.h
	display = NULL;
	disp_key = NULL;
	event_queue = NULL;
}