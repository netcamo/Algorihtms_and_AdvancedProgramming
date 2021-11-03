#include "some_util.h"
FILE* openfile() {
FILE* in =fopen("in.txt","r") ;
return in ;
}
void print_vertex(vertex_t vertex) {
    printf("%s %d Adj:",vertex.vertex_name,vertex.vertex_id) ;
    edge_t *go ;
    go=vertex.Adj ;
    for(go ;go!=NULL ; go=go->next) {
        printf("%d ",go->destination_id) ;
    }
    printf("-- \t%d %d\n\n",vertex.visited ,vertex.color) ;
}
void print_graph ( graph_t graph) {
    vertex_t* go=graph.g ;
    while(go!=NULL) {

        print_vertex(*go) ;

        go=go->next;
    }

    puts("") ;
}
graph_t* newGraph() {
    graph_t* graph=malloc(sizeof(graph_t)) ;
     graph->g=NULL ;
     graph->nv=0 ;
    return graph ;

}
vertex_t* newVertex (char *s) {



vertex_t *vertex ;
vertex=malloc(sizeof(vertex_t)) ;
vertex->Adj=NULL ;
vertex->color=0 ;
vertex->next=NULL ;
vertex->visited=WHITE ;
vertex->vertex_name=strdup(s) ;

return vertex ;

}
int findCreate_vertex (graph_t* graph,char *s){

    vertex_t* go=graph->g;
    int flag=0 ;
    while(go!=NULL) {
        if(strcmp(s,go->vertex_name)==0) {
            return go->vertex_id ;
        }
        go=go->next;

    }
    vertex_t* newvertex=newVertex(s) ;

    newvertex->vertex_id=graph->nv++ ;
    newvertex->next=graph->g ;
    graph->g=newvertex ;

    return newvertex->vertex_id ;

}
void insert_edge (graph_t* graph,int startid ,int destid) {

    vertex_t* go =graph->g ;
    while (go->vertex_id!=startid) go=go->next;
    edge_t* goedge=go->Adj ;


    edge_t* tmp=malloc(sizeof(edge_t)) ;
    tmp->destination_id=destid ;
    tmp->next=goedge ;
    go->Adj=tmp ;
    return ;

}
graph_t *load (FILE* in,graph_t* graph) {


    char s[10000] ;
    char start[1000] ,dest[1000] ;
    int stid ,destid  ;

    while(fgets(s,10000,in)!=NULL) {

            sscanf(s,"%s %s",start,dest) ;
           // printf("%s %s\n",start ,dest) ;
            stid=findCreate_vertex(graph,start) ;
            destid=findCreate_vertex(graph,dest) ;
            insert_edge(graph, stid, destid);
            insert_edge(graph,destid ,stid) ;
          }

      return graph ;

}



void solve (graph_t* graph) {

    int i =1 ,j ;
    int *colors ;
    colors=malloc(sizeof(int)*graph->nv) ;
    for(j=0 ; j< graph->nv ; j++) colors[j]=0 ;
    for (i=1; i<=graph->nv ; i++) {
            vertex_t* go=graph->g ;
            while(go!=NULL) {
            go->color=colors[go->vertex_id] ;
                go=go->next ;
                }
        for(j=0 ; j< graph->nv ; j++) colors[j]=0 ;
        if(solve_r(graph,graph->nv,colors,i ,0)){
         printf("\nmax color : %d\n ", i) ;
         return ;
        }
    }


}

int solve_r (graph_t* graph ,int nv , int *colors,  int maxcolor, int timer){
          //  printf(" \n ----- TIMER : %d ------\n",timer) ;
        if(timer==nv) {
            if (check(graph)==1)
            {   puts("cavab tapdi") ;
                print_graph(*graph) ;
                return 1 ;
            }
            else {
                return 0 ;
            }
        }
         int i , j ;
       for(i=0 ; i<nv; i++) {

            if(colors[i]==0) {

                for (j=1; j<=maxcolor; j++) {
                    colors[i]=j ;

                                vertex_t* go=graph->g ;
                                while(go!=NULL) {
                                    go->color=colors[go->vertex_id] ;
                                    go=go->next ;
                                }


                    if(check(graph)==0) {
                        colors[i]=0 ;

                         vertex_t* go=graph->g ;
                                while(go!=NULL) {
                                    go->color=colors[go->vertex_id] ;
                                    go=go->next;
                                }

                    }
                    else
                        if(solve_r(graph,nv,colors,maxcolor,timer+1)) return 1 ;
                }

            }



       }

        return 0 ;


}




int check_color (int color ,int id , graph_t* graph){
    vertex_t* go =graph->g ;
    while(go!=NULL) {
            if(go->vertex_id==id) {
            if (color== 0 || go->color == 0) return -1 ;
            if(color==go->color)return 1 ;
            else return 0;
        }


        go=go->next ;

    }


}


int check (graph_t* graph) {

    vertex_t* go=graph->g ;
    while (go!=NULL) {
    int color=go->color ;

    edge_t* edgego=go->Adj ;
    while(edgego!=NULL) {
         int neighborId=edgego->destination_id ;
          if(check_color(color,neighborId,graph)==1) {
            return 0 ;
          }



        edgego=edgego->next;
    }

    go=go->next ;
    }
return 1 ;

}



