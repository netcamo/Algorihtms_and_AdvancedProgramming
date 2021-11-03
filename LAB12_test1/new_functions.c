#include "new_functions.h"

void graph_dfs_type  (graph_t* g,  vertex_t* n) {
    int *arr=calloc(4,sizeof(int)) ;
      int currTime=0;
  vertex_t *tmp, *tmp2;

  printf("List of edges:\n");
  currTime = graph_dfs_type_r (g, n, currTime,arr);
  for (tmp=g->g; tmp!=NULL; tmp=tmp->next) {
    if (tmp->color == WHITE) {
      currTime = graph_dfs_type_r (g, tmp, currTime,arr);
    }
  }

  printf("List of vertices:\n");
  for (tmp=g->g; tmp!=NULL; tmp=tmp->next) {
    tmp2 = tmp->pred;
    printf("%2d: %2d/%2d (%d)\n",
      tmp->id, tmp->disc_time, tmp->endp_time,
      (tmp2!=NULL) ? tmp->pred->id : -1);
  }


printf("\n \t Edge Types : \nT: %d\n\nB: %d\n\nF: %d\n\nC: %d\n",arr[0],arr[1],arr[2],arr[3]) ;

}
int graph_dfs_type_r(graph_t *g, vertex_t *n, int currTime,int *arr) {
  edge_t *e;
  vertex_t *tmp;

  n->color = GREY;
  n->disc_time = ++currTime;
  e = n->head;
  while (e != NULL) {
    tmp = e->dst;
    switch (tmp->color) {
      case WHITE: printf("%d -> %d : T\n", n->id, tmp->id);arr[0]++ ; break;
      case GREY : printf("%d -> %d : B\n", n->id, tmp->id); arr[1]++ ;break;
      case BLACK: if (n->disc_time < tmp->disc_time) {
                    printf("%d -> %d : F\n", n->disc_time, tmp->disc_time); arr[2]++;
                  } else {
                    printf("%d -> %d : C\n", n->id, tmp->id);arr[3]++ ;
                  }
    }
    if (tmp->color == WHITE) {
      tmp->pred = n;
      currTime = graph_dfs_type_r (g, tmp, currTime,arr);
    }
    e = e->next;
  }
  n->color = BLACK;
  n->endp_time = ++currTime;

  return currTime;
}
int graph_bfs_count (graph_t *g, vertex_t *n) {
  queue_t *qp;
  vertex_t *d;
  edge_t *e;
  int count =1 ;

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
	count++ ;
      }
      e = e->next;
    }
    n->color = BLACK;
  }
  queue_dispose (qp, NULL);

  return count;
}
int graph_bfs_distance (graph_t *g, vertex_t *n) {
  queue_t *qp;
  vertex_t *d;
  edge_t *e;
  int distance =0 ;

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
	distance=(distance> d->dist ? distance : d->dist) ;
	d->pred = n;
	queue_put (qp, (void *)d);
      }
      e = e->next;
    }
    n->color = BLACK;
  }
  queue_dispose (qp, NULL);

  return distance ;
}
void graph_dfs_depth (graph_t* g ,  vertex_t* n) {

    graph_attribute_init(g) ;
    graph_dfs(g,n) ;


    vertex_t *go=g->g, *goin ;
    int depth=0 ;
    int cur_depth=0 ;
    while(go!=NULL) {
        cur_depth=0 ;
        goin=go ;
        while(goin->pred!=NULL) {
            cur_depth++ ;
            goin=goin->pred;

        }

            depth=(depth<cur_depth ? cur_depth : depth) ;
       // printf("\tid : %d \tdepth : %d\n ",go->id ,cur_depth) ;
        go=go->next;

    }
printf("The depth of DFS tree is :%d \n ",depth) ;

return  ;

}


