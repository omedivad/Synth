#include <allegro5/allegro.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_primitives.h>
#include <pthread.h>
#include <semaphore.h>
#include <math.h>
#include "handler.h"
#include "graph_v_c.h"
#include "audio_var.h"
#include "circular_array.h"
#include "variables.h"

void *handler_f(void *arg){
	ALLEGRO_MOUSE_STATE state;
	float mouse_old = 0;
	float mouse_old_2 = 0;
	int press = 0;
	int press_2 = 0;
	int press_11 = 0;
	int press_22 = 0;
	// int end_l = 0;

	while(end == 0){

		// handling OSC 1 buttons
		al_wait_for_event(event_queue, &ev);

	   	// Handle SINE button 
		if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP && XUPL_1 + 95 < ev.mouse.x && ev.mouse.x < XUPL_1 + 190 && YUPL_1 + 2 < ev.mouse.y && ev.mouse.y < YUPL_1 + 22) {
		    sem_wait(&wave_sel_s);
		    	wave_sel = SIN;
		    sem_post(&wave_sel_s);
		}
		// Handle SQUARE button 
		if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP && XUPL_1 + 195 < ev.mouse.x && ev.mouse.x < XUPL_1 + 285 && YUPL_1 + 2 < ev.mouse.y && ev.mouse.y < YUPL_1 + 22) {
		    sem_wait(&wave_sel_s);
		    	wave_sel = SQR;
		    sem_post(&wave_sel_s);
		}
		// Handle SAWTOOTH button 
		if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP && XUPL_1 + 290 < ev.mouse.x && ev.mouse.x < XUPL_1 + 380 && YUPL_1 + 2 < ev.mouse.y && ev.mouse.y < YUPL_1 + 22) {
		    sem_wait(&wave_sel_s);
		    	wave_sel = SAW;
		    sem_post(&wave_sel_s);
		}
		// Handle NOISE button 
		if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP && XUPL_1 + 95 < ev.mouse.x && ev.mouse.x < XUPL_1 + 190 && YUPL_1 + 26 < ev.mouse.y && ev.mouse.y < YUPL_1 + 46) {
		    sem_wait(&wave_sel_s);
		    	wave_sel = NSE;
		    sem_post(&wave_sel_s);
		}
		// Handle SINE button 
		if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP && XUPL_1 + 495 < ev.mouse.x && ev.mouse.x < XUPL_1 + 590 && YUPL_1 + 2 < ev.mouse.y && ev.mouse.y < YUPL_1 + 22) {
		   // Mouse button
		    sem_wait(&wave_sel_2_s);
		    	wave_sel_2 = SIN;
		    sem_post(&wave_sel_2_s);
		}
		// Handle SQUARE button 
		if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP && XUPL_1 + 595 < ev.mouse.x && ev.mouse.x < XUPL_1 + 685 && YUPL_1 + 2 < ev.mouse.y && ev.mouse.y < YUPL_1 + 22) {
		    sem_wait(&wave_sel_2_s);
		    	wave_sel_2 = SQR;
		    sem_post(&wave_sel_2_s);
		}
		// Handle SAWTOOTH button 
		if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP && XUPL_1 + 690 < ev.mouse.x && ev.mouse.x < XUPL_1 + 780 && YUPL_1 + 2 < ev.mouse.y && ev.mouse.y < YUPL_1 + 22) {
		    sem_wait(&wave_sel_2_s);
		    	wave_sel_2 = SAW;
		    sem_post(&wave_sel_2_s);
		}
		// Handle NOISE button 
		if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP && XUPL_1 + 495 < ev.mouse.x && ev.mouse.x < XUPL_1 + 590 && YUPL_1 + 26 < ev.mouse.y && ev.mouse.y < YUPL_1 + 46) {
		    sem_wait(&wave_sel_s);
		    	wave_sel_2 = NSE;
		    sem_post(&wave_sel_s);
		}

		// handling volume 1 knob
		if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN && ev.mouse.y <= sqrt(pow(20, 2)- pow(ev.mouse.x - 350, 2)) + 100 && ev.mouse.y >= - sqrt(pow(20, 2)- pow(ev.mouse.x - 350, 2)) + 100 && press != 1) {
		    // MOUSE CLICKED
		    al_get_mouse_state(&state);
		    press = 1;
		    mouse_old = state.y;
		}

		if(press == 1){
			al_get_mouse_state(&state);
			sem_wait(&amplitude_s);
		    	amplitude = amplitude - ((float)state.y - mouse_old) / 800.0;
		    	if (amplitude >= 1) amplitude = 1;
		    	if (amplitude <= 0) amplitude = 0;
			sem_post(&amplitude_s);
			// MOUSE RELEASED
			if(!al_mouse_button_down(&state, 1)){
				press = 0;
			}
		}

		//handling vol 2 knob
		if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN && ev.mouse.y <= sqrt(pow(20, 2)- pow(ev.mouse.x - (400 + 350), 2)) + 100 && ev.mouse.y >= - sqrt(pow(20, 2)- pow(ev.mouse.x - (400 + 350), 2)) + 100 && press_2 != 1) {
		    // MOUSE CLICKED
		    al_get_mouse_state(&state);
		    press_2 = 1;
		    mouse_old_2 = state.y;
		}

		if(press_2 == 1){
			al_get_mouse_state(&state);
			sem_wait(&amplitude_2_s);
		    	amplitude_2 = amplitude_2 - ((float)state.y - mouse_old_2) / 800.0;
		    	if (amplitude_2 >= 1.0) amplitude_2 = 1.0;
		    	if (amplitude_2 <= 0.0) amplitude_2 = 0.0;
			sem_post(&amplitude_2_s);
			// MOUSE RELEASED
			if(!al_mouse_button_down(&state, 1)){
				press_2 = 0;
			}
		}

		// handling pitch 1 knob
		if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN && ev.mouse.y <= sqrt(pow(20, 2)- pow(ev.mouse.x - 250, 2)) + 100 && ev.mouse.y >= - sqrt(pow(20, 2)- pow(ev.mouse.x - 250, 2)) + 100 && press_11 != 1) {
		    // MOUSE CLICKED
		    al_get_mouse_state(&state);
		    press_11 = 1;
		    mouse_old = state.y;
		}

		if(press_11 == 1){
			al_get_mouse_state(&state);
			sem_wait(&pitch_s);
		    	pitch = pitch - ((float)state.y - mouse_old) / (800.0 / 11.0);
		    	if (pitch >= 11) pitch = 11;
		    	if (pitch < 1) pitch = 1;
			sem_post(&pitch_s);
			// MOUSE RELEASED
			if(!al_mouse_button_down(&state, 1)){
				press_11 = 0;
			}
		}

		//handling pitch 2 knob

		if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN && ev.mouse.y <= sqrt(pow(20, 2)- pow(ev.mouse.x - (400 + 250), 2)) + 100 && ev.mouse.y >= - sqrt(pow(20, 2)- pow(ev.mouse.x - (400 + 250), 2)) + 100 && press_22 != 1) {
			// MOUSE CLICKED
			al_get_mouse_state(&state);
			press_22 = 1;
			mouse_old_2 = state.y;
		}

		if(press_22 == 1){
			al_get_mouse_state(&state);
			sem_wait(&pitch_2_s);
		    	pitch_2 = pitch_2 - ((float)state.y - mouse_old) / (800.0 / 11.0);
		    	if (pitch_2 >= 11) pitch_2 = 11;
		    	if (pitch_2 <= 1) pitch_2 = 1;
			sem_post(&pitch_2_s);
			// MOUSE RELEASED
			if(!al_mouse_button_down(&state, 1)){
				press_22 = 0;
			}
		}

		// filter button handling
		//OSC 1
		// NO FILTER
		if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP && XUPL_1 + 95 < ev.mouse.x && ev.mouse.x < XUPL_1 + 190 && YUPL_1 + 2 + BTT2 < ev.mouse.y && ev.mouse.y < YUPL_1 + 22 + BTT2) {
			sem_wait(&filter_s);
				filter_sel = NFLT;
			sem_post(&filter_s);
		}
		// HIGH PASS FILTER
		if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP && XUPL_1 + 195 < ev.mouse.x && ev.mouse.x < XUPL_1 + 285 && YUPL_1 + 2 + BTT2 < ev.mouse.y && ev.mouse.y < YUPL_1 + 22 + BTT2) {
			sem_wait(&filter_s);
				filter_sel = HPF;
			sem_post(&filter_s);
		}
		// LOW PASS FILTER
		if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP && XUPL_1 + 290 < ev.mouse.x && ev.mouse.x < XUPL_1 + 380 && YUPL_1 + 2 + BTT2 < ev.mouse.y && ev.mouse.y < YUPL_1 + 22 + BTT2) {
			sem_wait(&filter_s);
				filter_sel = LPF;
			sem_post(&filter_s);
		}
		// OSC 2
		// NO FILTER
		if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP && XUPL_1 + 495 < ev.mouse.x && ev.mouse.x < XUPL_1 + 590 && YUPL_1 + 2 + BTT2 < ev.mouse.y && ev.mouse.y < YUPL_1 + 22 + BTT2) {
			sem_wait(&filter_2_s);
				filter_sel_2 = NFLT;
			sem_post(&filter_2_s);
		}
		// HIGH PASS FILTER
		if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP && XUPL_1 + 595 < ev.mouse.x && ev.mouse.x < XUPL_1 + 685 && YUPL_1 + 2 + BTT2 < ev.mouse.y && ev.mouse.y < YUPL_1 + 22 + BTT2) {
			sem_wait(&filter_2_s);
				filter_sel_2 = HPF;
			sem_post(&filter_2_s);
		}
		// LOW PASS FILTER
		if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP && XUPL_1 + 690 < ev.mouse.x && ev.mouse.x < XUPL_1 + 780 && YUPL_1 + 2 + BTT2 < ev.mouse.y && ev.mouse.y < YUPL_1 + 22 + BTT2) {
			sem_wait(&filter_2_s);
				filter_sel_2 = LPF;
			sem_post(&filter_2_s);
		}

		// draw wave handling
		if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP && XUPL_1 + 5 < ev.mouse.x && ev.mouse.x < XUPL_1 + 95 && YUPL_1 + 60 + BTT2 < ev.mouse.y && ev.mouse.y < YUPL_1 + 82 + BTT2) {
			if(draw_wave == 0){
				sem_wait(&draw_wave_s);
					draw_wave = 1;
				sem_post(&draw_wave_s);
			}else{
				sem_wait(&draw_wave_s);
					draw_wave = 0;
				sem_post(&draw_wave_s);
			}
		}

		/*	note that in the following two "if" varialble 'hold' is used to let the time value of osc 1 and 2 't' increase as long as
			the keyboard button is pressed. The variable 't' is used for wave generation (example sin(w*t)) in FILE "wave_gen.c" */

		// handling keyboard note
		if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch(ev.keyboard.keycode) {
				case ALLEGRO_KEY_A:
					sem_wait(&wave_f_s);
						wave_f = 262; 		// DO
						sem_wait(&hold_s);
							hold = 1;
						sem_post(&hold_s);
				   	sem_post(&wave_f_s);
				   	break;
				case ALLEGRO_KEY_S:
					sem_wait(&wave_f_s);
						wave_f = 294; 		// RE
						sem_wait(&hold_s);
							hold = 1;
						sem_post(&hold_s);
				   	sem_post(&wave_f_s);
				   	break;
				case ALLEGRO_KEY_D:
					sem_wait(&wave_f_s);
						wave_f = 330; 		// MI
						sem_wait(&hold_s);
							hold = 1;
						sem_post(&hold_s);
				   	sem_post(&wave_f_s);
				   	break;
				case ALLEGRO_KEY_F:
					sem_wait(&wave_f_s);
						wave_f = 349;		// FA
						sem_wait(&hold_s);
							hold = 1;
						sem_post(&hold_s);
				   	sem_post(&wave_f_s);
				   	break;
				case ALLEGRO_KEY_G:
					sem_wait(&wave_f_s);
						wave_f = 392.00; 	// SOL
						sem_wait(&hold_s);
							hold = 1;
						sem_post(&hold_s);
				   	sem_post(&wave_f_s);
				   	break;
				case ALLEGRO_KEY_H:
					sem_wait(&wave_f_s);
						wave_f = 440.00; 	// LA
						sem_wait(&hold_s);
							hold = 1;
						sem_post(&hold_s);
				   	sem_post(&wave_f_s);
				   	break;
				case ALLEGRO_KEY_J:
					sem_wait(&wave_f_s);
						wave_f = 494; 		// SI
						sem_wait(&hold_s);
							hold = 1;
						sem_post(&hold_s);
				   	sem_post(&wave_f_s);
				   	break;
				case ALLEGRO_KEY_K:
					sem_wait(&wave_f_s);
						wave_f = 523; 		// DO
						sem_wait(&hold_s);
							hold = 1;
						sem_post(&hold_s);
				   	sem_post(&wave_f_s);
				   	break;
				case ALLEGRO_KEY_L:
					sem_wait(&wave_f_s);
						wave_f = 587;		// RE
						sem_wait(&hold_s);
							hold = 1;
						sem_post(&hold_s);
				   	sem_post(&wave_f_s);
				   	break;
			   	case ALLEGRO_KEY_W:
			   		sem_wait(&wave_f_s);
						wave_f = 277;		// DO#
						sem_wait(&hold_s);
							hold = 1;
						sem_post(&hold_s);
				   	sem_post(&wave_f_s);
				   	break;
				case ALLEGRO_KEY_E:
			   		sem_wait(&wave_f_s);
						wave_f = 311;		// RE#
						sem_wait(&hold_s);
							hold = 1;
						sem_post(&hold_s);
				   	sem_post(&wave_f_s);
				   	break;
				case ALLEGRO_KEY_T:
			   		sem_wait(&wave_f_s);
						wave_f = 370;		// FA#
						sem_wait(&hold_s);
							hold = 1;
						sem_post(&hold_s);
				   	sem_post(&wave_f_s);
				   	break;
				case ALLEGRO_KEY_Y:
			   		sem_wait(&wave_f_s);
						wave_f = 415;		// SOL#
						sem_wait(&hold_s);
							hold = 1;
						sem_post(&hold_s);
				   	sem_post(&wave_f_s);
				   	break;
				case ALLEGRO_KEY_U:
			   		sem_wait(&wave_f_s);
						wave_f = 466;		// LA#
						sem_wait(&hold_s);
							hold = 1;
						sem_post(&hold_s);
				   	sem_post(&wave_f_s);
				   	break;
				case ALLEGRO_KEY_O:
			   		sem_wait(&wave_f_s);
						wave_f = 554;		// DO#
						sem_wait(&hold_s);
							hold = 1;
						sem_post(&hold_s);
				   	sem_post(&wave_f_s);
				   	break;
				case ALLEGRO_KEY_P:
			   		sem_wait(&wave_f_s);
						wave_f = 622;		// RE#
						sem_wait(&hold_s);
							hold = 1;
						sem_post(&hold_s);
				   	sem_post(&wave_f_s);
				   	break;
				case ALLEGRO_KEY_ESCAPE:
			   		sem_wait(&end_s);
		    			end = 1;
		    		sem_post(&end_s);
				   	break;
				default:
					break;
			}
		}

		if(ev.type == ALLEGRO_EVENT_KEY_UP) {
			sem_wait(&hold_s);
				hold = 0;
			sem_post(&hold_s);
		}

		// close all tasks
		if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
			sem_wait(&end_s);
				end = 1;
			sem_post(&end_s);
			break;
		}

	}

	al_destroy_event_queue(event_queue);

	return NULL;
}
