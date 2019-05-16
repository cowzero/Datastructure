#include <stdio.h>
#include <stdlib.h>
#include "ADT_stack.h"

STACK* create_stack() {
	printf("creating a stack ... \n");
	STACK* stack = (STACK*)malloc(sizeof(STACK));
	if( !stack )
		return 0;
// when there is no place to allow, return 0 whick means null
	stack ->count = 0;
	stack ->top = 0;
	return stack;
}
	
int push(STACK* stack, void* in) {
	printf("creating a stack ... \n");
	STACK_NODE* node = (STACK_NODE*)malloc(sizeof(STACK_NODE));
	if( !node)
		return 0;

	node ->data_ptr = in;
	node ->link = stack ->top; // my net become old boss;
	stack ->top = node; // I am a new boss
	stack ->count++;

	return 1;
}

void* pop(STACK* stack) {
	if(stack->count==0)
	return 0;
	else{
	STACK_NODE* temp = stack->top;
	void*  data_out = stack->top->data_ptr;
	stack->top = stack->top->link;
	free(temp);
	stack ->count--;
	return data_out;
	}
}
