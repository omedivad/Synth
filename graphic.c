void *graphic_f(void *arg){
  int hd1, hd2;
  // needed to make task periodic, fo "make_periodic()" from FILE "periodic.c"
  struct periodic_info info_1;
  // set colors
  ALLEGRO_COLOR giallo = al_map_rgb(255, 255, 224);
  ALLEGRO_COLOR nero = al_map_rgb(0, 0, 0);
  ALLEGRO_COLOR bianco = al_map_rgb(255, 255, 255);
  ALLEGRO_COLOR boch = al_map_rgb(120, 120, 120);
  ALLEGRO_COLOR grigio = al_map_rgb(51, 51, 51);
  ALLEGRO_BITMAP *vol = NULL;
  ALLEGRO_BITMAP *ptc = NULL;
  // set fonts
  ALLEGRO_FONT *font_title = al_load_ttf_font("arial.ttf",24,0);
  ALLEGRO_FONT *font_section = al_load_ttf_font("arial.ttf",15,0);
  ALLEGRO_FONT *font_command = al_load_ttf_font("arial.ttf",12,0);
  // local variables to store wave val to print on screen (when wave draw is enabled)
  int c = 0;
  int c_2 = 0;
  int it;
  float period = 33333333.333333332;
  float wf1, wf2;

  // set backbuffer of display as target
  al_set_target_bitmap(al_get_backbuffer(display)); // setting target to display backbuffer

  // make task periodic FILE "periodic.c"
  /* note that the period is less than audio task because its calculated as 1 / 24
     according to the fact that 24 is the minimum framerate perceptible to human eyes */
  make_periodic(period, &info_1);

  // bitmaps initialization for volume and pitch knobs
  vol = al_create_bitmap(40, 40);
  ptc = al_create_bitmap(40, 40);

  /* Note that each allegro_5 display ha2 two buffers: the first on is printed,
     while the second one is called backbuffer and it the buffer when draw command acts.
     So, once draw commands are executed we need to flip displays with al_flip_display()
     function to show the applied changes */

  // needed to write on backbuffer flip display and write on the second buffer
  for(int i=0; i<2; i++){
    // color all screen with gray
    al_clear_to_color(grigio);
    // Title
    al_draw_text(font_title, bianco, XWIN/2, 0, ALLEGRO_ALIGN_CENTER, "SYNTH A ME");

    // Main graphical division lines and rectangles
    al_draw_rectangle(XUPL_1, YUPL_1, XLOR_1, YLOR_1, bianco, 1);
    al_draw_rectangle(XUPL_1 + 400, YUPL_1, XLOR_1 + 400, YLOR_1, bianco, 1);

    al_draw_rectangle(XUPL_1, YLOR_1, XLOR_1, 2 * YLOR_1, bianco, 1);
    al_draw_rectangle(XUPL_1 + 400, YLOR_1, XLOR_1 + 400, 2 * YLOR_1, bianco, 1);

    al_draw_text(font_section, bianco, XUPL_1 + 2, YUPL_1 + 2, ALLEGRO_ALIGN_LEFT, "OSC 1");
    al_draw_text(font_section, bianco, XUPL_1 + 402, YUPL_1 + 2, ALLEGRO_ALIGN_LEFT, "OSC 2");

    // Creating bitmap volume knob

    // set target to vol bitmap
    al_set_target_bitmap(vol);
    // color bitmap with gray
    al_clear_to_color(grigio);
    // draw knob interior part
    al_draw_filled_circle(20, 20, 20, boch);
    // draw knob border
    al_draw_circle(20, 20, 20, nero, 1);
    // drow knob indicator line
    al_draw_line(20, 0, 20, 15, nero, 2);
    
    // Creating pitch volume knob

    al_set_target_bitmap(ptc);
    al_clear_to_color(grigio);

    al_draw_filled_circle(20, 20, 20, boch);
    al_draw_circle(20, 20, 20, nero, 1);
    al_draw_line(18, 40, 20, 25, nero, 2);

    // set target to display
    al_set_target_bitmap(al_get_backbuffer(display));

    // flip display
    al_flip_display();
  }

  // all draw commands in while loop refresh graphical loop after user input
  while(end == 0){
    // WAVE FORM selection buttons

    // BUTTONs OSC 1 wave selecction
      // sine selected
      if(wave_sel == SIN){
        al_draw_filled_rectangle(XUPL_1 + X_BTT1_2, YUPL_1 + 2, XUPL_1 + 190, YUPL_1 + 22, giallo);
        al_draw_filled_rectangle(XUPL_1 + X_BTT2_2, YUPL_1 + 2, XUPL_1 + 285, YUPL_1 + 22, nero);
        al_draw_filled_rectangle(XUPL_1 + X_BTT3_2, YUPL_1 + 2, XUPL_1 + 380, YUPL_1 + 22, nero);
        al_draw_filled_rectangle(XUPL_1 + X_BTT1_2, YUPL_1 + 26, XUPL_1 + 190, YUPL_1 + 46, nero);
        al_draw_text(font_section, nero, XUPL_1 + 100, YUPL_1 + 2, ALLEGRO_ALIGN_LEFT, "Sine");
        al_draw_text(font_section, bianco, XUPL_1 + 200, YUPL_1 + 2, ALLEGRO_ALIGN_LEFT, "Square");
        al_draw_text(font_section, bianco, XUPL_1 + 295, YUPL_1 + 2, ALLEGRO_ALIGN_LEFT, "Saw");
        al_draw_text(font_section, bianco, XUPL_1 + 100, YUPL_1 + 26, ALLEGRO_ALIGN_LEFT, "NOISE");
      }
      // square selected
      if(wave_sel == SQR){
        al_draw_filled_rectangle(XUPL_1 + X_BTT1_2, YUPL_1 + 2, XUPL_1 + 190, YUPL_1 + 22, nero);
        al_draw_filled_rectangle(XUPL_1 + X_BTT2_2, YUPL_1 + 2, XUPL_1 + 285, YUPL_1 + 22, giallo);
        al_draw_filled_rectangle(XUPL_1 + X_BTT3_2, YUPL_1 + 2, XUPL_1 + 380, YUPL_1 + 22, nero);
        al_draw_filled_rectangle(XUPL_1 + X_BTT1_2, YUPL_1 + 26, XUPL_1 + 190, YUPL_1 + 46, nero);
        al_draw_text(font_section, bianco, XUPL_1 + 100, YUPL_1 + 2, ALLEGRO_ALIGN_LEFT, "Sine");
        al_draw_text(font_section, nero, XUPL_1 + 200, YUPL_1 + 2, ALLEGRO_ALIGN_LEFT, "Square");
        al_draw_text(font_section, bianco, XUPL_1 + 295, YUPL_1 + 2, ALLEGRO_ALIGN_LEFT, "Saw");
        al_draw_text(font_section, bianco, XUPL_1 + 100, YUPL_1 + 26, ALLEGRO_ALIGN_LEFT, "NOISE");
      }
      // Sawtooth selected
      if(wave_sel == SAW){
        al_draw_filled_rectangle(XUPL_1 + X_BTT1_2, YUPL_1 + 2, XUPL_1 + 190, YUPL_1 + 22, nero);
        al_draw_filled_rectangle(XUPL_1 + X_BTT2_2, YUPL_1 + 2, XUPL_1 + 285, YUPL_1 + 22, nero);
        al_draw_filled_rectangle(XUPL_1 + X_BTT3_2, YUPL_1 + 2, XUPL_1 + 380, YUPL_1 + 22, giallo);
        al_draw_filled_rectangle(XUPL_1 + X_BTT1_2, YUPL_1 + 26, XUPL_1 + 190, YUPL_1 + 46, nero);
        al_draw_text(font_section, bianco, XUPL_1 + 100, YUPL_1 + 2, ALLEGRO_ALIGN_LEFT, "Sine");
        al_draw_text(font_section, bianco, XUPL_1 + 200, YUPL_1 + 2, ALLEGRO_ALIGN_LEFT, "Square");
        al_draw_text(font_section, nero, XUPL_1 + 295, YUPL_1 + 2, ALLEGRO_ALIGN_LEFT, "Saw");
        al_draw_text(font_section, bianco, XUPL_1 + 100, YUPL_1 + 26, ALLEGRO_ALIGN_LEFT, "NOISE");
      }
      // Noise selected
      if(wave_sel == NSE){
        al_draw_filled_rectangle(XUPL_1 + X_BTT1_2, YUPL_1 + 2, XUPL_1 + 190, YUPL_1 + 22, nero);
        al_draw_filled_rectangle(XUPL_1 + X_BTT2_2, YUPL_1 + 2, XUPL_1 + 285, YUPL_1 + 22, nero);
        al_draw_filled_rectangle(XUPL_1 + X_BTT3_2, YUPL_1 + 2, XUPL_1 + 380, YUPL_1 + 22, nero);
        al_draw_filled_rectangle(XUPL_1 + X_BTT1_2, YUPL_1 + 26, XUPL_1 + 190, YUPL_1 + 46, giallo);
        al_draw_text(font_section, bianco, XUPL_1 + 100, YUPL_1 + 2, ALLEGRO_ALIGN_LEFT, "Sine");
        al_draw_text(font_section, bianco, XUPL_1 + 200, YUPL_1 + 2, ALLEGRO_ALIGN_LEFT, "Square");
        al_draw_text(font_section, bianco, XUPL_1 + 295, YUPL_1 + 2, ALLEGRO_ALIGN_LEFT, "Saw");
        al_draw_text(font_section, nero, XUPL_1 + 100, YUPL_1 + 26, ALLEGRO_ALIGN_LEFT, "NOISE");
      }
    
    // BUTTONs OSC 2 wave selection
      // Sine selected
      if(wave_sel_2 == SIN){
        al_draw_filled_rectangle(XUPL_1 + X_BTT1_2 + XOSC_2, YUPL_1 + 2, XUPL_1 + 190 + XOSC_2, YUPL_1 + 22, giallo);
        al_draw_filled_rectangle(XUPL_1 + X_BTT2_2 + XOSC_2, YUPL_1 + 2, XUPL_1 + 285 + XOSC_2 , YUPL_1 + 22, nero);
        al_draw_filled_rectangle(XUPL_1 + X_BTT3_2 + XOSC_2, YUPL_1 + 2, XUPL_1 + 380 + XOSC_2, YUPL_1 + 22, nero);
        al_draw_filled_rectangle(XUPL_1 + X_BTT1_2 + XOSC_2, YUPL_1 + 26, XUPL_1 + 190 + XOSC_2, YUPL_1 + 46, nero);
        al_draw_text(font_section, nero, XUPL_1 + 100 + XOSC_2, YUPL_1 + 2, ALLEGRO_ALIGN_LEFT, "Sine");
        al_draw_text(font_section, bianco, XUPL_1 + 200 + XOSC_2, YUPL_1 + 2, ALLEGRO_ALIGN_LEFT, "Square");
        al_draw_text(font_section, bianco, XUPL_1 + 295 + XOSC_2, YUPL_1 + 2, ALLEGRO_ALIGN_LEFT, "Saw");
        al_draw_text(font_section, bianco, XUPL_1 + 100 + XOSC_2, YUPL_1 + 26, ALLEGRO_ALIGN_LEFT, "NOISE");
      }
      // Square selected
      if(wave_sel_2 == SQR){
        al_draw_filled_rectangle(XUPL_1 + X_BTT1_2 + XOSC_2, YUPL_1 + 2, XUPL_1 + 190 + XOSC_2, YUPL_1 + 22, nero);
        al_draw_filled_rectangle(XUPL_1 + X_BTT2_2 + XOSC_2, YUPL_1 + 2, XUPL_1 + 285 + XOSC_2 , YUPL_1 + 22, giallo);
        al_draw_filled_rectangle(XUPL_1 + X_BTT3_2 + XOSC_2, YUPL_1 + 2, XUPL_1 + 380 + XOSC_2, YUPL_1 + 22, nero);
        al_draw_filled_rectangle(XUPL_1 + X_BTT1_2 + XOSC_2, YUPL_1 + 26, XUPL_1 + 190 + XOSC_2, YUPL_1 + 46, nero);
        al_draw_text(font_section, bianco, XUPL_1 + 100 + XOSC_2, YUPL_1 + 2, ALLEGRO_ALIGN_LEFT, "Sine");
        al_draw_text(font_section, nero, XUPL_1 + 200 + XOSC_2, YUPL_1 + 2, ALLEGRO_ALIGN_LEFT, "Square");
        al_draw_text(font_section, bianco, XUPL_1 + 295 + XOSC_2, YUPL_1 + 2, ALLEGRO_ALIGN_LEFT, "Saw");
        al_draw_text(font_section, bianco, XUPL_1 + 100 + XOSC_2, YUPL_1 + 26, ALLEGRO_ALIGN_LEFT, "NOISE");
      }
      // sawtooth selected
      if(wave_sel_2 == SAW){
        al_draw_filled_rectangle(XUPL_1 + X_BTT1_2 + XOSC_2, YUPL_1 + 2, XUPL_1 + 190 + XOSC_2, YUPL_1 + 22, nero);
        al_draw_filled_rectangle(XUPL_1 + X_BTT2_2 + XOSC_2, YUPL_1 + 2, XUPL_1 + 285 + XOSC_2 , YUPL_1 + 22, nero);
        al_draw_filled_rectangle(XUPL_1 + X_BTT3_2 + XOSC_2, YUPL_1 + 2, XUPL_1 + 380 + XOSC_2, YUPL_1 + 22, giallo);
        al_draw_filled_rectangle(XUPL_1 + X_BTT1_2 + XOSC_2, YUPL_1 + 26, XUPL_1 + 190 + XOSC_2, YUPL_1 + 46, nero);
        al_draw_text(font_section, bianco, XUPL_1 + 100 + XOSC_2, YUPL_1 + 2, ALLEGRO_ALIGN_LEFT, "Sine");
        al_draw_text(font_section, bianco, XUPL_1 + 200 + XOSC_2, YUPL_1 + 2, ALLEGRO_ALIGN_LEFT, "Square");
        al_draw_text(font_section, nero, XUPL_1 + 295 + XOSC_2, YUPL_1 + 2, ALLEGRO_ALIGN_LEFT, "Saw");
        al_draw_text(font_section, bianco, XUPL_1 + 100 + XOSC_2, YUPL_1 + 26, ALLEGRO_ALIGN_LEFT, "NOISE");
      }
      // noise selected
      if(wave_sel_2 == NSE){
        al_draw_filled_rectangle(XUPL_1 + X_BTT1_2 + XOSC_2, YUPL_1 + 2, XUPL_1 + 190 + XOSC_2, YUPL_1 + 22, nero);
        al_draw_filled_rectangle(XUPL_1 + X_BTT2_2 + XOSC_2, YUPL_1 + 2, XUPL_1 + 285 + XOSC_2, YUPL_1 + 22, nero);
        al_draw_filled_rectangle(XUPL_1 + X_BTT3_2 + XOSC_2, YUPL_1 + 2, XUPL_1 + 380 + XOSC_2, YUPL_1 + 22, nero);
        al_draw_filled_rectangle(XUPL_1 + X_BTT1_2 + XOSC_2, YUPL_1 + 26, XUPL_1 + 190 + XOSC_2, YUPL_1 + 46, giallo);
        al_draw_text(font_section, bianco, XUPL_1 + 100 + XOSC_2, YUPL_1 + 2, ALLEGRO_ALIGN_LEFT, "Sine");
        al_draw_text(font_section, bianco, XUPL_1 + 200 + XOSC_2, YUPL_1 + 2, ALLEGRO_ALIGN_LEFT, "Square");
        al_draw_text(font_section, bianco, XUPL_1 + 295 + XOSC_2, YUPL_1 + 2, ALLEGRO_ALIGN_LEFT, "Saw");
        al_draw_text(font_section, nero, XUPL_1 + 100 + XOSC_2, YUPL_1 + 26, ALLEGRO_ALIGN_LEFT, "NOISE");
      }

    // vol 1 knob
    al_draw_rotated_bitmap(vol, 20, 20, 350, 100, (float)amplitude * (2.0 * PI) * 4.0 / 5.0 - (2.0 * PI) * (2.0 / 5.0), 0);
    al_draw_filled_rectangle(310, 120, 399, 150, grigio);
    al_draw_line(338, 115, 330, 125, bianco, 1);
    al_draw_text(font_command, bianco, 322, 127, ALLEGRO_ALIGN_CENTER, "- inf");
    al_draw_line(338 + 25, 115, 330 + 40, 125, bianco, 1);
    al_draw_text(font_command, bianco, 325 + 50, 127, ALLEGRO_ALIGN_CENTER, "+ inf");
    al_draw_text(font_section, bianco, 350, 120, ALLEGRO_ALIGN_CENTER, "Vol");

    // vol 2 knob
    al_draw_rotated_bitmap(vol, 20, 20, 400 + 350, 100, (float)amplitude_2 * (2.0 * PI) * 4.0 / 5.0 - (2.0 * PI) * (2.0 / 5.0), 0);
    al_draw_filled_rectangle(400 + 310, 120, 400 + 399, 150, grigio);
    al_draw_line(400 + 338, 115, 400 + 330, 125, bianco, 1);
    al_draw_text(font_command, bianco, 400 + 322, 127, ALLEGRO_ALIGN_CENTER, "- inf");
    al_draw_line(400 + 338 + 25, 115, 400 + 330 + 40, 125, bianco, 1);
    al_draw_text(font_command, bianco, 400 + 325 + 50, 127, ALLEGRO_ALIGN_CENTER, "+ inf");
    al_draw_text(font_section, bianco, 400 + 350, 120, ALLEGRO_ALIGN_CENTER, "Vol");

    // frequency
    al_draw_filled_rectangle(2, 51, 92, 65, grigio);
    al_draw_textf(font_section, bianco, XUPL_1 + 2, YUPL_1 + 25, ALLEGRO_ALIGN_LEFT,"%.2f Hz", wave_f * pitch);
    al_draw_filled_rectangle(400 + 2, 51, 400 + 92, 65, grigio);
    al_draw_textf(font_section, bianco, XUPL_1 + 2 + 400, YUPL_1 + 25, ALLEGRO_ALIGN_LEFT,"%.2f Hz", wave_f * pitch_2);

    // pitch 1 knob
    al_draw_rotated_bitmap(ptc, 20, 20, 250, 100, (float)pitch / 2, 0);
    al_draw_filled_rectangle(210, 120, 299, 150, grigio);
    al_draw_line(238, 115, 230, 125, bianco, 1);
    al_draw_text(font_command, bianco, 222, 127, ALLEGRO_ALIGN_CENTER, "0");
    al_draw_line(238 + 25, 115, 230 + 40, 125, bianco, 1);
    al_draw_text(font_command, bianco, 225 + 50, 127, ALLEGRO_ALIGN_CENTER, "+");
    al_draw_text(font_section, bianco, 250, 120, ALLEGRO_ALIGN_CENTER, "pitch");

    // pitch 2 knob
    al_draw_rotated_bitmap(ptc, 20, 20, 400 + 250, 100, (float)pitch_2 / 2, 0);
    al_draw_filled_rectangle(400 + 210, 120, 400 + 299, 150, grigio);
    al_draw_line(400 + 238, 115, 400 + 230, 125, bianco, 1);
    al_draw_text(font_command, bianco, 400 + 222, 127, ALLEGRO_ALIGN_CENTER, "0");
    al_draw_line(400 + 238 + 25, 115, 400 + 230 + 40, 125, bianco, 1);
    al_draw_text(font_command, bianco, 400 + 225 + 50, 127, ALLEGRO_ALIGN_CENTER, "+");
    al_draw_text(font_section, bianco, 400 + 250, 120, ALLEGRO_ALIGN_CENTER, "pitch");
    al_draw_filled_rectangle(XUPL_1, YLOR_1, XLOR_1, 3 * YLOR_1, grigio);
    al_draw_filled_rectangle(XUPL_1 + 400, YLOR_1, XLOR_1 + 400, 3 * YLOR_1, grigio);

    al_draw_rectangle(XUPL_1, YLOR_1, XLOR_1, 2 * YLOR_1, bianco, 1);
    al_draw_rectangle(XUPL_1 + 400, YLOR_1, XLOR_1 + 400, 2 * YLOR_1, bianco, 1);

    // filter buttons

    // BUTTONs OSC 1
    sem_wait(&filter_s);
      if(filter_sel == NFLT){
        al_draw_filled_rectangle(XUPL_1 + 95, YUPL_1 + 2 + BTT2, XUPL_1 + 190, YUPL_1 + 22 + BTT2, giallo);
        al_draw_filled_rectangle(XUPL_1 + 190 + 5, YUPL_1 + 2 + BTT2, XUPL_1 + 285, YUPL_1 + 22 + BTT2, nero);
        al_draw_filled_rectangle(XUPL_1 + 285 + 5, YUPL_1 + 2 + BTT2, XUPL_1 + 380, YUPL_1 + 22 + BTT2, nero);
        al_draw_text(font_section, nero, XUPL_1 + 100, YUPL_1 + 2 + BTT2, ALLEGRO_ALIGN_LEFT, "No filter");
        al_draw_text(font_section, bianco, XUPL_1 + 200, YUPL_1 + 2 + BTT2, ALLEGRO_ALIGN_LEFT, "HPF");
        al_draw_text(font_section, bianco, XUPL_1 + 295, YUPL_1 + 2 + BTT2, ALLEGRO_ALIGN_LEFT, "LPF");
      }
      if(filter_sel == HPF){
        al_draw_filled_rectangle(XUPL_1 + 95, YUPL_1 + 2 + BTT2, XUPL_1 + 190, YUPL_1 + 22 + BTT2, nero);
        al_draw_filled_rectangle(XUPL_1 + 190 + 5, YUPL_1 + 2 + BTT2, XUPL_1 + 285, YUPL_1 + 22 + BTT2, giallo);
        al_draw_filled_rectangle(XUPL_1 + 285 + 5, YUPL_1 + 2 + BTT2, XUPL_1 + 380, YUPL_1 + 22 + BTT2, nero);
        al_draw_text(font_section, bianco, XUPL_1 + 100, YUPL_1 + 2 + BTT2, ALLEGRO_ALIGN_LEFT, "No Filter");
        al_draw_text(font_section, nero, XUPL_1 + 200, YUPL_1 + 2 + BTT2, ALLEGRO_ALIGN_LEFT, "HPF");
        al_draw_text(font_section, bianco, XUPL_1 + 295, YUPL_1 + 2 + BTT2, ALLEGRO_ALIGN_LEFT, "LPF");
      }
      if(filter_sel == LPF){
        al_draw_filled_rectangle(XUPL_1 + 95, YUPL_1 + 2 + BTT2, XUPL_1 + 190, YUPL_1 + 22 + BTT2, nero);
        al_draw_filled_rectangle(XUPL_1 + 190 + 5, YUPL_1 + 2 + BTT2, XUPL_1 + 285, YUPL_1 + 22 + BTT2, nero);
        al_draw_filled_rectangle(XUPL_1 + 285 + 5, YUPL_1 + 2 + BTT2, XUPL_1 + 380, YUPL_1 + 22 + BTT2, giallo);
        al_draw_text(font_section, bianco, XUPL_1 + 100, YUPL_1 + 2 + BTT2, ALLEGRO_ALIGN_LEFT, "No Filter");
        al_draw_text(font_section, bianco, XUPL_1 + 200, YUPL_1 + 2 + BTT2, ALLEGRO_ALIGN_LEFT, "HPF");
        al_draw_text(font_section, nero, XUPL_1 + 295, YUPL_1 + 2 + BTT2, ALLEGRO_ALIGN_LEFT, "LPF");
      }
    sem_post(&filter_s);

    // BUTTONs OSC 2
    sem_wait(&filter_2_s);
      if(filter_sel_2 == NFLT){
        al_draw_filled_rectangle(XUPL_1 + 95 + XOSC_2, YUPL_1 + 2 + BTT2, XUPL_1 + 190 + XOSC_2, YUPL_1 + 22 + BTT2, giallo);
        al_draw_filled_rectangle(XUPL_1 + 190 + 5 + XOSC_2, YUPL_1 + 2 + BTT2, XUPL_1 + 285 + XOSC_2 , YUPL_1 + 22 + BTT2, nero);
        al_draw_filled_rectangle(XUPL_1 + 285 + 5 + XOSC_2, YUPL_1 + 2 + BTT2, XUPL_1 + 380 + XOSC_2, YUPL_1 + 22 + BTT2, nero);
        al_draw_text(font_section, nero, XUPL_1 + 100 + XOSC_2, YUPL_1 + 2 + BTT2, ALLEGRO_ALIGN_LEFT, "No Filter");
        al_draw_text(font_section, bianco, XUPL_1 + 200 + XOSC_2, YUPL_1 + 2 + BTT2, ALLEGRO_ALIGN_LEFT, "HPF");
        al_draw_text(font_section, bianco, XUPL_1 + 295 + XOSC_2, YUPL_1 + 2 + BTT2, ALLEGRO_ALIGN_LEFT, "LPF");
      }
      if(filter_sel_2 == HPF){
        al_draw_filled_rectangle(XUPL_1 + 95 + XOSC_2, YUPL_1 + 2 + BTT2, XUPL_1 + 190 + XOSC_2, YUPL_1 + 22 + BTT2, nero);
        al_draw_filled_rectangle(XUPL_1 + 190 + 5 + XOSC_2, YUPL_1 + 2 + BTT2, XUPL_1 + 285 + XOSC_2 , YUPL_1 + 22 + BTT2, giallo);
        al_draw_filled_rectangle(XUPL_1 + 285 + 5 + XOSC_2, YUPL_1 + 2 + BTT2, XUPL_1 + 380 + XOSC_2, YUPL_1 + 22 + BTT2, nero);
        al_draw_text(font_section, bianco, XUPL_1 + 100 + XOSC_2, YUPL_1 + 2 + BTT2, ALLEGRO_ALIGN_LEFT, "No Filter");
        al_draw_text(font_section, nero, XUPL_1 + 200 + XOSC_2, YUPL_1 + 2 + BTT2, ALLEGRO_ALIGN_LEFT, "HPF");
        al_draw_text(font_section, bianco, XUPL_1 + 295 + XOSC_2, YUPL_1 + 2 + BTT2, ALLEGRO_ALIGN_LEFT, "LPF");
      }
      if(filter_sel_2 == LPF){
        al_draw_filled_rectangle(XUPL_1 + 95 + XOSC_2, YUPL_1 + 2 + 150, XUPL_1 + 190 + XOSC_2, YUPL_1 + 22 + 150, nero);
        al_draw_filled_rectangle(XUPL_1 + 190 + 5 + XOSC_2, YUPL_1 + 2 + 150, XUPL_1 + 285 + XOSC_2 , YUPL_1 + 22 + 150, nero);
        al_draw_filled_rectangle(XUPL_1 + 285 + 5 + XOSC_2, YUPL_1 + 2 + 150, XUPL_1 + 380 + XOSC_2, YUPL_1 + 22 + 150, giallo);
        al_draw_text(font_section, bianco, XUPL_1 + 100 + XOSC_2, YUPL_1 + 2 + 150, ALLEGRO_ALIGN_LEFT, "No Filter");
        al_draw_text(font_section, bianco, XUPL_1 + 200 + XOSC_2, YUPL_1 + 2 + 150, ALLEGRO_ALIGN_LEFT, "HPF");
        al_draw_text(font_section, nero, XUPL_1 + 295 + XOSC_2, YUPL_1 + 2 + 150, ALLEGRO_ALIGN_LEFT, "LPF");
      }
    sem_post(&filter_2_s);

    // draw wave box
    if(draw_wave == 0){
      al_draw_filled_rectangle(XUPL_1 + 5, YUPL_1 + 60 + BTT2, XUPL_1 + 95, YUPL_1 + 82 + BTT2, nero);
      al_draw_text(font_section, bianco, XUPL_1 + 10, YUPL_1 + 62 + BTT2, ALLEGRO_ALIGN_LEFT, "Draw Wave");
    }
    if(draw_wave == 1){
      al_draw_filled_rectangle(XUPL_1 + 5, YUPL_1 + 60 + BTT2, XUPL_1 + 95, YUPL_1 + 82 + BTT2, giallo);
      al_draw_text(font_section, nero, XUPL_1 + 10, YUPL_1 + 62 + BTT2, ALLEGRO_ALIGN_LEFT, "Draw Wave");
    }

    // Waveform draw OSC1 and OSC2
    
    // get OSC1 and OSC2 filtered values inedx
    hd1 = get_head(&wave_va_flt);
    hd2 = get_head(&wave_va_2_flt);

    if(draw_wave == 1){
      /*  note that due to period difference between audio tasks and graphical task it's better to take data directly from
          shared memory and not to store values in a local array and then get those value when needed. In fact, graphical exectues 24 times
          in a second, while graphical tasks eectutes 44800 times in a second. Thus, every loop of graphical task (48000 / 24) = 2000 samples
          are created from audio tasks. On the other side, the pixel designated to show waves in printed window are 800. This implies that
          higher performace are gained printig directly from shared memory buffers. */

      // draw waves
      for(it = 0; it < 800; it++){
        // caluclating idex to extract the last 800 samples from shared memory buffers

        // index OSC1
        c = ((hd1 - it) % BUFFER_LEN + BUFFER_LEN) % BUFFER_LEN;
        //index OSC2
        c_2 = ((hd2 - it) % BUFFER_LEN + BUFFER_LEN) % BUFFER_LEN;

        // storing samples to local variable
        wf1 = extract_n_CA(&wave_va_flt, c);
        wf2 = extract_n_CA(&wave_va_2_flt, c_2);

        // drowing OSC1 and OSC2. The space designated to display the two waves is 400px wide
        if (it < 400){
          // drow OSC1 wave
          al_draw_circle(399 - it, 350 + 80 * (-1) * wf1, 1, bianco, 2);
          // draw OSC2 wave
          al_draw_circle(799 - it, 350 + 80 * (-1) * wf2, 1, bianco, 2);
        }
        // draw OSC1 + OSC2 wave
        al_draw_circle(799 - it, 550 + 80 * (-1) * (wf1 + wf2) / 2.0, 1, bianco, 1);
      }
    }

    // switching backbuffer
    al_flip_display();

    //wait for period
    wait_period(&info_1);
  }

  // destroy bitmaps
  al_destroy_display(display);
  al_destroy_bitmap(vol);
  al_destroy_bitmap(ptc);
}
