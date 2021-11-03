#include "graph.h"

int main()
{


    graph_t *g=load_file("cities.txt") ;
    //print_graph(g) ;
    puts("LOADED\n\n");
    solve(g, K) ;




    return 0;
}
