#include "ADT_queue.h"// seperate headder is very useable.

QUEUE* create_queue(){
	QUEUE* queue;
	queue =(QUEUE*) malloc(sizeof(QUEUE));// inside of sizeof you must not use variable
	if(queue){
		queue->front = NULL;
		queue->rear = NULL;
		queue->count = 0;
		return queue; 
	} else {
		return NULL;
	}
}

bool 
enqueue (
	QUEUE* queue, // target queue
	 void* in	//data
){
	QUEUE_NODE* new_node;
	new_node = (QUEUE_NODE*) malloc(sizeof(QUEUE_NODE));
	new_node -> data_ptr = in;
	new_node -> next = NULL;
	
	if(queue->count==0){
		queue->front = new_node;
	}

	else {
		queue->rear->next = new_node;
	}
	queue->rear = new_node;
	queue->count++;
	return true;
	
}
void* dequeue(QUEUE* queue){
	if(queue->count==0) 
	return NULL;
	QUEUE_NODE* byebye_node;
	void* output = queue->front->data_ptr;
	byebye_node = queue->front;
	
	if(queue->count==1){
	queue->front = NULL;
	queue->rear = NULL;
	}else{
	queue->front = queue->front->next;
	}
	free(byebye_node);
	(queue->count)--;
	return output;
	}

