#ifndef GRAPH_V_C_H
#define GRAPH_V_C_H

//-------------------------------------
//            Graphical Const         -
//-------------------------------------
// grafical constrants, used to draw the view in the graphical task
#define XWIN          800
#define YWIN          600
#define XUPL_1          0
#define X_BTT1_2       95	// x button 1 of 3
#define X_BTT2_2      195	// x button 2 of 3
#define X_BTT3_2      290	// x button 3 of 3
#define YUPL_1         26
#define XLOR_1        400
#define YLOR_1        226
#define XOSC_2        400
#define BTT2          150
#define BUFFER_LEN_G  400

// GRAPHICAL VARAIBLES & POINTERS
//  init pointer to synth display
ALLEGRO_DISPLAY *display;
// init pointer to credits and instruction display
ALLEGRO_DISPLAY *disp_key;
// init allegro event
ALLEGRO_EVENT ev;
// init pointer to allegro event queue
ALLEGRO_EVENT_QUEUE *event_queue;

#endif