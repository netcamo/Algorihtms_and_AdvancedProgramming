#ifndef MERGE_H_INCLUDED
#define MERGE_H_INCLUDED

void error( void *pt) {

if (pt==NULL) {
    puts("Error Allocating!") ;
    exit(1) ;
}
}


int *allocate_array (int  n) {
int *a ;
a=malloc(n*sizeof(int)) ;
error(a) ;
return a;
}

void print (int* a, int na) {
int i=0 ;
for( i=0 ; i<na; i++) {
    printf("%d ",a[i]) ;

}
puts("\n") ;
return ;
}

int maxx( int a, int b) {
return (a<b ? b : a);
}

int *merge3(int *a ,int *b , int *c , int na, int nb ,int nc) {

    int* d ;
    int nd=na+nb+nc;
    d=allocate_array(nd) ;
    int arr_i[4];
    int i  ;
    for(i=0 ; i<4 ; i++) {
        arr_i[i]=0;
    }

     int m_arr ;
     int m_value ;

    print(a, na) ;
    print(b,nb) ;
    print(c,nc) ;
     for ( i=0 ; i<nd ; i++) {
           m_arr=0;
           m_value=100000 ;

        if(arr_i[0]<na && m_value > a[arr_i[0]] ){
            m_arr=0 ;
            m_value=a[arr_i[0]];

         }
        if(arr_i[1]<nb && m_value >b[arr_i[1]] ){
            m_arr=1 ;
            m_value=b[arr_i[1]];
         }
         if(arr_i[2]<nc && m_value >c[arr_i[2]] ){
            m_arr=2;
            m_value=c[arr_i[2]];
         }

         d[i]=m_value ;
         arr_i[m_arr]++ ;



     }
     print(d,nd) ;

return d ;

}



int* read_array(FILE* in , int na  ) {

int i ;
int *a ;
a=allocate_array(na) ;
for(i=0 ; i<na; i++) {
        fscanf(in,"%d",&a[i] ) ;
    }
    return a ;
}


#endif // MERGE_H_INCLUDED
