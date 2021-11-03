
#include "vert.h"



int main()
{


   graph_t* g=load_file("in.txt" );
    print_graph(g) ;
    puts("\n\n\n");
    solve (g) ;




    return 0;
}
