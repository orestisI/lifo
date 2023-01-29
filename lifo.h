#ifndef LIFO_H
#define LIFO_H

struct lifo_node_s{
	void *data;
	struct lifo_node_s *p;
};

struct lifo_s{
	struct lifo_node_s *head;
};

void lifo_init(struct lifo_s *lifo);
int lifo_push(struct lifo_s *lifo,void *data);
void *lifo_pop(struct lifo_s *lifo);
int lifo_is_empty(struct lifo_s *lifo);
void lifo_free(struct lifo_s *lifo);
void lifo_freee(struct lifo_s *lifo,void (*free_data)(void *));


#endif
