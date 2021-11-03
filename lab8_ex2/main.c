#include "h1.h"




void solve (int **mat ,int  n ) {
    if(n==1) {
        mat[0][0]=0 ;
        mat[0][1]=1 ;
    return ;
    }
    solve (mat ,n-1) ;
     int i,j, jj ;
    int mid=pow(2,n-1) ;
    for (i=0 ; i<n-1 ; i++) {
        for (jj=mid-1,j=mid; jj>=0 ; jj-- , j++) {
            mat[i][j]=mat[i][jj] ;
        }
    }
    for(i=0 ; i<=mid-1 ; i++) {
        mat[n-1][i]=0 ;
        mat[n-1][mid+i]=1;
    }
  //  for ( i=mid;i<=mid*2-1  ;i++) mat[n-1][i]=1 ;

return ;


}


void another_print(int** mat , int n) {

    int i, j ;
    for (j=0 ; j<pow(2,n) ; j++) {

        for ( i=n-1 ; i>=0 ; i--) {
            printf("%d",mat[i][j]);
        }
        puts("") ;
        if (j==pow(2,n-1)-1) puts("-------------") ;

    }


}


int main()
{


   int n ;
   scanf("%d",&n) ;
   int m = pow(2,n);
   int** mat= create_2d  (n,m) ;
   int bits [2] ={0,1} ;

   solve (mat ,n) ;

    another_print(mat, n ) ;
   //print_matrix(mat ,n ,m) ;




    return 0;
}
