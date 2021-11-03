#ifndef BALANCE_H_INCLUDED
#define BALANCE_H_INCLUDED
#include "Merge.h"
#include <math.h>

int *read_balance (int *n) {
int nf=0 ;

    FILE* in=fopen("input_balance.txt" ,"r") ;

    int i;
    float *bal_arr ;
    fscanf(in, "%d",&nf) ;
    bal_arr=malloc(sizeof(float)*nf) ;
    error(bal_arr) ;
    char c;
   // puts("Asd") ;
    for(i=0 ; i<nf; i++) {
        fscanf(in,"%f",&bal_arr[i]) ;
    }
    fclose(in) ;
    *n=nf ;
    puts("Success Reading!") ;
    return bal_arr ;
}

void print_float(float *a , int na) {

int i=0;
for(i=0 ; i<na ; i++) {
    printf("%f ",a[i]) ;
}
puts("" ) ;
}


float find_max_state (float* arr ,int nf) {
float s=0;
float max_state=arr[0] ;
int i ;
for( i=0 ; i<nf ; i++) {
    s+=arr[i] ;
    max_state=(max_state >s ? max_state : s) ;
}
return max_state ;
}
float find_min_state (float* arr, int nf) {
float s=0;
float min_state=arr[0] ;
int i ;
for( i=0 ; i<nf ; i++) {
    s+=arr[i] ;
    min_state=(min_state <s ? min_state : s) ;
}
return min_state ;

}



int solve (float s ,float *cur_arr, float* bal_arr ,int nf , int *used, int k,float *max_state ,float *min_state,float **max_arr) {
    int i ;
    if(k==nf) {
           // print_float(cur_arr,nf) ;
          float curmax_state=find_max_state(cur_arr,nf) ;
          float curmin_state=find_min_state(cur_arr,nf);
            float cur_dif=fabs(curmax_state-curmin_state);
           float max_dif=fabs(*max_state-*min_state) ;
            if(max_dif>cur_dif) {

                *max_state=curmax_state ;
                *min_state=curmin_state ;
                for(i=0; i<nf ; i++) (*max_arr)[i]=cur_arr[i] ;
                print_float(*max_arr ,nf) ;
                printf("%f %f\n" ,*min_state,*max_state) ;
                puts("-----------") ;
                return 1;

            }
    }
    for(i=0 ; i<nf ;i++) {
        if(used[i]==0) {

            used[i]=1 ;
            cur_arr[k]=bal_arr[i] ;
            solve(s+bal_arr[i] ,cur_arr ,bal_arr ,nf ,used,k+1, max_state,min_state,max_arr );
            used[i]=0 ;

        }

    }



    return 1 ;




}




#endif // BALANCE_H_INCLUDED
