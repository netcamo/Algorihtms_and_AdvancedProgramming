#include <stdio.h>
#include <stdlib.h>



void destroy (int** mat , int * array, int n)  {
free(array) ;
int i =0 ;
for(i=0 ; i<n ; i++) {
    free(mat[i]) ;
}

free(mat) ;

}


void error() {

puts("Error") ;
exit(1) ;

}

int* create_array ( int n) {
        int i =0 ;
        int *ava_n ;
        ava_n=malloc(n*n*(sizeof(int))) ;
        if (ava_n == NULL) {
            puts("Error") ;
            exit(1) ;

        }
        for( i =1 ; i<=n*n ; i++) {
            ava_n[i-1]=i;
        }
return ava_n ;
}


 int** create_matrix ( int n ) {

    int **mat ;
        int i =0 ;
        mat=malloc((sizeof(int*)*n)) ;
        if (mat==NULL) error() ;
        for( i=0 ; i<n; i++)  {
            mat[i]=malloc(sizeof(int)*n) ;
            if (mat[i]==NULL) error() ;

        }
        int j =0 ;

        for ( i=0 ;i < n ; i++) {
            for ( j=0; j<n ;j++) {
                mat[i][j]=0 ;
            }
        }
 return mat ;
 }


int check_rows ( int ** mat, int n , int R, int C) {
    int target = n*(n*n+1)/2 ;
    int sum=0;
    int  i ;

    for (i=0 ; i<=C ; i++) {
        sum+=mat[R][i] ;
    }
    if (C<n-1 ) {
        if(sum>target) return 0 ;
    }
    else if (sum!=target)return 0 ;

   sum=0 ;
   for ( i=0 ; i<=R ; i++) {
     sum+=mat[i][C] ;
   }
   if (R<n-1) {
    if(sum>target)return 0;
   }
   else {
    if (sum!=target) return 0 ;
   }
return 1 ;

}

 int check_solution ( int**  mat, int n) {
        int sum_check =0 ;
        int i =0 ;
        int j =0 ;


        int sum=0 ;
        for ( i=0 ; i< n ; i++) {
            sum_check+=mat[0][i] ;
        }


        for ( i =0 ; i < n ; i++  ) {
            sum=0 ;
            for (j =0 ; j<n; j++) {
                sum+=mat[i][j] ;
            }
            if ( sum !=sum_check) return 0 ;
        }


        for ( i =0 ; i < n ; i++  ) {
            sum=0 ;
            for (j =0 ; j<n; j++) {
                sum+=mat[j][i] ;
            }
            if ( sum !=sum_check) return 0 ;
        }


        sum=0 ;
        for (i = 0 ; i<n ; i++ ) {
            sum+=mat[i][i] ;
        }
            if (sum!=sum_check) return 0 ;


        sum=0 ;
        for (i=n-1 ,j=0 ;  i>=0 && j<n ; i-- ,j++) {
            sum+=mat[i][j] ;
        }

        if ( sum!=sum_check) return 0 ;


         return 1 ;

    }


void solve ( int** mat , int* arr , int n ,int k,int *flag) {
            int i =0,j =0 ;
            int R,C  ;
            R=k/n ;
            C=k%n ;

        if ( k == n*n ) {
            if ( check_solution(mat , n)==1) {
                 //  puts("asda") ;
                   print(mat,n);
                    *flag=1 ;
                    return ;
                }

                }


    for ( i=0 ; i<n*n; i++) {
        if (arr[i]!=0)
        {
            mat[R][C]=arr[i] ;
             if (check_rows(mat , n ,R,C)==0) {
                continue ;
            }
          //  printf("%d\n\n",arr[i]) ;
            arr[i]=0;

            solve(mat,arr,n,k+1,flag ) ;

            if(*flag==0) arr[i]=i+1 ;

        }


    }


}


void write (char *filename , int **mat , int n)  {
FILE* in =fopen (filename, "w");
int i =0 ,j=0;
for ( i=0 ; i<n ; i++) {
    for( j=0; j<n ; j++) {
        fprintf(in , "%3d ",mat[i][j] ) ;
    }
fputs("\n",in) ;
}
fclose(in) ;
}


void print(int** mat, int n ) {
int i ,j ;
for ( i=0 ; i<n; i++) {
    for ( j=0 ; j<n ; j++) {
        printf("%d ",mat[i][j]) ;
    }
    puts("") ;
}
puts("------\n------\n\n") ;
return;
}
int main(int argc , char* argv[])
{
        int j=0,i=0,n=atoi(argv[1]) ;
        int *ava_n=create_array(n) ;
        int **mat=create_matrix(n) ;
        int flag =0;
        solve(mat, ava_n, n ,0,&flag) ;
        //write(argv[2],mat,n) ;
        //print(mat,n) ;


        destroy(mat,ava_n,n) ;
       return 0;
}
