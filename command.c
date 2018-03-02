#include <allegro5/allegro.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_primitives.h>
#include "command.h"
#include "audio_var.h"
#include "circular_array.h"
#include "variables.h"
#include "graph_v_c.h"
#include "error.h"

void *command_f(void *arg){
	int end_this_l = 0;
	int inc = 14;
	// creating allegro event
	ALLEGRO_EVENT ev_k;
	// creating allegro pointer to event queue
	ALLEGRO_EVENT_QUEUE *event_queue_k = NULL;
	// defining allegro fonts to be used
	ALLEGRO_FONT *font_title = al_load_ttf_font("arial.ttf",24,0);
	// ALLEGRO_FONT *font_section = al_load_ttf_font("arial.ttf",15,0);
	ALLEGRO_FONT *font_command = al_load_ttf_font("arial.ttf",12,0);
	// defining allegro colors to be used
	// ALLEGRO_COLOR nero = al_map_rgb(0, 0, 0);
  	ALLEGRO_COLOR bianco = al_map_rgb(255, 255, 255);
  	ALLEGRO_COLOR grigio = al_map_rgb(51, 51, 51);

  	// creanting display
	disp_key = al_create_display(400, 300);
	if(!disp_key) {
		all_error("failed to create display!\n");
	}

	// creating allegro event queue and assigning it to queue pointer
	event_queue_k = al_create_event_queue();
  	if(!event_queue_k) {
		all_error("failed to create event_queue!\n");
		al_destroy_display(display);
  	}

  	// registering event from "disp_key" in event_queue_k
  	al_register_event_source(event_queue_k, al_get_display_event_source(disp_key));

  	// set bitmap target di disp_key
  	al_set_target_bitmap(al_get_backbuffer(disp_key)); 

  	while(end == 0 && end_this_l == 0){
  		// clear screen to grey
	  	al_clear_to_color(grigio);
	  	// draw text
	  	al_draw_text(font_title, bianco, 400 / 4, 0, ALLEGRO_ALIGN_CENTER, "Commands");
	  	al_draw_text(font_title, bianco, (400 / 4) * 3, 0, ALLEGRO_ALIGN_CENTER, "Credits");
	  	// draw lines to separate spaces in view
	  	al_draw_line(0, 25, 400, 25, bianco, 1);
	  	al_draw_line(400 / 2, 0, 400 / 2, 300, bianco, 1);

	  	// draw commands
	  	al_draw_text(font_command, bianco, 10, 30, ALLEGRO_ALIGN_LEFT, "A        DO");
	  	al_draw_text(font_command, bianco, 10, 30 + inc * 1, ALLEGRO_ALIGN_LEFT, "W       DO#");
	  	al_draw_text(font_command, bianco, 10, 30 + inc * 2, ALLEGRO_ALIGN_LEFT, "S        RE");
	  	al_draw_text(font_command, bianco, 10, 30 + inc * 3, ALLEGRO_ALIGN_LEFT, "E        RE#");
	  	al_draw_text(font_command, bianco, 10, 30 + inc * 4, ALLEGRO_ALIGN_LEFT, "D       MI");
	  	al_draw_text(font_command, bianco, 10, 30 + inc * 5, ALLEGRO_ALIGN_LEFT, "F        FA");
	  	al_draw_text(font_command, bianco, 10, 30 + inc * 6, ALLEGRO_ALIGN_LEFT, "T        FA#");
	  	al_draw_text(font_command, bianco, 10, 30 + inc * 7, ALLEGRO_ALIGN_LEFT, "G       SOL");
	  	al_draw_text(font_command, bianco, 10, 30 + inc * 8, ALLEGRO_ALIGN_LEFT, "Y        SOL#");
	  	al_draw_text(font_command, bianco, 10, 30 + inc * 9, ALLEGRO_ALIGN_LEFT, "H        LA");
	  	al_draw_text(font_command, bianco, 10, 30 + inc * 10, ALLEGRO_ALIGN_LEFT, "U        LA#");
	  	al_draw_text(font_command, bianco, 10, 30 + inc * 11, ALLEGRO_ALIGN_LEFT, "J        SI");
	  	al_draw_text(font_command, bianco, 10, 30 + inc * 12, ALLEGRO_ALIGN_LEFT, "K        DO");
	  	al_draw_text(font_command, bianco, 10, 30 + inc * 13, ALLEGRO_ALIGN_LEFT, "O        DO#");
	  	al_draw_text(font_command, bianco, 10, 30 + inc * 14, ALLEGRO_ALIGN_LEFT, "L        RE");
	  	al_draw_text(font_command, bianco, 10, 30 + inc * 15, ALLEGRO_ALIGN_LEFT, "P        RE#");

	  	// draw credits
	  	al_draw_text(font_command, bianco, 10 + (400/ 4) * 2, 30 + inc * 1, ALLEGRO_ALIGN_LEFT, "Davide Morelli");
	  	al_draw_text(font_command, bianco, 10 + (400/ 4) * 2, 30 + inc * 2, ALLEGRO_ALIGN_LEFT, "09/01/2018");
	  	al_draw_text(font_command, bianco, 10 + (400/ 4) * 2, 30 + inc * 3, ALLEGRO_ALIGN_LEFT, "RT project");

	  	// flip display
	  	al_flip_display();

	  	// get next event and store in ev_k
  		al_get_next_event(event_queue_k, &ev_k);

  		// handle close command
  		if(ev_k.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
			end_this_l = 1;
			break;
		}
  	}
  	// destroy
  	al_destroy_event_queue(event_queue_k);
  	al_destroy_display(disp_key);
}
