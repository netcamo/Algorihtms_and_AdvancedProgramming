#include "h1.h"


void error(void *ptr) {
if(ptr==NULL) {
    puts("allocate error") ;
exit(1);
}
return ;
}

int** create_2d ( int n , int m) {
int** mat ;
 mat=malloc(n*sizeof(int*)) ;
error(mat) ;
int i =0 ,j;
for ( i; i<m ; i++) {
    mat[i]=malloc(m*sizeof(int)) ;
    error(mat[i]) ;
    for (j=0; j<m ; j++) mat[i][j]=-1 ;
}
return mat ;
}


