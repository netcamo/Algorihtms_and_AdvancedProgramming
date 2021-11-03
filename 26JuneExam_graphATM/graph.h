#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <String.h>
enum colors {WHITE , GREY ,BLACK};

#define K 2
#define INF 100000
void print_array(int *arr , int n) {
int i ;
for(i=0 ; i<n ; i++) printf("%d ",arr[i]);
puts("");
 }
typedef struct edge_u{

    struct vertex_u* dest ;
    int weight ;
    struct edge_u* next;

}edge_t;

typedef struct vertex_u{

    int ATM_placed ;
    struct vertex_u *next ;
    edge_t* head ;
    char* name ;
    int id ;
    int color;
    int min_distance_fromATM ;




}vertex_t ;


typedef struct graph_u {
    vertex_t *vertex ;
    int nv ;


}graph_t ;


void print_graph (graph_t* g) {

    vertex_t* v=g->vertex ;
        printf("\t Vertices : %d \n",g->nv) ;
     while(v!=NULL) {
        printf("\t%s %d \ncolor: %d\nmin_distance: %d\nATM_placed %d\n",v->name,v->id,v->color,v->min_distance_fromATM,v->ATM_placed);
        edge_t* go=v->head;
        puts("\tEDGES\n");
        while(go!=NULL){
               printf("%s %d\n",go->dest->name,go->weight) ;
            go=go->next;
        }
            puts("") ;
        v=v->next;
     }
        return ;

}

 vertex_t* graph_find (graph_t* g , char *src) {

    vertex_t *go=g->vertex;
    while(go!=NULL) {
            if(strcmp(go->name,src)==0)return go ;
        go=go->next;
    }
 return go ;
 }

 vertex_t *add_node (graph_t* g, char *name){

     vertex_t  *src;
    src=graph_find(g,name) ;

    if(src==NULL) {
        vertex_t* v=malloc(sizeof(vertex_t)) ;
        v->ATM_placed=0;
        v->color=WHITE ;
        v->head=NULL ;
        v->id=g->nv++ ;
        v->min_distance_fromATM=INF ;
        v->next=NULL;
        v->name=strdup(name) ;
        v->next=g->vertex;
        g->vertex=v ;
        src=v ;
        }
    return src;
    }

void add_edge (graph_t* g ,char *from , char *to , int weight) {

   vertex_t *src,*dst ;

    src=add_node (g,from );
    dst=add_node (g,to) ;
    edge_t* edge=malloc(sizeof(edge_t)) ;
    edge->next=src->head;
    src->head=edge;
    edge->weight=weight;
    edge->dest=dst ;



    return ;
}

graph_t* load_file(char* filename) {


    FILE *in=fopen(filename ,"r") ;
    graph_t *g =malloc(sizeof(graph_t)) ;
    g->nv=0;
    g->vertex=NULL;
    char from[3000] ,to[3000] ;
    int weight ;

    char s[2000] ;
    while(fgets(s,2000,in)!=NULL) {

        sscanf(s,"%s %s %d",from ,to ,&weight) ;
        //printf("%s %s %d",from,to,weight) ;
        add_edge(g, from ,to ,weight) ;
        add_edge(g,to,from,weight) ;

    }
return g ;

}

void graph_attribute(graph_t* g) {
    vertex_t* go=g->vertex;
    while(go!=NULL) {
        go->ATM_placed=0;
        go->color=WHITE ;
        go->min_distance_fromATM=INF ;


        go=go->next;
    }

}

void num_to_bin_to_arr(int num , int* arr,int nv) {
    int i;
    for(i=0 ; i<nv; i++) arr[i]=0 ;
    int j=0 ;
    for (i=1 ; i<2<<(nv-1); i*=2) {
            //printf("%d %d\n",j,i) ;
        if(num & i) arr[j]=1 ;

        //printf("%d ",arr[j]) ;
        j++ ;
    }
    //puts("numtobinde\n") ;
    //print_array(arr, nv) ;
   // puts("") ;
    return ;

}


int check_array (int *arr ,int nv , int atm_number) {
    int i;

    for(i=0 ; i<nv ; i++) {
        atm_number-=arr[i] ;
    }
    if(atm_number==0){return 1 ; }
    else return 0;

}
int maxx(int a, int b){
return (a>b)? a : b;}


void relax (graph_t* g ,vertex_t* v) {
   // puts("ADA") ;
    if(v==NULL) return ;

    edge_t* e=v->head ;

    while(e!=NULL) {

        if(e->dest->min_distance_fromATM > e->weight +v->min_distance_fromATM){
           e->dest->min_distance_fromATM = e->weight +v->min_distance_fromATM;
           relax(g,e->dest) ;
        }
        e=e->next;
     }


}


void sssp (graph_t* g) {


        vertex_t* v=g->vertex;
        while(v->ATM_placed==0)v=v->next;
        relax(g,v) ;
        v=g->vertex;
        while(v!=NULL) {
           relax(g,v) ;
            v=v->next;
        }
        //relax v and then relax all of grap

}


int check_max_distance (graph_t* g, int *arr) {

        //print_array(arr,K) ;
    vertex_t* v=g->vertex ;
    while(v!=NULL) {
        v->ATM_placed=arr[v->id] ;
        if(v->ATM_placed)v->min_distance_fromATM=0;
        v=v->next;
    }

    // relaxation zad
   // puts("here") ;
    sssp(g) ;
    //puts("\t--------") ;
    //print_array(arr,g->nv) ;
   // print_graph(g) ;
   // puts("\t------");
   // exit(1) ;
    //realxaasda



    int max_distance=0 ;
    v=g->vertex ;
    while(v!=NULL) {
    max_distance=maxx(max_distance,v->min_distance_fromATM);
   v=v->next; }
   return max_distance ;

}


void solve (graph_t* g , int ATM_number) {
        int i,j ;
        int nv=g->nv;
        int *vertices_with_ATM =malloc(sizeof(int)*g->nv) ;
        for(i=0 ; i<nv;i++)vertices_with_ATM[i]=0 ;

        int best_sl_case=-1;
        int best_sl_max_dst=INF ;

        for(i=0 ; i<2<<(nv-1) ; i++){
            num_to_bin_to_arr(i,vertices_with_ATM,nv) ;
            graph_attribute(g) ;
            //printf("%d ",i) ;

            if(check_array(vertices_with_ATM,nv,ATM_number)){

                    int distance =check_max_distance(g,vertices_with_ATM) ;

                    if(best_sl_case==-1|| best_sl_max_dst> distance) {
                        best_sl_case=i ;
                        best_sl_max_dst=distance;
                    }

            }


        }
            puts("\t\tFOUND ONE\n\n") ;
            //    printf("\n\n\t\t%d %d\n\n ",best_sl_case,best_sl_max_dst) ;
        graph_attribute(g) ;
       // //puts("ARRAY IS") ;
        //print_array(vertices_with_ATM,4) ;

        num_to_bin_to_arr(best_sl_case,vertices_with_ATM,nv) ;
       // puts("ARRAY IS") ;
        //print_array(vertices_with_ATM,4) ;
        int result=check_max_distance(g,vertices_with_ATM) ;
        printf("RESULT IS %d",result) ;
        print_graph(g) ;
        //print the solution ;



}




#endif // GRAPH_H_INCLUDED
