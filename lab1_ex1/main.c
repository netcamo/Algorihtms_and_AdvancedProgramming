#include <stdio.h>
#include <stdlib.h>
#define MAX 100
void readDim (int* r, int* c) ;
int checkDim (int r1, int c1 , int r2 , int c2) ;
void readMatrix (float mat[][MAX], int r ,int c) ;
void computeProduct(float mat1[][MAX], int r1, int c1,
                       float mat2[][MAX], int r2, int c2,
                       float mat3[][MAX], int* r3, int* c3);
void writeMatrix(float mat1[][MAX], int r1, int c1,
                       float mat2[][MAX], int r2, int c2,
                       float mat3[][MAX], int r3, int c3);

int main()
{

 int r1,r2,c1,c2,r3,c3,i,j ;
 readDim( &r1, &c1) ;
 //printf("%d %d",r1,c1) ;
 readDim(&r2, &c2 ) ;
 float mat1[MAX][MAX], mat2[MAX][MAX],mat3[MAX][MAX]   ;

 if (checkDim(r1, c1,r2,c2)) {


                readMatrix (mat1, r1, c1) ;
                readMatrix (mat2, r2, c2) ;

                computeProduct(mat1, r1,c1,mat2,r2,c2,mat3,&r3,&c3) ;
                writeMatrix(mat1,r1,c1,mat2,r2,c2,mat3,r3,c3) ;


 }

 else {puts("Dimensions are not right!");exit(0) ;}






    return 0;
}

void readDim (int* r, int* c) {
    scanf("%d %d",r ,c ) ;
}
int checkDim (int r1, int c1 , int r2 , int c2)  {
    if (r1>MAX || c1>MAX || r2>MAX || c2>MAX || c1!=r2 || (r1<0||r2<0||c1<0||c2<0)) {return 0 ;}
    else return 1 ;

}
void readMatrix (float mat[][MAX], int r ,int c) {

    int i ,j ;
    for (i=0 ; i<r ; i++) {
        for (j=0; j<c; j++) {
            scanf("%f",&mat[i][j]) ;
        }
    }
}
void computeProduct(float mat1[][MAX], int r1, int c1,
                       float mat2[][MAX], int r2, int c2,
                       float mat3[][MAX], int* r3, int* c3){

                      *r3=r1 ;
                      *c3=c2 ;

                      int sum=0 ,i,j,k;
    for (i=0 ; i<*r3; i++) {
        for (j=0 ; j<*c3 ; j++) {


          // matrixlerin hasilin tap !
            sum=0 ;
            for (k=0 ; k<c1 ; k++) {
                    sum=sum+mat1[i][k]*mat2[k][j] ;
            }

        mat3[i][j]=sum ;
        }
       }
                       }
     void writeMatrix(float mat1[][MAX], int r1, int c1,
                       float mat2[][MAX], int r2, int c2,
                       float mat3[][MAX], int r3, int c3){

                       int i,j ;
                       for (i=0 ; i<r1 ; i++) {
                        for (j=0 ; j<c1; j++) {
                            printf("%f " ,mat1[i][j]) ;

                        }
                        puts("") ;
                       }
                       puts("");

                       for (i=0 ; i<r2 ; i++) {
                        for (j=0 ; j<c2; j++) {
                            printf("%f " ,mat2[i][j]) ;

                        }
                        puts("") ;
                       }
                       puts("");


                       for (i=0 ; i<r3 ; i++) {
                        for (j=0 ; j<c3; j++) {
                            printf("%f " ,mat3[i][j]) ;

                        }
                        puts("") ;
                       }
                       puts("");



                       }




