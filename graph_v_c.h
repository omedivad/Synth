//-------------------------------------
//            Graphical Const         -
//-------------------------------------
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
ALLEGRO_DISPLAY *display = NULL;
ALLEGRO_DISPLAY *disp_key = NULL;
ALLEGRO_EVENT ev;
ALLEGRO_EVENT_QUEUE *event_queue = NULL;

// control draw wave
int draw_wave = 0;
