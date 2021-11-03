#include <stdio.h>
#include <stdlib.h>


int h1(int k ) {
return k%21 ;
}
int h2 (int k ) {
return 1 +k%20 ;}


int main()
{
    char c;

    int k ;
    while (1) {
        int  choice ;
         scanf("%d", &choice);

      if (choice ==0) {
        scanf("%c",&c);
        k=c-'A'+1 ;
      }
      else if(choice ==1) {
        printf("%d\n",h1(k)) ;
      }
      else if (choice ==2) {
        printf("%d\n" ,h2(k)) ;
      }
    }




    return 0;
}
