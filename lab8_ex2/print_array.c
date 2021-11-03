void print_matrix ( int **mat ,int n ,int m) {
 int i =0;
 int j ;
 for ( i=0; i<n ; i++) {
    for ( j=0; j<m; j++) {
        printf("%d ",mat[i][j]) ;
    }
    puts("") ;

 }
 return ;
}
