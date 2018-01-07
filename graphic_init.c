void graphic_init(){
  float x1, y1, x2 , y2;
  al_init();
  all_error_stamp("Initialization");

  al_install_mouse();
  al_install_keyboard();
  al_init_font_addon(); // initialize the font addon
  al_init_ttf_addon();// initialize the ttf (True Type Font) addon
  al_install_audio();

  al_set_app_name("Synth a me");

  display = al_create_display(800, 600);
  if(!display) {
    	fprintf(stderr, "failed to create display!\n");
    	return -1;
  }

  event_queue = al_create_event_queue();
  if(!event_queue) {
  fprintf(stderr, "failed to create event_queue!\n");
    al_destroy_display(display);
    return -1;
  }

  al_register_event_source(event_queue, al_get_display_event_source(display));
  al_register_event_source(event_queue, al_get_mouse_event_source());
  al_register_event_source(event_queue, al_get_keyboard_event_source());
}