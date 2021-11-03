
#include "recurse.h"






void err(void *ptr) {
if(ptr==NULL){
    puts("not allocated") ;
}

}



int main()
{

    FILE* in=fopen("in.txt","r") ;

    int i ,j;

    int **truck =malloc(sizeof(int*)*23) ;
    for (i=0 ; i<=20 ; i++  ) {
        truck[i] =malloc(sizeof(int)*33) ;
        err(truck[i]) ;
            }
    for (i=0 ; i<=20 ; i++ ) {
        for (j=0 ; j<=30 ; j++) truck[i][j]=-1 ;
    }
    char s[100] ;
    int parcel_n=0;

    fscanf(in , "%d\n" , &parcel_n ) ;
    parcel_t *parcels =malloc(sizeof(parcel_t)*parcel_n);

    i=0 ;
    while (fgets(s , 1000 ,in )!=NULL) {
        sscanf(s, "%dx%d",&parcels[i].a , &parcels[i].b) ;
        parcels[i].used=0 ;
        parcels[i].id=i ;
        i++ ;
    }
    int x ,y ;
    x=15, y=15 ;

   //printf("\n--------%d--------\n", solve_(truck , x, y, parcel_n ,parcels , 0) ) ;
    //print_truck(truck ,x,y) ;
    int z[5] ={10,10 ,15 ,20,10} ;
    int a[5]={15,20,15,20,15} ;
    for (i=0 ; i<5; i++) {
            x=z[i];
            y=a[i] ;

    printf("\n---%d---\n",solve_(truck ,x,y ,parcel_n,parcels,0)) ;
    print_truck(truck ,x,y) ;
    mark(truck ,1,1,x,y,-1) ;
    for(j=0 ; j<parcel_n ; j++) parcels[j].used=0 ;

     }


    //print_truck(truck , x ,y) ;


    fclose(in) ;
    return 0;
}
