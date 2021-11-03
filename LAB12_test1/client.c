#include <stdio.h>
#include "queuePublic.h"
#include "graph.h"
#include "new_functions.h"


/* function prototypes */
void graph_bfs (graph_t *, vertex_t *);
void graph_dfs (graph_t *, vertex_t *);
int graph_dfs_r (graph_t *, vertex_t *, int);

void graph_verteces_print(graph_t* g ) {

    printf("\n\n\nPrinting  All information about vertices:\n\n\n") ;

    vertex_t *go ;
    go=g->g ;

    while(go!=NULL) {

        printf("\n\tid: %d\n\tcolor: %d\n\tdist: %d\n\tdisc_time: %d\n\tendp_time: %d\n\tscc: %d\n",
               go->id,go->color ,go->dist, go->disc_time, go->endp_time, go->scc);
        printf("\tedges: ")  ;
        edge_t* edge_go ;
        edge_go=go->head ;
        while (edge_go!=NULL) {

                printf("%d ",edge_go->dst->id) ;
            edge_go=edge_go->next ;
        }
        printf("\n") ;
        go=go->next ;

    }

}



void graph_dfs_r_max_path (graph_t *g, vertex_t *n, int currTime) {
  edge_t *e;
  vertex_t *tmp;

  n->color = GREY;
  if (currTime <= n->disc_time)
    return;

  n->disc_time = currTime;
  e = n->head;
  while (e != NULL) {
    currTime = n->disc_time + e->weight;
    tmp = e->dst;
    if (tmp->color == WHITE) {
      graph_dfs_r_max_path (g, tmp, currTime);
    }
    e = e->next;
  }
  n->color = WHITE;

  return;
}


/*
 *  main program
 */
int main (int argc, char *argv[]) {
  graph_t *g;
  vertex_t *src, *n;
  int i;

  util_check_m(argc>=2, "missing parameter.");
  g = graph_load (argv[1]);

  printf("Initial vertex? : 0\n");
  //scanf("%d", &i);
    i=0 ;



  printf ("Incoming/Outgoing Edges\n");
  src = graph_find (g, i);

  /* DFS */

  printf ("\nDFS\n");

  // Redundant after load
  graph_attribute_init (g);
  //graph_dfs (g, src);

  /* BFS */
    puts("") ;
  printf ("BFS\n");
  graph_attribute_init (g);
  //graph_bfs (g, src);

  /* print reachable nodes with info */
  n = g->g;
  printf("List of vertices:\n");
  while (n != NULL) {
    if (n->color != WHITE) {
      printf("%2d: [%d] (%d)\n", n->id, n->dist, n->pred ? n->pred->id : -1);
    }
    n = n->next;
  }



  puts("\n\n\n ------------ NOW THE GAME STARTS ----------- \n\n\n") ;
    graph_attribute_init (g);
   { // BFS VISITED COUNT
    // int bfs_count=graph_bfs_count(g, graph_find(g,i)) ;
   // printf("BFS visited count : %d \n ",bfs_count) ;
   }


   graph_attribute_init (g);
     {  //BFS DISTANCE
        // int bfs_distance=graph_bfs_distance(g,src) ;
        // printf("bfs_distance : %d\n" ,bfs_distance) ;
     }

    graph_attribute_init (g);
    {// DFS EDGE TYPES

        //graph_dfs_type(g,src) ;

    }

   {    //DFS DEPTH


    //graph_attribute_init (g);
    //graph_dfs(g, src) ;
    //graph_verteces_print(g) ;
   // graph_dfs_depth(g, src) ;
   }



    graph_dfs_r_max_path(g,graph_find(g,0),0) ;

    vertex_t *go =g->g ;
    while (go!=NULL) {
        printf("node_id : %d   -- maxpath  %d \n",go->id , go->disc_time) ;
        go=go->next ;
    }




  graph_dispose (g);

  return EXIT_SUCCESS;
}







/*
 *  perform BFS from vertex n
 */
void graph_bfs (graph_t *g, vertex_t *n) {
  queue_t *qp;
  vertex_t *d;
  edge_t *e;

  qp = queue_init (g->nv);
  n->color = GREY;
  n->dist = 0;
  n->pred = NULL;
  queue_put (qp, (void *)n);

  while (!queue_empty_m (qp)) {
    queue_get (qp, (void **)&n);
    e = n->head;
    while (e != NULL) {
      d = e->dst;
      if (d->color == WHITE) {
	d->color = GREY;
	d->dist = n->dist + 1;
	d->pred = n;
	queue_put (qp, (void *)d);
      }
      e = e->next;
    }
    n->color = BLACK;
  }
  queue_dispose (qp, NULL);

  return;
}

/*
 *  perform DFS from vertex i
 */
void graph_dfs (graph_t *g, vertex_t *n) {
  int currTime=0;
  vertex_t *tmp, *tmp2;

  printf("List of edges:\n");
  currTime = graph_dfs_r (g, n, currTime);
  for (tmp=g->g; tmp!=NULL; tmp=tmp->next) {
    if (tmp->color == WHITE) {
      currTime = graph_dfs_r (g, tmp, currTime);
    }
  }

  printf("List of vertices:\n");
  for (tmp=g->g; tmp!=NULL; tmp=tmp->next) {
    tmp2 = tmp->pred;
    printf("%2d: %2d/%2d (%d)\n",
      tmp->id, tmp->disc_time, tmp->endp_time,
      (tmp2!=NULL) ? tmp->pred->id : -1);
  }
}

/*
 *  perform recursive DFS from vertex i:
 *  labels nodes with td/tq, edges as T/F/B/C
 */
int graph_dfs_r(graph_t *g, vertex_t *n, int currTime) {
  edge_t *e;
  vertex_t *tmp;

  n->color = GREY;
  n->disc_time = ++currTime;
  e = n->head;
  while (e != NULL) {
    tmp = e->dst;
    switch (tmp->color) {
      case WHITE: printf("%d -> %d : T\n", n->id, tmp->id); break;
      case GREY : printf("%d -> %d : B\n", n->id, tmp->id); break;
      case BLACK: if (n->disc_time < tmp->disc_time) {
                    printf("%d -> %d : F\n", n->disc_time, tmp->disc_time);
                  } else {
                    printf("%d -> %d : C\n", n->id, tmp->id);
                  }
    }
    if (tmp->color == WHITE) {
      tmp->pred = n;
      currTime = graph_dfs_r (g, tmp, currTime);
    }
    e = e->next;
  }
  n->color = BLACK;
  n->endp_time = ++currTime;

  return currTime;
}
