#ifndef RECURSE_H_INCLUDED
#define RECURSE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct parcel_s{
int a ;
int b ;
int used ;
int id ;
}parcel_t;

void  print_truck (int** truck ,int width ,int length) {

puts("\n-----------\n") ;
int i ,j ;
for (i=1; i<=width ; i++) {
    for (j=1 ; j<=length ; j++) {
        printf("%2d",truck[i][j]) ;
    }
    puts("") ;
}
return ;
}

int check (int** truck , int width , int length ,int x, int y ,int a ,int b ) {
        if (x+a-1>width||y+b-1>length) return 0 ;

        int i ,j ;
        for(i=x ;i<=x+a-1 ; i++) {
            for (j=y; j<=y+b-1 ; j++) {
                if (truck[i][j]!=-1)return 0 ;
            }
        }
    return 1 ;
}


void mark (int **truck ,int x , int y, int a, int b , int id ) {

    int i ,j ;
    for (i=x; i<=x+a-1 ; i++) {
        for (j=y; j<=y+b-1 ; j++) {
            truck[i][j]=id ;
        }
    }
return ;
}


int solve_ (int ** truck , int width , int length, int parcel_n , parcel_t* parcels ,int used_parcels) {

    if (used_parcels==parcel_n) {
        return 1 ;

    }

    int i=0 ;
    int x,y ;


    i=used_parcels ;
            for (x=1; x<=width ; x++) {
                for (y=1; y<=length ;y++) {
                   if(truck[x][y]==-1)  {

                         // printf("\n\n---------%d %d %d--------\n\n", i ,x, y) ;
                    if(check(truck ,width ,length,x,y,parcels[i].a,parcels[i].b) ==1) {

                        parcels[i].used=1 ;
                        mark(truck ,x,y,parcels[i].a,parcels[i].b,parcels[i].id) ;
                       // print_truck(truck ,width, length) ;
                       if( solve_(truck,width,length,parcel_n,parcels,used_parcels+1) )return 1 ;
                        mark(truck ,x,y,parcels[i].a , parcels[i].b,-1) ;
                       parcels[i].used=0 ;

                    }
                    if(check(truck ,width ,length,x,y,parcels[i].b,parcels[i].a) ==1) {
                         //   print_truck(truck,15 ,15) ;
                        parcels[i].used=1 ;
                        mark(truck ,x,y,parcels[i].b,parcels[i].a,parcels[i].id) ;
                        //print_truck(truck , width, length) ;
                       if( solve_(truck,width,length,parcel_n,parcels,used_parcels+1) )return 1 ;
                        mark(truck ,x,y,parcels[i].b , parcels[i].a,-1) ;
                       parcels[i].used=0 ;
                       }

                   }

                }
            }






return 0;
}





#endif // RECURSE_H_INCLUDED
