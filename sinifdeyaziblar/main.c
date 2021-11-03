#include  "list.h"
#include "Merge.h"
#include "balance.h"





int main()
{
    {


    #ifdef MERGE
    int *a,*b,*c,na,nb,nc ;
    FILE* in=fopen("input.txt" , "r") ;
    char s[1000] ;
    fgets(s,1000,in) ;
    sscanf(s ,"%d %d %d",&na,&nb,&nc) ;
    a=read_array(in,na) ;
    b=read_array(in,nb) ;
    c=read_array(in,nc) ;
    int* d ;
    d=merge3(a,b,c,na,nb,nc) ;



    free(a) ;
    free(b);
    free(c) ;
    fclose(in) ;

    #endif // MERGE
    }
    {
        #ifdef list_add

        list_t *head=new_list();
        char name[20] ,surname[20] ;
        while (1) {
            scanf("%s %s",surname ,name) ;

           int k=-5;
           k=list_insert_in_order(&head ,surname ,name) ;
                printf("Process ended with k=%d\n\n",k) ;
            print_list(head) ;
        }
        #endif // list_add

    }

    {
        #ifdef  balance


    float* bal_arr;
    int nf=0 ,i;
    bal_arr=read_balance(&nf) ;
    float max_state=find_max_state(bal_arr, nf) ;
    float min_state=find_min_state(bal_arr,nf) ;
    float *cur_arr=malloc(sizeof(float)*nf) ;
    float *max_array=malloc(sizeof(float)*nf) ;
    int *used=malloc(sizeof(int)*nf) ;
    for(i=0; i<nf; i++) {
        used[i]=0 ;
    }
    solve(0,cur_arr ,bal_arr,nf,used,0,&max_state,&min_state,&max_array) ;
    #endif // balance

    }
     return 0;

}
