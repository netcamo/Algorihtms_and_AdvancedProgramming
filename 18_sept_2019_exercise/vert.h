#ifndef VERT_H_INCLUDED
#define VERT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct vertex_u {
    char* name ;
    struct vertex_u *next ;
    int id ;

}vertex_t ;

typedef struct edge_u{
    char* name_src ;
    char* name_dst ;
    struct edge_u* next ;

}edge_t ;

typedef struct graph_u{
   vertex_t *v ;
   edge_t *e ;
   int nv;

}graph_t ;
char * graph_find_id(graph_t* g , int id) {
    vertex_t* v=g->v;
    while(v!=NULL){
            if(id==v->id) return v->name;
        v=v->next;
    }
return "\0" ;
}
vertex_t* graph_find(graph_t* g ,char* name) {
    vertex_t* go=g->v ;
    while(go!=NULL) {

        if(strcmp(go->name,name)==0)return go ;

        go=go->next;
    }

    return NULL ;
}
void add_vertex (graph_t* g,char* name) {
        if(graph_find(g,name)==NULL) {
          vertex_t* v=malloc(sizeof(vertex_t) ) ;
          v->next=g->v ;
          v->id=g->nv;
          v->name=strdup(name) ;
            g->v=v ;
            g->nv++ ;
        }


    return ;
}
void add_edge (graph_t* g , char* src, char* dst) {

    edge_t* edge=malloc(sizeof(edge_t)) ;
    edge->name_dst=strdup(dst) ;
    edge->name_src=strdup(src) ;
    edge->next=g->e ;
    g->e=edge ;
    add_vertex(g,src) ;
    add_vertex(g,dst) ;

    return ;
}
void print_graph (graph_t* g) {
printf("\tVERTICES %d\n",g->nv) ;
    vertex_t *go=g->v;
    while(go!=NULL) {
        printf("%s %d\n",go->name,go->id) ;
        go=go->next;
    }
    puts("\tEdges\n");
    edge_t *goe=g->e;
    while(goe!=NULL) {
        printf("%s %s\n",goe->name_src,goe->name_dst) ;
        goe=goe->next;
    }

}
graph_t* load_file(char* filename) {

    FILE* in =fopen(filename, "r") ;
    graph_t* g =malloc(sizeof(graph_t));
    g->e=NULL ;
    g->v=NULL ;
    g->nv=0 ;

    char s[10000] ;
    char src[1000] ;
    char dst[1000] ;


    while(fgets(s,1000,in)!=NULL) {
        sscanf(s,"%s %s",src,dst) ;
        add_edge(g,src,dst) ;
    }





    fclose(in) ;
    return g ;

}

void arr_init(int *arr ,int n) {
    int i ;
    for(i=0 ; i<n ; i++) {
        arr[i]=-1 ;

    }
return ;
}

int check_solution (graph_t* g , int *arr, int k) {

        edge_t* edgego=g->e;
        int i=0;
        while(edgego!=NULL) {

                int flag=0 ;
               for(i=0 ; i<k ;i++) {
                if(graph_find(g,edgego->name_dst)->id==arr[i] ||graph_find(g,edgego->name_src)->id==arr[i]) flag=1 ;
               }
             if(flag==0) return 0 ;
            edgego=edgego->next;
        }
      return 1 ;

 }


 int solve_r (graph_t* g ,int *arr,int k,int count_, int start) {

        if(count_ == k) {
            if(check_solution(g,arr,k)) {
                int j ;
                for(j=0 ; j<k ; j++) {
                    printf("%s ",graph_find_id(g,arr[j])) ;
                }
                return 1 ;
            }
            else return 0;
            }

        int i ;
        for(i=start ;i<g->nv ; i++) {
            arr[count_]=i ;
           if( solve_r (g ,arr ,k ,count_+1 ,start+1)) return 1 ;
        }

    return 0;

 }





void solve (graph_t* g) {
    int *arr=malloc(sizeof(int)*g->nv) ;

    int i ,j , k ;
    for( i=1 ; i<=g->nv; i++) {
        arr_init(arr,g->nv) ;

         if(   solve_r(g,arr,i,0,0) ) return ;
        //combinatorics recursion

    }





}




#endif // VERT_H_INCLUDED
