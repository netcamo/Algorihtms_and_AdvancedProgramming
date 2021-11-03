#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int matrix[102];
int matrixv[102] ;


int main()
{
    FILE* fi=fopen("input","r") ;
    if(fi==NULL) {
            exit(0) ;
    }
    char s[102] ;

    int hor=0 ;
    int ver=0 ;
    int i , j ;

    while (fgets(s, 102 , fi)!=NULL){
        for (i=0 ; i<102 ; i++)matrix[i]=0 ;
        for (i=0 ; i<strlen(s) ; i++) {
            if (s[i]=='h') matrix[i+1]=matrix[i]+1 ;
            if (matrix [i]>=5)hor++ ;

            if (s[i]=='v') {
                matrixv[i]++ ;
                if (matrixv[i]>=5)ver++ ;
            }
            else matrixv[i] =0 ;


        }



    }





    printf("%d  %d" , hor , ver) ;


    fclose(fi) ;




    return 0;
}
