void graphic_init(){
  float x1, y1, x2 , y2;
  al_init();
  all_error_stamp("Initialization");

  al_install_mouse();
  al_install_keyboard();
  al_init_font_addon(); // initialize the font addon
  al_init_ttf_addon();// initialize the ttf (True Type Font) addon

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

  ALLEGRO_FONT *font_title = al_load_ttf_font("arial.ttf",24,0);
  ALLEGRO_FONT *font_section = al_load_ttf_font("arial.ttf",15,0);
  ALLEGRO_COLOR bianco = al_map_rgb(255, 255, 255);
  ALLEGRO_COLOR nero = al_map_rgb(0, 0, 0);
  ALLEGRO_COLOR giallo = al_map_rgb(255, 255, 224);

  for( int i=0; i<2; i++){
    // Title
    al_clear_to_color(nero);
    al_draw_text(font_title, bianco, XWIN/2, 0, ALLEGRO_ALIGN_CENTER, "SYNTH A ME");

  // Main graphical division
    al_draw_filled_rectangle(XUPL_1, YUPL_1, XLOR_1, YLOR_1, al_map_rgb(51, 51, 51));
    al_draw_filled_rectangle(XUPL_1 + 400, YUPL_1, XLOR_1 + 400, YLOR_1, al_map_rgb(51, 51, 51));
    al_draw_rectangle(XUPL_1, YUPL_1, XLOR_1, YLOR_1, bianco, 1);
    al_draw_rectangle(XUPL_1 + 400, YUPL_1, XLOR_1 + 400, YLOR_1, bianco, 1);

    al_draw_text(font_section, bianco, XUPL_1 + 2, YUPL_1 + 2, ALLEGRO_ALIGN_LEFT, "OSC 1");
    al_draw_text(font_section, bianco, XUPL_1 + 402, YUPL_1 + 2, ALLEGRO_ALIGN_LEFT, "OSC 2");
    
    // button OSC 1
    //sine
    al_draw_filled_rectangle(XUPL_1 + 95, YUPL_1 + 2, XUPL_1 + 190, YUPL_1 + 22, giallo);
    al_draw_rectangle(XUPL_1 + 95, YUPL_1 + 2, XUPL_1 + 190, YUPL_1 + 22, bianco, 1);
    al_draw_text(font_section, bianco, XUPL_1 + 100, YUPL_1 + 2, ALLEGRO_ALIGN_LEFT, "Sine");
    // tri
    al_draw_filled_rectangle(XUPL_1 + 190 + 5, YUPL_1 + 2, XUPL_1 + 285, YUPL_1 + 22, nero);
    al_draw_rectangle(XUPL_1 + 190 + 5, YUPL_1 + 2, XUPL_1 + 190 + 95, YUPL_1 + 22, bianco, 1);
    al_draw_text(font_section, bianco, XUPL_1 + 200, YUPL_1 + 2, ALLEGRO_ALIGN_LEFT, "Triangular");
    // saw
    al_draw_filled_rectangle(XUPL_1 + 285 + 5, YUPL_1 + 2, XUPL_1 + 380, YUPL_1 + 22, nero);
    al_draw_rectangle(XUPL_1 + 285 + 5, YUPL_1 + 2, XUPL_1 + 190 + 190, YUPL_1 + 22, bianco, 1);
    al_draw_text(font_section, bianco, XUPL_1 + 295, YUPL_1 + 2, ALLEGRO_ALIGN_LEFT, "Saw");
    
    // button OSC 2
    //sine
    al_draw_filled_rectangle(XUPL_1 + 95 + XOSC_2, YUPL_1 + 2, XUPL_1 + 190 + XOSC_2, YUPL_1 + 22, giallo);
    al_draw_rectangle(XUPL_1 + 95 + XOSC_2, YUPL_1 + 2, XUPL_1 + 190 + XOSC_2, YUPL_1 + 22, bianco, 1);
    al_draw_text(font_section, bianco, XUPL_1 + 100 + XOSC_2, YUPL_1 + 2, ALLEGRO_ALIGN_LEFT, "Sine");
    // tri
    al_draw_filled_rectangle(XUPL_1 + 190 + 5 + XOSC_2, YUPL_1 + 2, XUPL_1 + 285 + XOSC_2 , YUPL_1 + 22, nero);
    al_draw_rectangle(XUPL_1 + 190 + 5 + XOSC_2, YUPL_1 + 2, XUPL_1 + 285 + XOSC_2, YUPL_1 + 22, bianco, 1);
    al_draw_text(font_section, bianco, XUPL_1 + 200 + XOSC_2, YUPL_1 + 2, ALLEGRO_ALIGN_LEFT, "Triangular");
    // saw
    al_draw_filled_rectangle(XUPL_1 + 285 + 5 + XOSC_2, YUPL_1 + 2, XUPL_1 + 380 + XOSC_2, YUPL_1 + 22, nero);
    al_draw_rectangle(XUPL_1 + 285 + 5 + XOSC_2, YUPL_1 + 2, XUPL_1 + 380 + XOSC_2, YUPL_1 + 22, bianco, 1);
    al_draw_text(font_section, bianco, XUPL_1 + 295 + XOSC_2, YUPL_1 + 2, ALLEGRO_ALIGN_LEFT, "Saw");
    al_flip_display();
  }
}