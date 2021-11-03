#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int mul( int x, int y) {
   if(y==0 )return 0 ;
   else if(y==1) return x ;
    else return x+mul(x,y-1) ;

}
int catalan( int n) {

if(n==0) return 1;
else {
    int res=0 ;
    int i =0 ;
    for (i ; i<n ; i++) {
        res+=catalan(i)*(catalan(n-1-i)) ;
    }
    return res ;

}

}



int main()
{


int a=3, b=5 ;

printf("%d\n",catalan(1)  ) ;


    return 0;
}
