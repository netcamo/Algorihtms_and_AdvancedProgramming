#ifndef TEMP_WORK_H_INCLUDED
#define TEMP_WORK_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct e_u{
    char* name ;
    int assigned_f;
    int* preference_off ;


}e_t;

typedef struct f_u{
    char *name ;
    int used;
    int assigned_e;
    int* preference_ofe ;

}f_t;

typedef struct cdb_u{


    int** table_e ;
    int** table_f ;
    e_t* arr_e ;
    f_t* arr_f ;
    int n;
    int act_ne ;
    int act_nf ;


}cdb_t ;//company database
cdb_t* cdb_init(int n) {
    cdb_t* cdb=malloc(sizeof(cdb_t));
    cdb->n=n ;
    cdb->act_ne=0 ;
    cdb->act_nf=0;
    cdb->arr_e=malloc(n*sizeof(e_t)) ;
    cdb->arr_f=malloc(n*sizeof(f_t)) ;
    cdb->table_e=malloc(n*sizeof(int*)) ;
    cdb->table_f=malloc(n*sizeof(int*)) ;
    int i ;
    for(i=0 ; i<n; i++) {
        cdb->table_e[i]=malloc(n*sizeof(int)) ;
        cdb->table_f[i]=malloc(n*sizeof(int)) ;
    }
    for(i=0 ; i<n ; i++) {
        cdb->arr_e[i].name=NULL ;
        cdb->arr_f[i].name=NULL ;
    }
    return cdb;
}
int add_e(cdb_t* cdb, char* s) {

    int found=0 ;
    int i , j, k;
    for ( i = 0 ; i< cdb->act_ne ; i++) {
        if(strcmp(s,cdb->arr_e[i].name)==0){
            found= 1 ;
            break ;
        }
    }
    if(found==1)  return i ;
    else {
        i=cdb->act_ne ;
        cdb->act_ne++ ;
        cdb->arr_e[i].name=strdup(s) ;
        cdb->arr_e[i].assigned_f=-1 ;
        cdb->arr_e[i].preference_off=malloc(sizeof(int)*cdb->n);

        return i ;
    }


}
int add_f (cdb_t* cdb, char* s) {
    int found=0 ;
    int i , j, k;
    for ( i = 0 ; i< cdb->act_nf ; i++) {
        if(strcmp(s,cdb->arr_f[i].name)==0){
            found= 1 ;
            break ;
        }
    }
    if(found==1)  return i ;
    else {
        i=cdb->act_nf ;
        cdb->act_nf++ ;
        cdb->arr_f[i].used=0;
        cdb->arr_f[i].name=strdup(s) ;
        cdb->arr_f[i].assigned_e=-1;
        cdb->arr_f[i].preference_ofe=malloc(sizeof(int)*cdb->n);

        return i ;
    }


}
void print_everything (cdb_t* cdb) {
    printf("\tSTART OF PRINTING\n%d %d %d\n",cdb->n, cdb->act_ne, cdb->act_nf) ;
    int i , j ;
    for(i=0; i<cdb->act_ne ; i++) {
        printf("%s %d\n",cdb->arr_e[i].name,cdb->arr_e[i].assigned_f);
    }
    puts("");
    for(i=0 ;i<cdb->act_nf;i++) {
        printf("%s %d %d\n",cdb->arr_f[i].name,cdb->arr_f[i].assigned_e,cdb->arr_f[i].used);
    }
    puts("TABLE E\n") ;
    for(i=0 ; i<cdb->n; i++) {
        printf("%s - ",cdb->arr_e[i]) ;
        for(j=0 ; j<cdb->n ; j++) {
            printf("%s ",cdb->arr_f[cdb->table_e[i][j]].name);
        }
        puts("") ;
    }
    puts("\nTABLE F\n") ;

    for(i=0 ;i<cdb->n ; i++) {
        printf("%s - ",cdb->arr_f[i]);
        for(j=0 ; j<cdb->n;j++) {
            printf("%s ",cdb->arr_e[cdb->table_f[i][j]].name) ;
        }
        puts("") ;

    }

    puts("\tEND OF PRINTING\n") ;



}
cdb_t* load_file(char *filename) {

    int n ;
    FILE* in=fopen(filename,"r") ;
    fscanf(in,"%d\n",&n) ;
    cdb_t* cdb=cdb_init(n) ;


    char s[1000] ;
    int i ,j,k ;
    for(i=0 ; i<n ; i++) {
       fscanf(in,"%s",s) ;
        add_e(cdb,s) ;
        for(j=0; j<n ; j++) {
            fscanf(in ,"%s",s) ;
            cdb->table_e[i][j]=add_f(cdb,s) ;
        }
    }
    char z[1000] ;
    for(i=0; i<n ; i++) {
         fscanf(in,"%s",z) ;
        add_f(cdb,z) ;
        for(j=0; j<n ; j++) {
            fscanf(in ,"%s",s) ;
            cdb->table_f[add_f(cdb,z)][j]=add_e(cdb,s) ;
        }
    }


    fclose(in) ;
    return cdb;

}

void solve(cdb_t* cdb) {
      int z=0 ;
        solve_r (cdb , 0,&z) ;

    //printf("---%d----",z) ;



}


int check(cdb_t* cdb) {



    int e , f,i,j,jj,condition=0;
    for( e =0 ; e<cdb->n ; e++) {
        for(f=0 ; f<cdb->n; f++) {
            condition=0 ;

            for(i=0 ; i<cdb->n; i++) {
                if(cdb->table_e[e][i]==f) j=i ;
                if(cdb->table_e[e][i]==cdb->arr_e[e].assigned_f) jj=i;
            }
            if(j<jj)condition++ ;

            for(i=0 ; i<cdb->n; i++) {
                if(cdb->table_f[f][i]==e) j=i ;
                if(cdb->table_f[f][i]==cdb->arr_f[f].assigned_e)jj=i ;
            }
            if(j<jj)condition++ ;
            if(condition==2) return 0;






        }
    }


    return 1 ;


}


int solve_r (cdb_t* cdb ,int k, int* z) {
    if(k==cdb->n) {
        // check soution
        if(check(cdb)) {
            puts("YESSS") ;
            print_everything(cdb) ;
            int u ;
            for(u =0 ; u<cdb->n ; u++) {
                printf("%s %s \n",cdb->arr_e[u].name , cdb->arr_f[cdb->arr_e[u].assigned_f].name) ;
            }
            return 1;
        }
        (*z)++ ;
        //print_everything(cdb) ;
        //exit(1) ;
        return 0 ;

    }

    int i , j ;
        for(j=0; j<cdb->n; j++) {

                if(cdb->arr_f[j].used==0) {
                   cdb->arr_e[k].assigned_f=j ;
                   cdb->arr_f[j].used=1;
                   cdb->arr_f[j].assigned_e=k ;
                   if( solve_r(cdb,k+1,z) ) return 1 ;
                   cdb->arr_e[k].assigned_f=-1 ;
                   cdb->arr_f[j].used=0;
                   cdb->arr_f[j].assigned_e=-1 ;
                }



        }


    return 0 ;



}




#endif // TEMP_WORK_H_INCLUDED
