void *graphic_f(void *arg){
  struct periodic_info info_1;
  ALLEGRO_COLOR giallo = al_map_rgb(255, 255, 224);
  ALLEGRO_COLOR nero = al_map_rgb(0, 0, 0);
  ALLEGRO_COLOR bianco = al_map_rgb(255, 255, 255);
  ALLEGRO_FONT *font_section = al_load_ttf_font("arial.ttf",15,0);
  int wave_old, wave_old_2;

  al_set_target_bitmap(al_get_backbuffer(display));
  make_periodic(41.666666666666664, &info_1);

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

    al_flip_display();

    wait_period(&info_1);
  }
  al_destroy_display(display);
}