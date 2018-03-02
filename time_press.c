// #include <sys/time.h>
// #include <sys/timeb.h>
// #include <sys/timerfd.h>
#include "time_press.h"
#include "audio_var.h"

double get_time_press(int hold_l){
	// static int flag;
	// static double all;
	// double ns
	double all_2;
	// time_t sec;
	// struct timespec spec, spec_2;
	static double x = 0;
	static int release = 0;

	/*	note that variable 'release' is only used as precaution. While testing the program, I've noticed that allegro event
		ALLEGRO_EVENT_KEY_UP somethimes was triggered for few periods even if the keyboard button was still pressed. 
		So ?release? allows to stop incementing x if and only if the ALLEGRO_EVENT_KEY_UP event last more than 'release' periods */
	// if keybutton is pressed increment x
	if(hold_l == 1){
		// if(flag == 0){
		// 	clock_gettime(CLOCK_MONOTONIC, &spec);
		// 	sec = spec.tv_sec;
		// 	ns = spec.tv_nsec;
		// 	all = sec + ns / 1000000000L;
		// 	flag = 1;
		// }
		// clock_gettime(CLOCK_MONOTONIC, &spec_2);
		// sec = spec_2.tv_sec;
		// ns = spec_2.tv_nsec;
		// all_2 = (sec + ns / 1000000000L) - all;

		// uncomment this and comment time if you want to use sample time instead of current time
		x = x + (1.0 / (float)F_SAMPL);
		release = 0;
	}

	// set x to 0 if button is released
	if(hold_l == 0){
		// uncomment this and comment time if you want to use sample time instead of current time
		// all_2 = 0;
		// flag = 0;
		release = release + 1;
		if(release >= 40){
			x = 0;
			release = 0;
		}

	}
	// uncomment this and comment time if you want to use sample time instead of current time
	all_2 = x;

	return all_2;
}