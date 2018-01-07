void *graphic_f(void *arg){
  struct periodic_info info_1;
  ALLEGRO_COLOR giallo = al_map_rgb(255, 255, 224);
  ALLEGRO_COLOR nero = al_map_rgb(0, 0, 0);
  ALLEGRO_COLOR bianco = al_map_rgb(255, 255, 255);
  ALLEGRO_COLOR boch = al_map_rgb(120, 120, 120);
  ALLEGRO_COLOR grigio = al_map_rgb(51, 51, 51);
  ALLEGRO_BITMAP *vol = NULL;
  ALLEGRO_BITMAP *ptc = NULL;
  int c = 0;

  al_set_target_bitmap(al_get_backbuffer(display));

  make_periodic(41.666666666666664, &info_1);

  ALLEGRO_FONT *font_title = al_load_ttf_font("arial.ttf",24,0);
  ALLEGRO_FONT *font_section = al_load_ttf_font("arial.ttf",15,0);
  ALLEGRO_FONT *font_command = al_load_ttf_font("arial.ttf",12,0);

  vol = al_create_bitmap(40, 40);
  ptc = al_create_bitmap(40, 40);

  for( int i=0; i<2; i++){
    // Title
    al_clear_to_color(nero);
    al_draw_text(font_title, bianco, XWIN/2, 0, ALLEGRO_ALIGN_CENTER, "SYNTH A ME");

  // Main graphical division
    al_draw_filled_rectangle(XUPL_1, YUPL_1, XLOR_1, YLOR_1, grigio);
    al_draw_filled_rectangle(XUPL_1 + 400, YUPL_1, XLOR_1 + 400, YLOR_1, grigio);
    al_draw_rectangle(XUPL_1, YUPL_1, XLOR_1, YLOR_1, bianco, 1);
    al_draw_rectangle(XUPL_1 + 400, YUPL_1, XLOR_1 + 400, YLOR_1, bianco, 1);

    al_draw_filled_rectangle(XUPL_1, YLOR_1, XLOR_1, 2 * YLOR_1, grigio);
    al_draw_filled_rectangle(XUPL_1 + 400, YLOR_1, XLOR_1 + 400, 2 * YLOR_1, grigio);
    al_draw_rectangle(XUPL_1, YLOR_1, XLOR_1, 2 * YLOR_1, bianco, 1);
    al_draw_rectangle(XUPL_1 + 400, YLOR_1, XLOR_1 + 400, 2 * YLOR_1, bianco, 1);

    al_draw_text(font_section, bianco, XUPL_1 + 2, YUPL_1 + 2, ALLEGRO_ALIGN_LEFT, "OSC 1");
    al_draw_text(font_section, bianco, XUPL_1 + 402, YUPL_1 + 2, ALLEGRO_ALIGN_LEFT, "OSC 2");

    // drawing volume knob
    // vol 1
    al_set_target_bitmap(vol);
    al_clear_to_color(grigio);

    al_draw_filled_circle(20, 20, 20, boch);
    al_draw_circle(20, 20, 20, nero, 1);
    al_draw_line(20, 0, 20, 15, nero, 2);

    al_set_target_bitmap(al_get_backbuffer(display));
    al_draw_bitmap(vol, 330, 80, 0);
    // vol 2
    al_set_target_bitmap(ptc);
    al_clear_to_color(grigio);

    al_draw_filled_circle(20, 20, 20, boch);
    al_draw_circle(20, 20, 20, nero, 1);
    al_draw_line(18, 40, 20, 25, nero, 2);

    al_set_target_bitmap(al_get_backbuffer(display));
    al_draw_bitmap(ptc, 400 + 330, 80, 0);

    al_flip_display();
  }

  while(end == 0){
    sem_wait(&wave_sel_s);
      if(wave_sel == 0){
        al_draw_filled_rectangle(XUPL_1 + 95, YUPL_1 + 2, XUPL_1 + 190, YUPL_1 + 22, giallo);
        al_draw_filled_rectangle(XUPL_1 + 190 + 5, YUPL_1 + 2, XUPL_1 + 285, YUPL_1 + 22, nero);
        al_draw_filled_rectangle(XUPL_1 + 285 + 5, YUPL_1 + 2, XUPL_1 + 380, YUPL_1 + 22, nero);
        al_draw_text(font_section, nero, XUPL_1 + 100, YUPL_1 + 2, ALLEGRO_ALIGN_LEFT, "Sine");
        al_draw_text(font_section, bianco, XUPL_1 + 200, YUPL_1 + 2, ALLEGRO_ALIGN_LEFT, "Triangular");
        al_draw_text(font_section, bianco, XUPL_1 + 295, YUPL_1 + 2, ALLEGRO_ALIGN_LEFT, "Saw");
      }
      if(wave_sel == 1){
        al_draw_filled_rectangle(XUPL_1 + 95, YUPL_1 + 2, XUPL_1 + 190, YUPL_1 + 22, nero);
        al_draw_filled_rectangle(XUPL_1 + 190 + 5, YUPL_1 + 2, XUPL_1 + 285, YUPL_1 + 22, giallo);
        al_draw_filled_rectangle(XUPL_1 + 285 + 5, YUPL_1 + 2, XUPL_1 + 380, YUPL_1 + 22, nero);
        al_draw_text(font_section, bianco, XUPL_1 + 100, YUPL_1 + 2, ALLEGRO_ALIGN_LEFT, "Sine");
        al_draw_text(font_section, nero, XUPL_1 + 200, YUPL_1 + 2, ALLEGRO_ALIGN_LEFT, "Triangular");
        al_draw_text(font_section, bianco, XUPL_1 + 295, YUPL_1 + 2, ALLEGRO_ALIGN_LEFT, "Saw");
      }
      if(wave_sel == 2){
        al_draw_filled_rectangle(XUPL_1 + 95, YUPL_1 + 2, XUPL_1 + 190, YUPL_1 + 22, nero);
        al_draw_filled_rectangle(XUPL_1 + 190 + 5, YUPL_1 + 2, XUPL_1 + 285, YUPL_1 + 22, nero);
        al_draw_filled_rectangle(XUPL_1 + 285 + 5, YUPL_1 + 2, XUPL_1 + 380, YUPL_1 + 22, giallo);
        al_draw_text(font_section, bianco, XUPL_1 + 100, YUPL_1 + 2, ALLEGRO_ALIGN_LEFT, "Sine");
        al_draw_text(font_section, bianco, XUPL_1 + 200, YUPL_1 + 2, ALLEGRO_ALIGN_LEFT, "Triangular");
        al_draw_text(font_section, nero, XUPL_1 + 295, YUPL_1 + 2, ALLEGRO_ALIGN_LEFT, "Saw");
      }
    sem_post(&wave_sel_s);
    sem_wait(&wave_sel_2_s);
      if(wave_sel_2 == 0){
        al_draw_filled_rectangle(XUPL_1 + 95 + XOSC_2, YUPL_1 + 2, XUPL_1 + 190 + XOSC_2, YUPL_1 + 22, giallo);
        al_draw_filled_rectangle(XUPL_1 + 190 + 5 + XOSC_2, YUPL_1 + 2, XUPL_1 + 285 + XOSC_2 , YUPL_1 + 22, nero);
        al_draw_filled_rectangle(XUPL_1 + 285 + 5 + XOSC_2, YUPL_1 + 2, XUPL_1 + 380 + XOSC_2, YUPL_1 + 22, nero);
        al_draw_text(font_section, nero, XUPL_1 + 100 + XOSC_2, YUPL_1 + 2, ALLEGRO_ALIGN_LEFT, "Sine");
        al_draw_text(font_section, bianco, XUPL_1 + 200 + XOSC_2, YUPL_1 + 2, ALLEGRO_ALIGN_LEFT, "Triangular");
        al_draw_text(font_section, bianco, XUPL_1 + 295 + XOSC_2, YUPL_1 + 2, ALLEGRO_ALIGN_LEFT, "Saw");
      }
      if(wave_sel_2 == 1){
        al_draw_filled_rectangle(XUPL_1 + 95 + XOSC_2, YUPL_1 + 2, XUPL_1 + 190 + XOSC_2, YUPL_1 + 22, nero);
        al_draw_filled_rectangle(XUPL_1 + 190 + 5 + XOSC_2, YUPL_1 + 2, XUPL_1 + 285 + XOSC_2 , YUPL_1 + 22, giallo);
        al_draw_filled_rectangle(XUPL_1 + 285 + 5 + XOSC_2, YUPL_1 + 2, XUPL_1 + 380 + XOSC_2, YUPL_1 + 22, nero);
        al_draw_text(font_section, bianco, XUPL_1 + 100 + XOSC_2, YUPL_1 + 2, ALLEGRO_ALIGN_LEFT, "Sine");
        al_draw_text(font_section, nero, XUPL_1 + 200 + XOSC_2, YUPL_1 + 2, ALLEGRO_ALIGN_LEFT, "Triangular");
        al_draw_text(font_section, bianco, XUPL_1 + 295 + XOSC_2, YUPL_1 + 2, ALLEGRO_ALIGN_LEFT, "Saw");
      }
      if(wave_sel_2 == 2){
        al_draw_filled_rectangle(XUPL_1 + 95 + XOSC_2, YUPL_1 + 2, XUPL_1 + 190 + XOSC_2, YUPL_1 + 22, nero);
        al_draw_filled_rectangle(XUPL_1 + 190 + 5 + XOSC_2, YUPL_1 + 2, XUPL_1 + 285 + XOSC_2 , YUPL_1 + 22, nero);
        al_draw_filled_rectangle(XUPL_1 + 285 + 5 + XOSC_2, YUPL_1 + 2, XUPL_1 + 380 + XOSC_2, YUPL_1 + 22, giallo);
        al_draw_text(font_section, bianco, XUPL_1 + 100 + XOSC_2, YUPL_1 + 2, ALLEGRO_ALIGN_LEFT, "Sine");
        al_draw_text(font_section, bianco, XUPL_1 + 200 + XOSC_2, YUPL_1 + 2, ALLEGRO_ALIGN_LEFT, "Triangular");
        al_draw_text(font_section, nero, XUPL_1 + 295 + XOSC_2, YUPL_1 + 2, ALLEGRO_ALIGN_LEFT, "Saw");
      }
    sem_post(&wave_sel_2_s);

    // vol 1 knob
    sem_wait(&amplitude_s);
      al_draw_rotated_bitmap(vol, 20, 20, 350, 100, (float)amplitude * 800, 0);
    sem_post(&amplitude_s);
    al_draw_filled_rectangle(310, 120, 399, 150, grigio);
    al_draw_line(338, 115, 330, 125, bianco, 1);
    al_draw_text(font_command, bianco, 322, 127, ALLEGRO_ALIGN_CENTER, "- inf");
    al_draw_line(338 + 25, 115, 330 + 40, 125, bianco, 1);
    al_draw_text(font_command, bianco, 325 + 50, 127, ALLEGRO_ALIGN_CENTER, "+ inf");
    al_draw_text(font_section, bianco, 350, 120, ALLEGRO_ALIGN_CENTER, "Vol");

    //vol 2 knob
    sem_wait(&amplitude_2_s);
      al_draw_rotated_bitmap(vol, 20, 20, 400 + 350, 100, (float)amplitude_2 * 800, 0);
    sem_post(&amplitude_2_s);
    al_draw_filled_rectangle(400 + 310, 120, 400 + 399, 150, grigio);
    al_draw_line(400 + 338, 115, 400 + 330, 125, bianco, 1);
    al_draw_text(font_command, bianco, 400 + 322, 127, ALLEGRO_ALIGN_CENTER, "- inf");
    al_draw_line(400 + 338 + 25, 115, 400 + 330 + 40, 125, bianco, 1);
    al_draw_text(font_command, bianco, 400 + 325 + 50, 127, ALLEGRO_ALIGN_CENTER, "+ inf");
    al_draw_text(font_section, bianco, 400 + 350, 120, ALLEGRO_ALIGN_CENTER, "Vol");

    // frequency
    sem_wait(&wave_f_s);
    sem_wait(&pitch_s);
      al_draw_filled_rectangle(2, 51, 92, 65, grigio);
      al_draw_textf(font_section, bianco, XUPL_1 + 2, YUPL_1 + 25, ALLEGRO_ALIGN_LEFT,"%.2f Hz", wave_f * pitch);
    sem_post(&pitch_s);
    sem_post(&wave_f_s);
    sem_wait(&wave_f_s);
    sem_wait(&pitch_2_s);
      al_draw_filled_rectangle(400 + 2, 51, 400 + 92, 65, grigio);
      al_draw_textf(font_section, bianco, XUPL_1 + 2 + 400, YUPL_1 + 25, ALLEGRO_ALIGN_LEFT,"%.2f Hz", wave_f * pitch_2);
    sem_post(&pitch_2_s);
    sem_post(&wave_f_s);

    // pitch 1 knob
    sem_wait(&pitch_s);
      al_draw_rotated_bitmap(ptc, 20, 20, 250, 100, (float)pitch/2, 0);
    sem_post(&pitch_s);
    al_draw_filled_rectangle(210, 120, 299, 150, grigio);
    al_draw_line(238, 115, 230, 125, bianco, 1);
    al_draw_text(font_command, bianco, 222, 127, ALLEGRO_ALIGN_CENTER, "0");
    al_draw_line(238 + 25, 115, 230 + 40, 125, bianco, 1);
    al_draw_text(font_command, bianco, 225 + 50, 127, ALLEGRO_ALIGN_CENTER, "+");
    al_draw_text(font_section, bianco, 250, 120, ALLEGRO_ALIGN_CENTER, "pitch");

    // pitch 2 knob
    sem_wait(&pitch_2_s);
      al_draw_rotated_bitmap(ptc, 20, 20, 400 + 250, 100, (float)pitch_2/2, 0);
    sem_post(&pitch_2_s);
    al_draw_filled_rectangle(400 + 210, 120, 400 + 299, 150, grigio);
    al_draw_line(400 + 238, 115, 400 + 230, 125, bianco, 1);
    al_draw_text(font_command, bianco, 400 + 222, 127, ALLEGRO_ALIGN_CENTER, "0");
    al_draw_line(400 + 238 + 25, 115, 400 + 230 + 40, 125, bianco, 1);
    al_draw_text(font_command, bianco, 400 + 225 + 50, 127, ALLEGRO_ALIGN_CENTER, "+");
    al_draw_text(font_section, bianco, 400 + 250, 120, ALLEGRO_ALIGN_CENTER, "pitch");

    al_draw_filled_rectangle(XUPL_1, YLOR_1, XLOR_1, 3 * YLOR_1, grigio);
    al_draw_filled_rectangle(XUPL_1 + 400, YLOR_1, XLOR_1 + 400, 3 * YLOR_1, grigio);
    al_draw_rectangle(XUPL_1, YLOR_1, XLOR_1, 3 * YLOR_1, bianco, 1);
    al_draw_rectangle(XUPL_1 + 400, YLOR_1, XLOR_1 + 400, 3 * YLOR_1, bianco, 1);

    // filter buttons
    sem_wait(&filter_s);
      if(filter_sel == 0){
        al_draw_filled_rectangle(XUPL_1 + 95, YUPL_1 + 2 + BTT2, XUPL_1 + 190, YUPL_1 + 22 + BTT2, giallo);
        al_draw_filled_rectangle(XUPL_1 + 190 + 5, YUPL_1 + 2 + BTT2, XUPL_1 + 285, YUPL_1 + 22 + BTT2, nero);
        al_draw_filled_rectangle(XUPL_1 + 285 + 5, YUPL_1 + 2 + BTT2, XUPL_1 + 380, YUPL_1 + 22 + BTT2, nero);
        al_draw_text(font_section, nero, XUPL_1 + 100, YUPL_1 + 2 + BTT2, ALLEGRO_ALIGN_LEFT, "No filter");
        al_draw_text(font_section, bianco, XUPL_1 + 200, YUPL_1 + 2 + BTT2, ALLEGRO_ALIGN_LEFT, "HPF");
        al_draw_text(font_section, bianco, XUPL_1 + 295, YUPL_1 + 2 + BTT2, ALLEGRO_ALIGN_LEFT, "Saw");
      }
      if(filter_sel == 1){
        al_draw_filled_rectangle(XUPL_1 + 95, YUPL_1 + 2 + BTT2, XUPL_1 + 190, YUPL_1 + 22 + BTT2, nero);
        al_draw_filled_rectangle(XUPL_1 + 190 + 5, YUPL_1 + 2 + BTT2, XUPL_1 + 285, YUPL_1 + 22 + BTT2, giallo);
        al_draw_filled_rectangle(XUPL_1 + 285 + 5, YUPL_1 + 2 + BTT2, XUPL_1 + 380, YUPL_1 + 22 + BTT2, nero);
        al_draw_text(font_section, bianco, XUPL_1 + 100, YUPL_1 + 2 + BTT2, ALLEGRO_ALIGN_LEFT, "No Filter");
        al_draw_text(font_section, nero, XUPL_1 + 200, YUPL_1 + 2 + BTT2, ALLEGRO_ALIGN_LEFT, "HPF");
        al_draw_text(font_section, bianco, XUPL_1 + 295, YUPL_1 + 2 + BTT2, ALLEGRO_ALIGN_LEFT, "LPF");
      }
      if(filter_sel == 2){
        al_draw_filled_rectangle(XUPL_1 + 95, YUPL_1 + 2 + BTT2, XUPL_1 + 190, YUPL_1 + 22 + BTT2, nero);
        al_draw_filled_rectangle(XUPL_1 + 190 + 5, YUPL_1 + 2 + BTT2, XUPL_1 + 285, YUPL_1 + 22 + BTT2, nero);
        al_draw_filled_rectangle(XUPL_1 + 285 + 5, YUPL_1 + 2 + BTT2, XUPL_1 + 380, YUPL_1 + 22 + BTT2, giallo);
        al_draw_text(font_section, bianco, XUPL_1 + 100, YUPL_1 + 2 + BTT2, ALLEGRO_ALIGN_LEFT, "No Filter");
        al_draw_text(font_section, bianco, XUPL_1 + 200, YUPL_1 + 2 + BTT2, ALLEGRO_ALIGN_LEFT, "HPF");
        al_draw_text(font_section, nero, XUPL_1 + 295, YUPL_1 + 2 + BTT2, ALLEGRO_ALIGN_LEFT, "LPF");
      }
    sem_post(&filter_s);
    sem_wait(&filter_2_s);
      if(filter_sel_2 == 0){
        al_draw_filled_rectangle(XUPL_1 + 95 + XOSC_2, YUPL_1 + 2 + BTT2, XUPL_1 + 190 + XOSC_2, YUPL_1 + 22 + BTT2, giallo);
        al_draw_filled_rectangle(XUPL_1 + 190 + 5 + XOSC_2, YUPL_1 + 2 + BTT2, XUPL_1 + 285 + XOSC_2 , YUPL_1 + 22 + BTT2, nero);
        al_draw_filled_rectangle(XUPL_1 + 285 + 5 + XOSC_2, YUPL_1 + 2 + BTT2, XUPL_1 + 380 + XOSC_2, YUPL_1 + 22 + BTT2, nero);
        al_draw_text(font_section, nero, XUPL_1 + 100 + XOSC_2, YUPL_1 + 2 + BTT2, ALLEGRO_ALIGN_LEFT, "No Filter");
        al_draw_text(font_section, bianco, XUPL_1 + 200 + XOSC_2, YUPL_1 + 2 + BTT2, ALLEGRO_ALIGN_LEFT, "HPF");
        al_draw_text(font_section, bianco, XUPL_1 + 295 + XOSC_2, YUPL_1 + 2 + BTT2, ALLEGRO_ALIGN_LEFT, "LPF");
      }
      if(filter_sel_2 == 1){
        al_draw_filled_rectangle(XUPL_1 + 95 + XOSC_2, YUPL_1 + 2 + BTT2, XUPL_1 + 190 + XOSC_2, YUPL_1 + 22 + BTT2, nero);
        al_draw_filled_rectangle(XUPL_1 + 190 + 5 + XOSC_2, YUPL_1 + 2 + BTT2, XUPL_1 + 285 + XOSC_2 , YUPL_1 + 22 + BTT2, giallo);
        al_draw_filled_rectangle(XUPL_1 + 285 + 5 + XOSC_2, YUPL_1 + 2 + BTT2, XUPL_1 + 380 + XOSC_2, YUPL_1 + 22 + BTT2, nero);
        al_draw_text(font_section, bianco, XUPL_1 + 100 + XOSC_2, YUPL_1 + 2 + BTT2, ALLEGRO_ALIGN_LEFT, "No Filter");
        al_draw_text(font_section, nero, XUPL_1 + 200 + XOSC_2, YUPL_1 + 2 + BTT2, ALLEGRO_ALIGN_LEFT, "HPF");
        al_draw_text(font_section, bianco, XUPL_1 + 295 + XOSC_2, YUPL_1 + 2 + BTT2, ALLEGRO_ALIGN_LEFT, "LPF");
      }
      if(filter_sel_2 == 2){
        al_draw_filled_rectangle(XUPL_1 + 95 + XOSC_2, YUPL_1 + 2 + 150, XUPL_1 + 190 + XOSC_2, YUPL_1 + 22 + 150, nero);
        al_draw_filled_rectangle(XUPL_1 + 190 + 5 + XOSC_2, YUPL_1 + 2 + 150, XUPL_1 + 285 + XOSC_2 , YUPL_1 + 22 + 150, nero);
        al_draw_filled_rectangle(XUPL_1 + 285 + 5 + XOSC_2, YUPL_1 + 2 + 150, XUPL_1 + 380 + XOSC_2, YUPL_1 + 22 + 150, giallo);
        al_draw_text(font_section, bianco, XUPL_1 + 100 + XOSC_2, YUPL_1 + 2 + 150, ALLEGRO_ALIGN_LEFT, "No Filter");
        al_draw_text(font_section, bianco, XUPL_1 + 200 + XOSC_2, YUPL_1 + 2 + 150, ALLEGRO_ALIGN_LEFT, "HPF");
        al_draw_text(font_section, nero, XUPL_1 + 295 + XOSC_2, YUPL_1 + 2 + 150, ALLEGRO_ALIGN_LEFT, "LPF");
      }
    sem_post(&filter_2_s);

    for(int i = 0; i<=BUFFER_LEN; i++){
      c = wave_va.head + i % BUFFER_LEN;
      al_draw_circle(400 - i, 400 + 100 * - extract_CA(&wave_va_flt), 1, bianco, 1);
    }

    for(int i = 0; i<=BUFFER_LEN; i++){
      c = wave_va_2.head + i % BUFFER_LEN;
      al_draw_circle(400 + 400 - i, 400 + 100 * -extract_CA(&wave_va_2_flt), 1, bianco, 1);
    }

    al_flip_display();

    wait_period(&info_1);
  }
  al_destroy_display(display);
}