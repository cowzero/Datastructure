#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
	void* data_ptr;
	struct node* next;
} QUEUE_NODE;
typedef struct{
	int count;
	QUEUE_NODE* front;
	QUEUE_NODE* rear;	
} QUEUE;

QUEUE* create_queue();// just sun eon here, make function's body in .c
bool enqueue (QUEUE* queue, void* in); // pointer is light so we use *
void* dequeue (QUEUE* queue); // return void pointer since we delete it.
