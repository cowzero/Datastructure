#include "ADT_list.h"

LLIST* create_list(){
	LLIST* list;
	list = (LLIST*)malloc(sizeof(LLIST));
	if(list){
	list -> count = 0;
	list -> front = NULL;
	list -> rear = NULL;
	list -> pos = NULL;
	}
	return list;

}
bool add_node_at(LLIST* list, unsigned int index, void* data){
	if(index>(list->count))	return false;
	NODE* add_node;
	add_node = (NODE*)malloc(sizeof(NODE*));
	if(!add_node) return false;
	add_node -> data_ptr = data;
	add_node -> next = NULL;//maiking a node to add
	if(list->count ==0){
	list -> front = add_node;
	list -> rear = add_node;
	(list->count) ++;
	return true;
	}
	int i = 0;
	if(index ==0){
	add_node ->next = list -> front;
	list -> front = add_node;
	(list->count)++;
	return true;
	}// when adding a node in front of the list 
	i ++;
	list -> pos = list -> front;
	while(i !=index){
	list -> pos = list -> pos ->next;
	i ++;
	}// moving pos node to find index to add node
	if(i == list->count){
	list -> pos -> next = add_node;
	list ->rear = add_node;
	(list->count) ++;
	return true;
	}// when index number i is list's count (which means the last node)
	else {
	add_node -> next =list -> pos -> next;
	list -> pos -> next = add_node;
	(list -> count)++;
	return true;
	}// when index number i is in the middle of count number and 0

	return false;
}
bool del_node_at(LLIST* list, unsigned int index){
	if(list->count == 0) return false;
	else if(index >= list->count) return false;
	if(list->count ==1) {
	free(list->front);
	list -> front = NULL;
	list -> rear = NULL ;
	list -> count = 0;
	return true;
	}
	int i = 0;
	list -> pos = list -> front;
	NODE* pre = NULL;
	while( i !=index){
	pre = list -> pos;
	list -> pos = list -> pos -> next;
	i++;
	}
	if(index==0){
	list -> front = list -> pos -> next;
	free(list ->pos);
	list -> pos = NULL;
	(list -> count)--;
	}
	if(index ==(list->count-1)){
	list -> rear = pre;//before remove node should think the node's purpose, it is rear, so should redefine rear
	pre -> next = NULL;// after redefine rear, should left it's next value is null
	free(list -> pos);//now, you can remove the node's value
	list -> pos = NULL;//after remove the value, should remove it's address value
	(list->count)--;// always think about list's total members.
	return true;
	}	
	else {
	pre -> next = list -> pos-> next;
	free(list->pos);
	list ->pos = NULL;
	(list->count)--;
	return true;
	}
}

void* get_data_at(LLIST* list, unsigned int index){
	if(list->count == 0) return false;
	else if(index >= list->count) return false;
	void* hook;
	int i = 1;
	list -> pos = list -> front;
	while( i !=index){
	list -> pos = list -> pos -> next;
	i++;
	}
	hook = list-> pos -> data_ptr ;
	return hook;
}
