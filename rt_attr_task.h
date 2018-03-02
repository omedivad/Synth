#ifndef R_ATTR_H
#define R_ATTR_H

void init_hrt_attr(pthread_attr_t *rt_attr, struct sched_param *hrt_param, int n);
void init_hrt_attr_d(pthread_attr_t *rt_attr, struct sched_param *hrt_param, int n);

#endif