void *handler_f(void *arg){
	ALLEGRO_MOUSE_STATE state;
	struct periodic_info info;

	make_periodic(40, &info);
	while(end == 0){

		// handling dropdown menu
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


		if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
		    end = 1;
		    break;
		}
	}

	al_destroy_event_queue(event_queue);
	wait_period(&info);
}