#include"lifo.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct ex_s{
	int id;
	char *name;
};

struct ex_s *ex_s_init(int id,const char *name){
	struct ex_s *ex = (struct ex_s *)malloc(sizeof(struct ex_s));
	ex->id = id;
	ex->name = (char *)malloc(strlen(name) + 1);
	strcpy(ex->name,name);
	return ex;
}

void ex_s_free(void *ex_v){
	struct ex_s *ex = (struct ex_s *)ex_v;
	free(ex->name);
	free(ex);
}

void ex_s_print(void *ex_v){
	struct ex_s *ex = (struct ex_s *)ex_v;
	printf("Id = %d\n",ex->id);
	printf("Name = %s\n",ex->name);
	printf("-----\n");
}

int main(){
	struct lifo_s lifo;
	lifo_init(&lifo);
	//
	struct ex_s *ex1 = ex_s_init(0,"george");
	struct ex_s *ex2 = ex_s_init(1,"maria");
	struct ex_s *ex3 = ex_s_init(2,"john");
	struct ex_s *ex4 = ex_s_init(3,"antrea");
	//
	lifo_push(&lifo,ex1);
	lifo_push(&lifo,ex2);
	lifo_push(&lifo,ex3);
	lifo_push(&lifo,ex4);
	//
	void *ex_v;
	while(!lifo_is_empty(&lifo)){
		ex_v = lifo_pop(&lifo);
		ex_s_print(ex_v);
		ex_s_free(ex_v);
	}
	return 1;
}
