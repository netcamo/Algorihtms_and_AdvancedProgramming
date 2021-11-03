
#include "some_util.h"


int main()
{

    FILE* in =openfile() ;

    graph_t *graph ;
    graph=newGraph() ;
    graph=load(in,graph) ;
    //print_graph(*graph) ;

    solve(graph) ;
   // print_graph(*graph) ;

    fclose (in) ;
    return 0;
}
