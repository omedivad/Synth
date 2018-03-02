#include "circular_array.h"
#include "variables.h"
// initialize c_queue type
void init_CA(c_queue *a){
	a->head = 0;
	a->tail = 0;
	a->num = 0;
	sem_init(&a->mtx, 0, 1);
	// avoid extraction when the queue is empty
	sem_init(&a->emp, 0, 0);
	sem_init(&a->full, 0, BUFFER_LEN);
	for(int index = 0; index++; index < BUFFER_LEN)
		a->array[index] = 0;
}

// insert one element into c_queue type
void insert_CA(c_queue *a, float elem){
	// sem_wait(&a->full);
	sem_wait(&a->mtx);
		a->array[a->head] = elem;
		a->head = (a->head + 1) % BUFFER_LEN;
		a->num++;
	sem_post(&a->mtx);
	sem_post(&a->emp);
}

// extract one element into c_queue type
float extract_CA(c_queue *a){
	float elem;
	sem_wait(&a->emp);
	sem_wait(&a->mtx);
		elem = a->array[a->tail];
		a->tail = (a->tail + 1) % BUFFER_LEN;
		a->num--;
	sem_post(&a->mtx);
	// sem_post(&a->full);
	return elem;
}

// get ectraction index
int get_head(c_queue *a){
	int ret;
	sem_wait(&a->mtx);
		ret = a->head;
	sem_post(&a->mtx);
	return ret;
}

// get ectraction index
int get_tail(c_queue *a){
	int ret;
	sem_wait(&a->mtx);
		ret = a->tail;
	sem_post(&a->mtx);
	return ret;
}

// get num
int get_num(c_queue *a){
	int ret;
	sem_wait(&a->mtx);
		ret = a->num;
	sem_post(&a->mtx);
	return ret;
}


// increase tail index
void increase_tail(c_queue *a){
	sem_wait(&a->mtx);
		a->tail = (a->tail + 1) % BUFFER_LEN;
		a->num--;
	sem_post(&a->mtx);
}

// extract an element identified by a given index
float extract_n_CA(c_queue *a, int idx){
	float elem = 0;
	sem_wait(&a->mtx);
		elem = a->array[idx];
	sem_post(&a->mtx);
	return elem;
}
