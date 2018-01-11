void all_init(){
  
  if(!al_init()){
    all_error("FAILED to initialize allegro\n");
  }

  if(!al_install_mouse()){
    all_error("FAILED to initialize the mouse\n"); // FILE "error.c"
  }
  if(!al_install_keyboard()){
    all_error("FAILED to initialize the keyboard\n");
  }
  al_init_font_addon();
  if(!al_init_ttf_addon()){
    all_error("FAILED to initialize the ttf (True Type Font) addon\n");
  }
  if(!al_install_audio()){
    all_error("FAILED to initialize audio addon\n");
  }
  if(!al_init_acodec_addon()){
    all_error("FAILED to initialize audio codecs!\n");
   }

  if (!al_reserve_samples(1)) {
    all_error("Could not set up voice and mixer.\n");
  }

  al_set_app_name("Synth a me");

  display = al_create_display(800, 650);
  if(!display) {
      all_error("failed to create display!\n");
  }

  event_queue = al_create_event_queue();
  if(!event_queue) {
    all_error("failed to create event_queue!\n");
    al_destroy_display(display);
  }

  al_reserve_samples(0);
  // initializing stream
  sem_wait(&samples_s);
    stream = al_create_audio_stream(AUDIO_FRAG, samples, F_SAMPL, depth, chan_conf);
    if (!stream) {
           all_error("Could not create an ALLEGRO_AUDIO_STREAM\n");
    }
  sem_post(&samples_s);

  // registering events in the queue events
  al_register_event_source(event_queue, al_get_display_event_source(display));
  al_register_event_source(event_queue, al_get_mouse_event_source());
  al_register_event_source(event_queue, al_get_keyboard_event_source());
}