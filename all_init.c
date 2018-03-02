#include <allegro5/allegro.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_primitives.h>
#include "audio_var.h"
#include "graph_v_c.h"
#include "error.h"

void all_init(){
  
  // initialize allegro
  if(!al_init()){
    all_error("FAILED to initialize allegro\n");
  }

  // install mouse
  if(!al_install_mouse()){
    all_error("FAILED to initialize the mouse\n"); // FILE "error.c"
  }

  // install keyboard
  if(!al_install_keyboard()){
    all_error("FAILED to initialize the keyboard\n");
  }

  // initialize allegro font addon
  al_init_font_addon();

  // initialize ttf addon, used to use arial.ttf
  if(!al_init_ttf_addon()){
    all_error("FAILED to initialize the ttf (True Type Font) addon\n");
  }

  // install allegro audio addon
  if(!al_install_audio()){
    all_error("FAILED to initialize audio addon\n");
  }

  // initialize audio addons
  if(!al_init_acodec_addon()){
    all_error("FAILED to initialize audio codecs!\n");
   }

  if (!al_reserve_samples(1)) {
    all_error("Could not set up voice and mixer.\n");
  }

   // set allegro app name (title)
  al_set_app_name("Synth a me");

  // create synth allegro_display
  display = al_create_display(800, 650);
  if(!display) {
      all_error("failed to create display!\n");
  }

  // create allegro event queue, needed to handle input from user
  event_queue = al_create_event_queue();
  if(!event_queue) {
    all_error("failed to create event_queue!\n");
    al_destroy_display(display);
  }

  // set initial samples
  // al_reserve_samples(1);

  // initialize audio stream
  stream = al_create_audio_stream(AUDIO_FRAG, samples, F_SAMPL, depth, chan_conf);
  if (!stream) {
         all_error("Could not create an ALLEGRO_AUDIO_STREAM\n");
  }

  // register events in the events queue
  al_register_event_source(event_queue, al_get_display_event_source(display));
  al_register_event_source(event_queue, al_get_mouse_event_source());
  al_register_event_source(event_queue, al_get_keyboard_event_source());
}