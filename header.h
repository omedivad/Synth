#include <math.h>
#include <time.h>
#include <stdio.h>
#include <sched.h>
#include <errno.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <sys/timeb.h>
#include <semaphore.h>
#include <sys/timerfd.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_primitives.h>

// audio.h inludes audio constants and open stream channel
#include "audio.h"
// graph_v_c.h includes visual constants and initialize two allegro displays and one event queue
// #include "graph_v_c.h"
// periodic.c includes functions to make threads periodic
// #include "periodic.c"
// circular_array.c includes circular array struct and functions to interact with the struct
// #include "circular_array.c"
// variables.h includes global variables and semaphores related to those variables
#include "circular_array.h"
#include "variables.h"
// osc_f.c read global variables and write wave value on one array shared with filter.c
// #include "osc_f.c"
// error.c include function to print error both on log.txt and on standart out
// #include "error.c"
// rt_attr_task.c initialize pthreads attribute
// #include "rt_attr_task.c"
// all_init.c initializes allegro and its addons
// #include "all_init.c"
// graphic.c contains the graphical task
// #include "graphic.c"
// input_handler.c handles user inputs
// #include "input_handler.c"
// audio.c open and fill audio channel
// #include "audio.c"

// filter.c takes sample from osc-filter buffer, applies filter and writes the value on filter-audio_channel buffer
// #include "filter.c"