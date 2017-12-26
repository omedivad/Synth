typedef struct Cricular_Array {
	int array[400];
	int head, tail;
} c_queue;

void init_CA(c_queue *a){
	a->head = 0;
	a->tail = 0;
	for(int i=0, i<400, i++){
		arrai[i]=0;
	}
}

int insert_CA(c_queue *a, int elem){
	a->array[a->head] = elem;
	a->head = (a->head + 1) % 400;
	return 1;
}

int extract_CA(c_queue *a, int elem[]){
	elem = a->array;
}