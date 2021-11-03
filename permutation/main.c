#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int permutate  (char* s , int *marker ,int* sol, int level , int *count  ) {
        int n=strlen(s) ;
            int i =0 ;
        if( level>=n) {
            for (i; i<n ; i++) {
                printf("%c",s[sol[i]]);
            }
        puts("") ;
            *count=*count+1 ;

        }

        for(i ; i <n ; i++) {
            if(marker[i]==0) {
                marker[i]=1;
                sol[level]=i ;
                permutate(s, marker,sol, level+1, count) ;
                marker[i]=0 ;
            }
        }


}




int main()
{

    char s[10000] ;
    gets(s) ;


    int n =strlen(s) ;
    int* marker ;
    int *sol ;
    marker=malloc((n+1)*sizeof(int)) ;
    int i =0 ;
    for (i; i<n ; i++) marker[i]=0;
    sol=calloc(n+1, sizeof(int)) ;
    int level=0 ;
    int count= 0 ;
    permutate(s,marker ,sol,level,&count) ;

printf("\n%d\n",count) ;
    return 0;
}
