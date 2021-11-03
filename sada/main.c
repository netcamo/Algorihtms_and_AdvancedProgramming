#include <stdio.h>
#include <stdlib.h>
#include <string.h>



char ***board_read(char *namee)
{

    FILE* in = fopen(namee ,"r") ;

    int r ,c;
    char *name=malloc (sizeof(char)*100) ;
    int ki,kj ;
    char *line= malloc(sizeof(char)*100) ;
    char*** board=malloc(r*sizeof(char**)) ;
    fscanf(in , "%d %d\n" , &r,&c) ;

    for(int i =0 ; i<r; i++) {
        board[i]=malloc(sizeof(char*)*c) ;
    }
    for(int i =0 ; i<r ; i++) {
        for(int j =0 ; j<c; j++) board[i][j]=NULL ;
    }

    while (fgets(line,100,in)!=NULL) {
        sscanf(line ,"%d %d %s" , &ki , &kj , name) ;
        board[ki][kj]=malloc(sizeof(char)*100) ;
        strcpy(board[ki][kj],name) ;


    }


    fclose(in) ;
    free(name);
    free(line) ;
    return board ;

}

int main()
{
  setbuf(stdout,0) ;
    char***board= board_read("tmp.txt") ;
    for (int i=0 ; i<5; i++) {
        for (int j=0 ; j<10 ; j++) {
            printf("%s ",board[i][j]) ;

        }
        printf("\n") ;
    }


    return 0;
}

