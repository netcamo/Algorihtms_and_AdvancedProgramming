#include <stdio.h>
#include <stdlib.h>

void mall(int ***z) {
    int i ;
   int** a ;
    a=malloc(5*sizeof(int *)) ;
    if (a==NULL) {
        puts("error") ;
        exit(1) ;
    }
    for (i=0 ; i<5; i ++) {
        a[i]=malloc(5*sizeof(int)) ;
        if (a[i]==NULL) {
            puts("error") ;
            exit(1) ;
        }
    }
    a[3][3]=2 ;
    *z=a ;

return ;
}


int main()
{

    int **m  ;


    mall(&m) ;
    if (m==NULL) {
        puts("NUll") ;
        exit(1) ;
    }
    printf("%d",m[3][3]) ;





    return 0;
}
