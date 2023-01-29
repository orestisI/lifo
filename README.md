# lifo
lifo(last in first out)

## API
```C
//Initialize lifo
void lifo_init(struct lifo_s *lifo);
//Push data
int lifo_push(struct lifo_s *lifo,void *data);
//Pop data
void *lifo_pop(struct lifo_s *lifo);
//Check if lifo is empty
int lifo_is_empty(struct lifo_s *lifo);
//Free lifo
void lifo_free(struct lifo_s *lifo);
//Free lifo + data
void lifo_freee(struct lifo_s *lifo,void (*free_data)(void *));

```

