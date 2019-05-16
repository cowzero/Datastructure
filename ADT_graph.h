#ifndef _GRAPH_H_
#define _GRAPH_H_
#include <stdio.h>
#include "ADT_list.h"
#include <stdbool.h>
typedef struct{
	LLIST* vertex_list;
}GRAPH;

typedef struct vertex{
	int data_ptr;
	LLIST* arc_list;
}VERTEX;

typedef struct{
	struct vertex* to_vertex;
}ARC;
GRAPH* create_graph();
bool	g_insert_vertex(GRAPH* graph, int data);
int 	find_vertex(LLIST* list, void* search_data);
bool	g_insert_arc(GRAPH* graph, int from, int to);
#endif
