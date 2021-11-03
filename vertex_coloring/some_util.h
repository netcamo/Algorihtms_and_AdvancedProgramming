#ifndef SOME_UTIL_H_INCLUDED
#define SOME_UTIL_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>
#include <string.h>




enum color {WHITE ,GREY , BLACK};

typedef struct vertex_s vertex_t ;
typedef struct edge_s  edge_t ;
typedef struct graph_s graph_t ;

struct edge_s {
int destination_id ;
edge_t *next ;

};
struct graph_s {
    vertex_t* g;
    int nv ;
};
struct vertex_s {
    char* vertex_name;
    int vertex_id ;
    int visited ;
    int color ;
    edge_t* Adj ;
    vertex_t* next;
};

void print_vertex(vertex_t vertex) ;
void print_graph ( graph_t graph);
graph_t* newGraph() ;
vertex_t* newVertex (char *s);
int findCreate_vertex (graph_t* graph,char *s);
void insert_edge (graph_t* graph,int startid ,int destid);
graph_t *load (FILE* in,graph_t* graph);


int check_color (int color ,int id , graph_t* graph);
int check (graph_t* graph) ;
void solve (graph_t* graph) ;
int solve_r (graph_t* graph ,int nv , int *colors,  int maxcolor, int timer);


#endif // SOME_UTIL_H_INCLUDED
