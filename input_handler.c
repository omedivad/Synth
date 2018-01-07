void *handler_f(void *arg){
	ALLEGRO_MOUSE_STATE state;
	struct periodic_info info;
	float mouse_old = 0;
	float mouse_old_2 = 0;
	int press = 0;
	int press_2 = 0;
	int press_11 = 0;
	int press_22 = 0;

	printf("%s\n","handler started" );

	make_periodic(30, &info);
	while(end == 0){

		// handling dropdown menu
		// al_wait_for_event_timed(event_queue, &ev, 0.03);
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP && XUPL_1 + 95 < ev.mouse.x && ev.mouse.x < XUPL_1 + 190 && YUPL_1 + 2 < ev.mouse.y && ev.mouse.y < YUPL_1 + 22) {
		    /* Primary (e.g. left) mouse button is held. */
		    sem_wait(&wave_sel_s);
		    	wave_sel = 0;
		    sem_post(&wave_sel_s);
		}
		if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP && XUPL_1 + 195 < ev.mouse.x && ev.mouse.x < XUPL_1 + 285 && YUPL_1 + 2 < ev.mouse.y && ev.mouse.y < YUPL_1 + 22) {
		    /* Primary (e.g. left) mouse button is held. */
		    sem_wait(&wave_sel_s);
		    	wave_sel = 1;
		    sem_post(&wave_sel_s);
		}
		if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP && XUPL_1 + 290 < ev.mouse.x && ev.mouse.x < XUPL_1 + 380 && YUPL_1 + 2 < ev.mouse.y && ev.mouse.y < YUPL_1 + 22) {
		    /* Primary (e.g. left) mouse button is held. */
		    sem_wait(&wave_sel_s);
		    	wave_sel = 2;
		    sem_post(&wave_sel_s);
		}
		if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP && XUPL_1 + 495 < ev.mouse.x && ev.mouse.x < XUPL_1 + 590 && YUPL_1 + 2 < ev.mouse.y && ev.mouse.y < YUPL_1 + 22) {
		    /* Primary (e.g. left) mouse button is held. */
		    sem_wait(&wave_sel_2_s);
		    	wave_sel_2 = 0;
		    sem_post(&wave_sel_2_s);
		}
		if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP && XUPL_1 + 595 < ev.mouse.x && ev.mouse.x < XUPL_1 + 685 && YUPL_1 + 2 < ev.mouse.y && ev.mouse.y < YUPL_1 + 22) {
		    /* Primary (e.g. left) mouse button is held. */
		    sem_wait(&wave_sel_2_s);
		    	wave_sel_2 = 1;
		    sem_post(&wave_sel_2_s);
		}
		if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP && XUPL_1 + 690 < ev.mouse.x && ev.mouse.x < XUPL_1 + 780 && YUPL_1 + 2 < ev.mouse.y && ev.mouse.y < YUPL_1 + 22) {
		    /* Primary (e.g. left) mouse button is held. */
		    sem_wait(&wave_sel_2_s);
		    	wave_sel_2 = 2;
		    sem_post(&wave_sel_2_s);
		}

		// handling volume 1 knob
		if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN && ev.mouse.y <= sqrt(pow(20, 2)- pow(ev.mouse.x - 350, 2)) + 100 && ev.mouse.y >= - sqrt(pow(20, 2)- pow(ev.mouse.x - 350, 2)) + 100 && press != 1) {
		    /* Primary (e.g. left) mouse button is held. */
		    al_get_mouse_state(&state);
		    press = 1;
		    mouse_old = -state.y;
		    printf("%d mouse old \n", mouse_old);
		}

		if(press == 1){
			al_get_mouse_state(&state);
			sem_wait(&amplitude_s);
		    	amplitude = amplitude - (float)state.y - mouse_old;
		    	if (amplitude >= 1) amplitude = 1;
		    	if (amplitude <= 0) amplitude = 0;
	    	sem_post(&amplitude_s);
		    mouse_old = -state.y;
		    printf("%f mouse old \n", mouse_old);
		    printf("%d\n", press);
		    sem_wait(&amplitude_s);
		    	printf("%f amplitude\n", amplitude);
	    	sem_post(&amplitude_s);
		    printf("%d\n", -state.y);
		    if(!al_mouse_button_down(&state, 1)){
	    		press = 0;
	    		printf("%d\n", press);
			}
		}

		//handling vol 2 knob

		if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN && ev.mouse.y <= sqrt(pow(20, 2)- pow(ev.mouse.x - (400 + 350), 2)) + 100 && ev.mouse.y >= - sqrt(pow(20, 2)- pow(ev.mouse.x - (400 + 350), 2)) + 100 && press_2 != 1) {
		    /* Primary (e.g. left) mouse button is held. */
		    al_get_mouse_state(&state);
		    press_2 = 1;
		    mouse_old_2 = -state.y;
		    printf("%d mouse old \n", mouse_old_2);
		}

		if(press_2 == 1){
			al_get_mouse_state(&state);
			sem_wait(&amplitude_2_s);
		    	amplitude_2 = amplitude_2 - (state.y + mouse_old_2);
		    	if (amplitude_2 >= 1.0) amplitude_2 = 1.0;
		    	if (amplitude_2 <= 0.0) amplitude_2 = 0.0;
	    	sem_post(&amplitude_2_s);
		    mouse_old_2 = -state.y;
		    printf("%d mouse old \n", mouse_old_2);
		    printf("%d\n", press_2);
		    sem_wait(&amplitude_2_s);
		    	printf("%d amplitude_2\n", amplitude_2);
	    	sem_post(&amplitude_2_s);
		    printf("%d\n", -state.y);
		    if(!al_mouse_button_down(&state, 1)){
	    		press_2 = 0;
	    		printf("%d\n", press_2);
			}
		}

		// handling pitch 1 knob

		if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN && ev.mouse.y <= sqrt(pow(20, 2)- pow(ev.mouse.x - 250, 2)) + 100 && ev.mouse.y >= - sqrt(pow(20, 2)- pow(ev.mouse.x - 250, 2)) + 100 && press_11 != 1) {
		    /* Primary (e.g. left) mouse button is held. */
		    al_get_mouse_state(&state);
		    press_11 = 1;
		    mouse_old = -state.y;
		    printf("%d mouse old \n", mouse_old);
		}

		if(press_11 == 1){
			al_get_mouse_state(&state);
			sem_wait(&pitch_s);
		    	pitch = pitch - state.y - mouse_old;
		    	if (pitch >= 11) pitch = 11;
		    	if (pitch < 1) pitch = 1;
	    	sem_post(&pitch_s);
		    mouse_old = -state.y;
		    printf("%d mouse old \n", mouse_old);
		    printf("%d\n", press_11);
		    sem_wait(&pitch_s);
		    	printf("%d pitch\n", pitch);
	    	sem_post(&pitch_s);
		    printf("%d\n", -state.y);
		    if(!al_mouse_button_down(&state, 1)){
	    		press_11 = 0;
	    		printf("%d\n", press);
			}
		}

		//handling pitch 2 knob

		if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN && ev.mouse.y <= sqrt(pow(20, 2)- pow(ev.mouse.x - (400 + 250), 2)) + 100 && ev.mouse.y >= - sqrt(pow(20, 2)- pow(ev.mouse.x - (400 + 250), 2)) + 100 && press_22 != 1) {
		    /* Primary (e.g. left) mouse button is held. */
		    al_get_mouse_state(&state);
		    press_22 = 1;
		    mouse_old_2 = -state.y;
		    printf("%d mouse old \n", mouse_old_2);
		}

		if(press_22 == 1){
			al_get_mouse_state(&state);
			sem_wait(&pitch_2_s);
		    	pitch_2 = pitch_2 - state.y - mouse_old_2;
		    	if (pitch_2 >= 11) pitch_2 = 11;
		    	if (pitch_2 <= 1) pitch_2 = 1;
	    	sem_post(&pitch_2_s);
		    mouse_old_2 = -state.y;
		    printf("%d mouse old \n", mouse_old_2);
		    printf("%d\n", press_22);
		    sem_wait(&pitch_2_s);
		    	printf("%d pitch_2\n", pitch_2);
	    	sem_post(&pitch_2_s);
		    printf("%d\n", -state.y);
		    if(!al_mouse_button_down(&state, 1)){
	    		press_22 = 0;
	    		printf("%d\n", press_2);
			}
		}

		// filter button hanfling
		if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP && XUPL_1 + 95 < ev.mouse.x && ev.mouse.x < XUPL_1 + 190 && YUPL_1 + 2 + BTT2 < ev.mouse.y && ev.mouse.y < YUPL_1 + 22  + BTT2) {
		    /* Primary (e.g. left) mouse button is held. */
		    sem_wait(&filter_s);
		    	filter_sel = 0;
		    sem_post(&filter_s);
		}
		if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP && XUPL_1 + 195 < ev.mouse.x && ev.mouse.x < XUPL_1 + 285 && YUPL_1 + 2 + BTT2 < ev.mouse.y && ev.mouse.y < YUPL_1 + 22  + BTT2) {
		    /* Primary (e.g. left) mouse button is held. */
		    sem_wait(&filter_s);
		    	filter_sel = 1;
		    sem_post(&filter_s);
		}
		if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP && XUPL_1 + 290 < ev.mouse.x && ev.mouse.x < XUPL_1 + 380 && YUPL_1 + 2 + BTT2 < ev.mouse.y && ev.mouse.y < YUPL_1 + 22  + BTT2) {
		    /* Primary (e.g. left) mouse button is held. */
		    sem_wait(&filter_s);
		    	filter_sel = 2;
		    sem_post(&filter_s);
		}
		if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP && XUPL_1 + 495 < ev.mouse.x && ev.mouse.x < XUPL_1 + 590 && YUPL_1 + 2 + BTT2 < ev.mouse.y && ev.mouse.y < YUPL_1 + 22  + BTT2) {
		    /* Primary (e.g. left) mouse button is held. */
		    sem_wait(&filter_2_s);
		    	filter_sel_2 = 0;
		    sem_post(&filter_2_s);
		}
		if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP && XUPL_1 + 595 < ev.mouse.x && ev.mouse.x < XUPL_1 + 685 && YUPL_1 + 2 + BTT2 < ev.mouse.y && ev.mouse.y < YUPL_1 + 22  + BTT2) {
		    /* Primary (e.g. left) mouse button is held. */
		    sem_wait(&filter_2_s);
		    	filter_sel_2 = 1;
		    sem_post(&filter_2_s);
		}
		if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP && XUPL_1 + 690 < ev.mouse.x && ev.mouse.x < XUPL_1 + 780 && YUPL_1 + 2 + BTT2 < ev.mouse.y && ev.mouse.y < YUPL_1 + 22  + BTT2) {
		    /* Primary (e.g. left) mouse button is held. */
		    sem_wait(&filter_2_s);
		    	filter_sel_2 = 2;
		    sem_post(&filter_2_s);
		}

		// handling keyboard note

		if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch(ev.keyboard.keycode) {
				case ALLEGRO_KEY_A:
					sem_wait(&wave_f_s);
						wave_f = 261.63; // DO
						hold = 1;
				   	sem_post(&wave_f_s);
				   	break;
					case ALLEGRO_KEY_S:
					sem_wait(&wave_f_s);
						wave_f = 293.66; // RE
						hold = 1;
				   	sem_post(&wave_f_s);
				   	break;
				case ALLEGRO_KEY_D:
					sem_wait(&wave_f_s);
						wave_f = 329.63; // MI
						hold = 1;
				   	sem_post(&wave_f_s);
				   	break;
				case ALLEGRO_KEY_F:
					sem_wait(&wave_f_s);
						wave_f = 349.23; // FA
						hold = 1;
				   	sem_post(&wave_f_s);
				   	break;
				case ALLEGRO_KEY_G:
					sem_wait(&wave_f_s);
						wave_f = 392.00; // SOL
						hold = 1;
				   	sem_post(&wave_f_s);
				   	break;
				case ALLEGRO_KEY_H:
					sem_wait(&wave_f_s);
						wave_f = 440.00; // LA
						hold = 1;
				   	sem_post(&wave_f_s);
				   	break;
				case ALLEGRO_KEY_J:
					sem_wait(&wave_f_s);
						wave_f = 493.88; // SI
						hold = 1;
				   	sem_post(&wave_f_s);
				   	break;
				case ALLEGRO_KEY_K:
					sem_wait(&wave_f_s);
						wave_f = 523.25; // DO
						hold = 1;
				   	sem_post(&wave_f_s);
				   	break;
				case ALLEGRO_KEY_L:
					sem_wait(&wave_f_s);
						wave_f = 587.33; // RE
						hold = 1;
				   	sem_post(&wave_f_s);
				   	break;
			}
      	}

      	if(ev.type == ALLEGRO_EVENT_KEY_UP) {
      		hold = 0;
      	}

		if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
		    end = 1;
		    break;
		}
	}

	al_destroy_event_queue(event_queue);
	wait_period(&info);
}