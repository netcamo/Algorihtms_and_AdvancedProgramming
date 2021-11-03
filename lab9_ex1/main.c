#include "H1.h"




int main(int argc , char* argv[])
{
    char** maze  ;
    int R,C ;
    int  init_x ,init_y ;
    char** maze_best ;
    maze=f_read(&R,&C) ;

    maze_best=alloc2D(R,C) ;
    puts("Successfull Reading!") ;
    find_init(maze ,R,C,&init_x, &init_y) ;
    //find_one(maze ,R ,C ,init_x, init_y ) ;
    //find_all(maze, R ,C ,init_x , init_y) ;
    int best=100000 ;

    find_best(maze ,maze_best ,R ,C ,init_x,init_y,0,&best) ;




    return 0;
}

