#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_color.h>
#include <math.h>
#include <sched.h>
#include <sys/timerfd.h>
#include <time.h>
#include <math.h>
#include <errno.h>
#include <semaphore.h>

#include <alsa/asoundlib.h>
#include <alsa/pcm.h>

#include "audio.h"
#include "graph_v_c.h"
#include "periodic.c"
#include "circular_array.c"
#include "variables.h"
#include "osc_f.c"
#include "error.c"
#include "rt_attr_task.c"
#include "graphic_init.c"
#include "graphic.c"
#include "input_handler.c"
#include "audio.c"