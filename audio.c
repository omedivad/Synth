void *audio_f(void *arg){
	struct periodic_info info;
	float *buffer;
	float wave_1, wave_2, wave_final;
	ALLEGRO_EVENT_QUEUE *queue;
	int end_l = 0;

	al_attach_audio_stream_to_mixer(stream, al_get_default_mixer());
	
	make_periodic(SAMPL, &info);

	al_set_audio_stream_playing(stream, true);

	queue = al_create_event_queue();
   	al_register_event_source(queue, al_get_audio_stream_event_source(stream));

	while(end_l == 0){

		ALLEGRO_EVENT aud_eve;
		al_wait_for_event(queue, &aud_eve);

		if(wave_va_flt.num >= samples && wave_va_2_flt.num >= samples && aud_eve.type == ALLEGRO_EVENT_AUDIO_STREAM_FRAGMENT){
			buffer = al_get_audio_stream_fragment(stream);

			for (int i = 0; i < samples; i++){
				wave_1 = extract_CA(&wave_va_flt);
				wave_2 = extract_CA(&wave_va_2_flt);
				wave_final = ((wave_1 + wave_2) / 2);
				buffer[i] = wave_final;
				// buffer[i] = (short)(wave_final * 32767); // cast from FLOAT32 to INT16s
			}
			if (!al_set_audio_stream_fragment(stream, buffer)){
		    		printf("Error setting stream fragment.\n");
		 	}
		}
		sem_wait(&end_s);
      			end_l = end;
    		sem_post(&end_s);

		wait_period(&info);
	}

	al_destroy_audio_stream(stream);
	al_uninstall_audio();
}
