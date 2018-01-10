typedef struct Cricular_Array {
	float array[BUFFER_LEN];
	int head, tail, num;
	sem_t emp, mtx;
} c_queue;

void init_CA(c_queue *a){
	a->head = 0;
	a->tail = 0;
	a->num = 0;
	sem_init(&a->mtx, 0, 1);
	// avoid extraction when the queue is empty
	sem_init(&a->emp, 0, 0);
}

void insert_CA(c_queue *a, float elem){
	sem_wait(&a->mtx);
		a->array[a->head] = elem;
		a->head = (a->head + 1) % BUFFER_LEN;
		a->num++;
	sem_post(&a->mtx);
	sem_post(&a->emp);
}

float extract_CA(c_queue *a){
	float elem;
	sem_wait(&a->emp);
	sem_wait(&a->mtx);
		elem = a->array[a->tail];
		a->tail = (a->tail + 1) % BUFFER_LEN;
		a->num--;
	sem_post(&a->mtx);
	return elem;
}

int get_tail(c_queue *a){
	int ret = 0;
	sem_wait(&a->mtx);
		ret = a->head;
	sem_post(&a->mtx);
	return ret;
}

void increase_tail(c_queue *a){
	int ret = 0;
	sem_wait(&a->mtx);
		a->tail = (a->tail + 1) % BUFFER_LEN;
		a->num--;
	sem_post(&a->mtx);
}

float extract_n_CA(c_queue *a, int idx){
	float elem;
	sem_wait(&a->mtx);
		elem = a->array[idx];
	sem_post(&a->mtx);
	return elem;
}
