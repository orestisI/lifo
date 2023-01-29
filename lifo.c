#include"lifo.h"
#include"stdlib.h"

void lifo_init(struct lifo_s *lifo){
	lifo->head = NULL;
}

int lifo_push(struct lifo_s *lifo,void *data){
	struct lifo_node_s *lifo_node = (struct lifo_node_s *)malloc(sizeof(struct lifo_node_s));
	if (lifo_node == NULL) return 0;
	lifo_node->data = data;
	if (lifo->head == NULL){
		lifo->head = lifo_node;
	}
	else{
		lifo_node->p = lifo->head;
		lifo->head = lifo_node;
	}
	return 1;
}

void *lifo_pop(struct lifo_s *lifo){
	void *data;
	if (lifo->head == NULL) return NULL;
	struct lifo_node_s *tmp = lifo->head;
	lifo->head = tmp->p;
	data = tmp->data;
	free(tmp);
	return data;
}

int lifo_is_empty(struct lifo_s *lifo){
	return lifo->head == NULL;
}

void lifo_free(struct lifo_s *lifo){
	struct lifo_node_s *t1,*t2;
	t1 = lifo->head;
	while(t1 != NULL){
		t2 = t1->p;
		free(t1);
		t1 = t2;
	}
}

void lifo_freee(struct lifo_s *lifo,void (*free_data)(void *)){
	struct lifo_node_s *t1,*t2;
	void *data;
	t1 = lifo->head;
	while(t1 != NULL){
		t2 = t1->p;
		data = t1->data;
		free_data(data);
		free(t1);
		t1 = t2;
	}
}

