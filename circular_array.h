#ifndef CIRCULAR_ARRAY_H
#define CIRCULAR_ARRAY_H

#include <semaphore.h>
#include "audio_var.h"

typedef struct Circular_Array {
	float array[BUFFER_LEN];
	int head, tail, num;
	sem_t emp, mtx, full;
} c_queue;

void init_CA(c_queue *a);
void insert_CA(c_queue *a, float elem);
float extract_CA(c_queue *a);
int get_head(c_queue *a);
int get_tail(c_queue *a);
int get_num(c_queue *a);
void increase_tail(c_queue *a);
float extract_n_CA(c_queue *a, int idx);


#endif