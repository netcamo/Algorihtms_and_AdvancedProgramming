#ifndef NEW_FUNCTIONS_H_INCLUDED
#define NEW_FUNCTIONS_H_INCLUDED

#include  "graph.h"
#include "queuePublic.h"



int graph_bfs_count (graph_t *, vertex_t *);
int graph_bfs_distance    (graph_t* ,vertex_t*) ;
void graph_dfs_type  (graph_t* ,  vertex_t*) ;
int graph_dfs_type_r(graph_t *g, vertex_t *n, int currTime, int *arr) ;
void graph_dfs_depth (graph_t* ,  vertex_t*) ;



#endif // NEW_FUNCTIONS_H_INCLUDED
