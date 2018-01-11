double get_time_press(int hold){
	static int flag;
	static double all;
	double ns, all_2;
	time_t sec;
	struct timespec spec, spec_2;
	static double x = 0;

	if(hold == 1){
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
		x = x + (1.0 / 48000.0);
	}
	if(hold == 0){
		// uncomment this and comment time if you want to use sample time instead of current time
		// all_2 = 0;
		// flag = 0;

		x = 0;
	}
	// uncomment this and comment time if you want to use sample time instead of current time
	all_2 = x;

	return all_2;
}