#include <allegro5/allegro_audio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include "audio.h"
#include "periodic.h"
#include "audio_var.h"
#include "circular_array.h"
#include "variables.h"

void *audio_f(void *arg){
	struct periodic_info info;
	float *buffer;
	float wave_1, wave_2, wave_final;
	int i;
	// creating pointer to queue data type
	ALLEGRO_EVENT_QUEUE *queue;

	// stream to mixer
	al_attach_audio_stream_to_mixer(stream, al_get_default_mixer());
	
	// make task periodic
	make_periodic(SAMPL, &info);

	// play stream
	al_set_audio_stream_playing(stream, true);

	// creating event queue
	queue = al_create_event_queue();

	// register event stream in queue
   	al_register_event_source(queue, al_get_audio_stream_event_source(stream));

   	// creating allegro event
	ALLEGRO_EVENT aud_eve;
	while(end == 0){

		// note that it's not possible to store value in a local array and transfer those value in buffer because of allegro syntax

		// wait for event registered in "queue" and put it into "aud_eve" event
		al_wait_for_event(queue, &aud_eve);
		if(wave_va_flt.num >= samples && wave_va_2_flt.num >= samples && aud_eve.type == ALLEGRO_EVENT_AUDIO_STREAM_FRAGMENT){
			// assigning fragment to buffer array
			buffer = al_get_audio_stream_fragment(stream);

			for (i = 0; i < samples; i++){
				// extraction of OSC1 filtered value
				wave_1 = extract_CA(&wave_va_flt);
				// extraction of OSC2 filtered value
				wave_2 = extract_CA(&wave_va_2_flt);
				// ALLEGRO_AUDIO_DEPTH_FLOAT32 accept values [-1, 1] so after summing OSC1 and OSC2 values normalizzation is needed
				wave_final = ((wave_1 + wave_2) / 2);
				buffer[i] = wave_final;
				// buffer[i] = (short)(wave_final * 32767); // cast from FLOAT32 to INT16s
			}
			if (!al_set_audio_stream_fragment(stream, buffer)){
		    		printf("Error setting stream fragment.\n");
		 	}
		}

		// wait for period
		wait_period(&info);
	}

	// destroy
	al_destroy_audio_stream(stream);
	al_uninstall_audio();
}
