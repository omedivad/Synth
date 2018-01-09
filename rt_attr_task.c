void init_hrt_attr(pthread_attr_t *rt_attr, struct sched_param *hrt_param, int n){
	int ctrl_var = 0;
	int policy = SCHED_RR;
		// //initialize task attribute
	ctrl_var = pthread_attr_init(rt_attr);
	error_stamp(ctrl_var, 0, "pthread_attr_init");

	ctrl_var = pthread_attr_setschedpolicy(rt_attr, policy);
	error_stamp(ctrl_var, 0, "pthread_attr_setschedpolicy");

	ctrl_var = pthread_attr_setdetachstate(rt_attr, PTHREAD_CREATE_JOINABLE);
	error_stamp(ctrl_var, 0, "pthread_attr_setdetachstate");

	hrt_param->sched_priority = n;
	/* setting the new scheduling param */
	ctrl_var = pthread_attr_setschedparam(rt_attr, hrt_param);
	error_stamp(ctrl_var, 0, "pthread_setschedparam");

	ctrl_var = pthread_attr_setinheritsched(rt_attr, PTHREAD_EXPLICIT_SCHED);
	error_stamp(ctrl_var, 0, "pthread_attr_setinheritsched");
}

void init_hrt_attr_d(pthread_attr_t *rt_attr, struct sched_param *hrt_param, int n){
	int ctrl_var = 0;
	int policy = SCHED_RR;
		// //initialize task attribute
	ctrl_var = pthread_attr_init(rt_attr);
	error_stamp(ctrl_var, 0, "pthread_attr_init");

	ctrl_var = pthread_attr_setschedpolicy(rt_attr, policy);
	error_stamp(ctrl_var, 0, "pthread_attr_setschedpolicy");

	ctrl_var = pthread_attr_setdetachstate(rt_attr, PTHREAD_CREATE_DETACHED);
	error_stamp(ctrl_var, 0, "pthread_attr_setdetachstate");

	hrt_param->sched_priority = n;
	/* setting the new scheduling param */
	ctrl_var = pthread_attr_setschedparam(rt_attr, hrt_param);
	error_stamp(ctrl_var, 0, "pthread_setschedparam");

	ctrl_var = pthread_attr_setinheritsched(rt_attr, PTHREAD_EXPLICIT_SCHED);
	error_stamp(ctrl_var, 0, "pthread_attr_setinheritsched");
}