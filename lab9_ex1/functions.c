#include "H1.h"


int v_x[4]={0,0,1,-1} ;
int v_y[4]={1,-1,0,0} ;

void chechnerror(void* p) {

if(p==NULL) {
    puts("Error allocating!") ;
    exit(1) ;
}
return ;
}

char** alloc2D (int R, int C) {
char** m ;
m=malloc(sizeof(char*)*R) ;
chechnerror(m) ;
int i,j;
for ( i=0 ; i<R ; i++) {
    m[i]=malloc(sizeof(char)*C);
    chechnerror(m[i]) ;
    for (j=0; j<C ;j++) {
        m[i][j]=-1;
    }
}



return m ;




}

char** f_read(int* R ,int* C) {

    FILE* in =fopen("lab_big.txt", "r") ;
    char **maze;
    char s[10000],t[1000] ;
    fgets(s,1000,in) ;

    sscanf(s,"%d %d",R,C) ;
    maze=alloc2D(*R,*C) ;
    int i =0,j ;
    while (fgets(s,1000,in)!=NULL) {

        sscanf(s,"%s/n",t) ;
        for (j=0 ; j<*C; j++) {
            maze[i][j]=s[j] ;
        }
        i++;
    }




    fclose(in) ;

    return maze ;
}

void print_matrix(char** matrix ,int R , int C) {
puts("-------------PRINTING MATRIX!_--------");
    int i ,j ;
    for (i=0 ;i<R ; i++) {
        for (j=0; j<C ;j++) {
            printf("%c",matrix[i][j]);
        }
        puts("") ;
    }
    puts("------------END OF PRINTING!--------") ;
return ;

}

void find_init (char** maze , int R ,int C,int *x ,int *y) {
int i ,j ;
for (i=0 ; i<R; i++) {
    for (j=0; j<C ; j++) {
        if(maze[i][j]=='@') {
            *x=i ;
            *y=j ;
            return ;
        }
    }
}


}


int find_one(char** maze , int R ,int C,int i ,int j ) {
//
          //  print_matrix(maze ,R ,C);

            if(maze[i][j]=='*') return 0;
            else if (maze[i][j]=='#') return 1;

            int ii ,jj ;
            int temp_i , temp_j ;
            for(ii=0 ; ii<4; ii++) {
                    temp_i=i+v_x[ii] ;
                    temp_j=j+v_y[ii] ;
                if(maze[temp_i][temp_j]=='#'){

                        puts("tapdim") ;
                        print_matrix(maze , R, C) ;
                        return 1 ;


                 }

                if(maze[temp_i][temp_j]==' ') {
                    maze[temp_i][temp_j]='!' ;

                    if(find_one(maze,R,C,temp_i,temp_j)==1) return 1 ;
                    maze[temp_i][temp_j]=' ' ;


                }


            }




            return 0 ;


}


int find_all(char** maze , int R ,int C,int i ,int j){

            if(maze[i][j]=='*') return 0;
            else if (maze[i][j]=='#') return 1;
            int ii ,jj ;
            int temp_i , temp_j ;
            for(ii=0 ; ii<4; ii++) {
                    temp_i=i+v_x[ii] ;
                    temp_j=j+v_y[ii] ;
                if(maze[temp_i][temp_j]=='#'){

                        puts("tapdim") ;
                        print_matrix(maze , R, C) ;
                        return 1 ;


                 }

                if(maze[temp_i][temp_j]==' ') {
                        maze[temp_i][temp_j]='!' ;
                        find_all(maze ,R, C ,temp_i , temp_j) ;
                        maze[temp_i][temp_j]=' ' ;


                }


            }




            return 0 ;


}



int find_best(char** maze ,char** maze_best, int R ,int C,int i ,int j, int stepcur, int* stepbest){

            if(maze[i][j]=='*') return 0;
            else if (maze[i][j]=='#') return 1;
            int ii ,jj ;
            int fi,fj ;
            int temp_i , temp_j ;
            for(ii=0 ; ii<4; ii++) {
                    temp_i=i+v_x[ii] ;
                    temp_j=j+v_y[ii] ;
                if(maze[temp_i][temp_j]=='#'){

                           if(stepcur <*stepbest)  {
                            for (fi=0; fi<R; fi++) {
                                for(fj=0 ; fj<C; fj++) {
                                    maze_best[fi][fj]=maze[fi][fj] ;
                                }
                            }
                            *stepbest=stepcur ;
                                puts("new Best") ;
                                print_matrix(maze_best ,R,C) ;
                                printf(" --------- %d ---------\n", *stepbest) ;

                            }


                       // puts("tapdim") ;
                      //  print_matrix(maze , R, C) ;
                        return 1 ;


                 }

                if(maze[temp_i][temp_j]==' ') {
                        maze[temp_i][temp_j]='!' ;
                        find_best(maze ,maze_best ,R, C ,temp_i , temp_j,stepcur+1 ,stepbest) ;
                        maze[temp_i][temp_j]=' ' ;


                }


            }




            return 0 ;


}



