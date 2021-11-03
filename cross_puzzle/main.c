#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(R,C) ((R>C)?R:C)

 char **malloc2d(int R, int C);
 void free2d (char ** , int R ,int C) ;
 void find(char * , char ** , char *** , int  , int) ;
void find_all(char *word , char ** , char *** , int R , int C , int r, int c) ;




int main()
{
    FILE *in=fopen("mat.txt","r") ;
    FILE *out=fopen("out.txt","w") ;
    FILE *words= fopen ("words","r") ;
    if (in ==NULL || out==NULL || words== NULL ) {
        puts("cant open file") ;
        return 1;
    }


    char **matrix_1st,**matrix_out;
    int R,C ;
    char *word ;

   char s[1000] ;
   fgets(s,1000,in) ;
   sscanf(s ,"%d %d" ,&R,&C )
 ;
int i , j , k ;
    matrix_1st=malloc2d(R,C) ;
    matrix_out=malloc2d(R,C) ;
    for (i=0 ; i<R; i++) {
        for (j=0 ; j<C; j++) {
            matrix_out[i][j]=' ' ;

        }
        matrix_out [i][j]='\n' ;
    }
    word=malloc((max(R,C)+1)*sizeof(char)) ;

   for (i = 0 ; i <R ; i++) {
    fgets(s,1000 ,in) ;
    strcpy(matrix_1st[i],s) ;
   }

    while (fgets(s ,1000 ,words)!=NULL) {
        sscanf(s, "%s", word) ;

         find (word ,matrix_1st , &matrix_out , R ,C ) ;
    }


    for (i=0 ; i<R ; i++)
    {
        for (j=0 ; j<C+1; j++) {

            printf("%c" , matrix_out[i][j]) ;

        }
    }




    free2d(matrix_1st,R,C) ;
    free(word) ;

    fclose(in) ;
    fclose(out) ;
    fclose(words) ;
    return 0;
}






 char **malloc2d(int R, int C)    {

   char **mat=NULL ;

   int i , j ;
    mat=malloc(R*sizeof(char *)) ;
    if (mat==NULL) {puts("cant allocate memorty") ; exit(1) ;}
   for (i=0 ; i<R ; i++){
    mat[i]=malloc((C+1)*sizeof (char)) ;

    if (mat[i]==NULL) {
        puts("Cant allocate the memory") ;
        exit(1) ;
    }
    }
    return mat ;

    }

void free2d( char ** mat,int R, int C) {

            int i ;
            for ( i =0 ; i<R; i++ ) {
                free(mat[i]) ;
            }
        free(mat) ;
        return ;
    }

void find_all(char *word , char **mat , char ***out , int R , int C , int r, int c) {
            char  ** mat_out=*out ;

        //mat_out  modified.
        int flag  ;
        int r_new ,c_new ;
         //   printf(" %s %d \n", word , strlen(word)) ;
        int versor[8][2] ={{0 ,1},{0,-1},{1,0},{1,1},{1,-1},{-1,0},{-1,1},{-1,-1}} ;
     int i , j ;
     for (i = 0 ; i<8 ; i++) {
        flag=1;
        for (j=1 ; j<strlen(word)&&flag==1 ; j ++) {
            r_new=r+versor[i][0]*j ;
            c_new=c+versor[i][1]*j ;

            if (r_new<0 || r_new>=R || c_new<0 || c_new>=C || word[j]!=mat[r_new][c_new]) {
                flag=0 ;
            }

        }

        if (flag==1) {
            for (j=0 ; j<strlen(word) ; j++) {
                mat_out[r+j*versor[i][0]][c+j*versor[i][1]] =word[j] ;
            }
        }



     }





return ;
}


  void find(char *word , char **mat_search , char ***mat_out , int R  , int C)  {
    int  i , j;
        for (i=0 ; i<R; i++) {
            for (j=0 ; j<C; j++) {
                if (word[0]==mat_search[i][j]) {
                    find_all(word, mat_search , mat_out  , R , C , i , j) ;
                }
            }
        }


    return ;
  }

