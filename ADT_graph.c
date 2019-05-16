#include <stdio.h>
#include <stdlib.h>
#include "ADT_list.h"
#include "ADT_graph.h"
#include <stdbool.h>
GRAPH* create_graph(){
	GRAPH* graph = (GRAPH*)malloc(sizeof(GRAPH));
	if(graph == NULL)
		return NULL;

	graph->vertex_list = create_list();	
	return graph;
}

bool	g_insert_vertex(GRAPH* graph, int data){
	VERTEX* new_vertex = (VERTEX*)malloc(sizeof(VERTEX));
	new_vertex->data_ptr = data;
	new_vertex->arc_list = create_list();

	int vertex_loc = find_vertex(graph-> vertex_list, new_vertex);

	if (vertex_loc!= -1)//when there is no input vertex which is good
		return false;

	return add_node_at(
	graph->vertex_list,
	graph->vertex_list->count,//end of it
	new_vertex
	);

}

int find_vertex(LLIST* list, void* search_data){
	list -> pos = list -> front;
	int iter_i = 0;

	while(list->pos != NULL){
		VERTEX* left = (VERTEX*)(list -> pos -> data_ptr);
		VERTEX* right = (VERTEX*) search_data;

		if(left -> data_ptr == right -> data_ptr)
			return iter_i;

		list -> pos = list ->pos ->next;
		iter_i ++;
	}
	return -1;
}
bool g_insert_arc(GRAPH* graph, int from, int to){
	VERTEX temp_vertex1;
	temp_vertex1.data_ptr = from;// using . not ->  since it is local data 
	temp_vertex1.arc_list = NULL;

	int vertex_loc = find_vertex(graph->vertex_list,
	&temp_vertex1//you should use address value since it its temp (local)
);
	if(vertex_loc == -1){
		printf("from_vertex %c : not found\n", (char)from);
		return false;
	}

	VERTEX* from_vertex = (VERTEX*)get_data_at(graph->vertex_list, vertex_loc);
	VERTEX temp_vertex2;
	temp_vertex2.data_ptr = to;// using . not ->  since it is local data 
	temp_vertex2.arc_list = NULL;

	vertex_loc = find_vertex(graph->vertex_list,
	&temp_vertex2);
	if(vertex_loc == -1){
		printf("to_vertex %c : not found\n", (char)to);
		return false;
	}

	VERTEX* to_vertex = (VERTEX*)get_data_at(graph->vertex_list, vertex_loc);
	
	ARC* new_arc = (ARC*)malloc(sizeof(ARC));
	new_arc -> to_vertex = to_vertex;
	
	return add_node_at(
		from_vertex->arc_list,
		from_vertex->arc_list->count,//maumdaero
		new_arc
	);
}

