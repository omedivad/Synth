void *audio_f(void *arg){
	struct periodic_info info;
	int flag = 0;

    snd_pcm_t *handle;
    snd_pcm_sframes_t frames;

    int err;
    float buffer[BUFFER_LEN];

	make_periodic(SAMPL, &info);

	// ERROR HANDLING

	// opening audio streaming
    if ((err = snd_pcm_open(&handle, device, SND_PCM_STREAM_PLAYBACK, 0)) < 0) {
            printf("Playback open error: %s\n", snd_strerror(err));
            exit(EXIT_FAILURE);
    }

    // setting parameters
    if ((err = snd_pcm_set_params(handle, SND_PCM_FORMAT_FLOAT, SND_PCM_ACCESS_RW_INTERLEAVED, 1, S_F, 0, LATENCY_MS)) < 0) {   
        printf("Playback open error: %s\n", snd_strerror(err));
    	exit(EXIT_FAILURE);
    }

	while(end == 0){
		if(wave_va.num >= BUFFER_LEN_AUDIO && wave_va_2.num >= BUFFER_LEN_AUDIO){
			for (int i = 0; i < BUFFER_LEN_AUDIO; i++){
				// writing wave on buffer
				buffer[i] = extract_CA(&wave_va) + extract_CA(&wave_va_2);
			}
		}

		// writing 
		frames = snd_pcm_writei(handle, buffer, BUFFER_LEN);
    	if (frames < 0){
        	frames = snd_pcm_recover(handle, frames, 0);
    	}
    	if (frames < 0) {
        	printf("snd_pcm_writei failed: %s\n", snd_strerror(frames));
        break;
    	}
    	if (frames > 0 && frames < BUFFER_LEN){
        	printf("Short write (expected %li, wrote %li)\n", BUFFER_LEN, frames);
    	}

		wait_period(&info);
	}

	snd_pcm_close(handle);
}