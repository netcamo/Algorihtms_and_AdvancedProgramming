#include <stdio.h>
#include <stdlib.h>

int u (int t) {
if(t<0) return 0 ;
else if (t>0) return 1 ;
else {

    puts("error") ;
    exit(1) ;
 }

}


int f(int k) {

    return u(10-4*k-1)-u(10-4*k-4) ;


}

int main()
{

    int sum=0;
    int i =0 ;
    for ( i = 0 ; i<15; i++) {
        sum+=f(i) ;
    }
    printf("%d",sum) ;
    return 0;
}
