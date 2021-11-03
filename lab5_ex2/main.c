#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char*** m_alloc (int R,int C) ;
char*** read_file (FILE* in , int* R , int* C) ;
char** sort_mat(char*** mat, int R , int C) ;
void print_file(FILE* , int ,char**) ;
int main()
{
    char*** mat ;
    char** fin_mat ;
    FILE* in=fopen ("input",  "r") ;
    FILE* out= fopen( "output", "w") ;
    int R,C,i,j ;
    //fscanf(in , "%d %d\n",&R,&C) ;
    mat=read_file(in, &R ,&C) ;
    fin_mat=sort_mat (mat ,R ,C) ;

    for (i=0 ; i<R*C ;i++ ){
        printf("%s\n",fin_mat[i]) ;
    }

    print_file (out, R*C , fin_mat) ;

    for (i=0; i< R ; i++) {
        for (j=0; j<C ; j++) {
                //printf("%s\n",mat[i][j]) ;
            free(mat[i][j]) ;
        }
        free(mat[i]) ;
    }
    free(mat) ;
    for (i=0 ; i<R*C ; i++) {
        free(fin_mat[i]);
    }
    free(fin_mat) ;

    return 0;
}

void print_file(FILE* out ,int n , char** mat) {

    fprintf(out,"%d\n",n) ;
    int i =0 ;
    for (i ; i <n; i++) {
        fprintf(out,"%s\n",mat[i]) ;
    }




fclose(out) ;
return ;
}


char** sort_mat(char*** mat, int R , int C) {
    char** mat_fin ;
    int n =R*C , i , j , k ;
    mat_fin=malloc(sizeof(char*)*R*C) ;

    int* row_min_place ;

    row_min_place=calloc(R,sizeof(int)) ;
   // for (i=0 ; i<R ; i++ ) {printf("%d ",row_min_place[i]);}
    char min_word[22] ;
    int min_word_row_number;
    i=0 ;
   // puts("yes") ;
    for (i=0 ; i<R*C; i++) {
              k=0 ;
           while (row_min_place[k]>=C){
            k++ ;
           }
            strcpy(min_word,mat[k][row_min_place[k]]) ;
            min_word_row_number=k ;

        for (j=0 ; j<R ; j++) {
            if (row_min_place[j]<C) {
                if (strcmp(min_word,mat[j][row_min_place[j]])>0){

            strcpy(min_word,mat[j][row_min_place[j]]) ;
            min_word_row_number=j ;

                }
            }

        }
       // printf("%s %d %d\n" , min_word,min_word_row_number , row_min_place[min_word_row_number]);
      mat_fin[i]=strdup(min_word) ;
     //8 strcpy(mat_fin[i],min_word) ;
      row_min_place[min_word_row_number]++ ;

    }
    free(min_word) ;
    free(row_min_place) ;
   // puts("yessss");
    return mat_fin ;


}


char*** read_file (FILE* in , int* R , int* C) {
    char*** mat ;
    char s[22] ;
    fscanf(in , "%d %d\n",R,C) ;
    int  r=*R , c=*C,i,j;
    mat=m_alloc(r,c) ;
    for (i=0 ; i<r; i++) {
        for (j=0 ; j<c ; j++){
            fscanf(in , "%s",s) ;
            mat[i][j]=strdup(s) ;
        }
    }

    fclose(in) ;
    return mat ;

}



char*** m_alloc (int R,int C) {
    int i ;
    char*** mat ;
    mat=malloc(sizeof(char**)*R) ;
    for (i=0 ; i< R ; i++) {
        mat[i]=malloc(sizeof(char*)*C) ;
    }
    return mat ;

}
