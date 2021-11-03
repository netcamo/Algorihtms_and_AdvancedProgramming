#include <stdio.h>
#include <stdlib.h>

int check (int used[]) {


int i ;
for (i=0 ; i<5; i++) {
    if(!used[i]) return 0 ;
}
return 1;


}

int solve ( char char_array[] ,int n , int used[] ,char *word , int time ) {

    if (time ==n) {
       if( check(used) ) {
            word[n]='\0' ;
        printf("%s\n",word ) ;
       return 1 ;
       }
       return 0 ;
    }

    int i =0;
    for (i=0 ; i<5; i++) {
        word[time]=char_array[i] ;
        used[i]++ ;
        solve(char_array,n,used,word,time+1) ;
        used[i]--;

    }


return ;

}





int main()
{


    char char_array[5]="AEIOU" ;
    int n=7 ;
    char *word=malloc(sizeof(char)*(n+1)) ;
    int used[5] ={0,0,0,0,0} ;
    int time=0 ;
    solve(char_array,n,used,word,time ) ;








    return 0;
}
