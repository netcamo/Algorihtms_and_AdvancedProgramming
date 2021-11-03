#include "formula.h"



void check_malloc (void *ptr) {
    if(ptr==NULL) {
        puts("Malloc error") ;
        exit(2) ;
    }
}

void    print_formula(formula_t* formula) {

    printf("%d %d\n",formula->n_clause,formula->n_variables) ;
    int i , j ;
    for (i=0 ; i<formula->n_clause ; i++) {
        printf("%d ",formula->clause[i].n_var) ;
        for(j=0 ; j<formula->clause[i].n_var ; j++) {
            printf("%d ",formula->clause[i].vars[j]) ;
        }
        puts("") ;
    }
    return ;
}

formula_t* load_file(char *filename) {
    FILE* in =fopen(filename, "r") ;
        if(in==NULL) {
            puts("error opening!");
            exit(1) ;
        }
        int t1,t2 ,i,j ;
        char s[1000] ;
        fgets(s,1000,in) ; //I wrote in and then s in paper
        sscanf(s,"%d %d",&t1,&t2) ;
        formula_t* formula=malloc(sizeof(formula_t)) ;
        check_malloc(formula->clause) ;
        formula->n_clause=t1 ;
        formula->n_variables=t2 ;
        formula->clause=malloc(t1*sizeof(clause_t)) ;
        check_malloc(formula->clause) ;
        for(i=0 ; i<t1; i++) {
            fscanf(in,"%d",&t2) ;
            formula->clause[i].n_var=t2 ;
            formula->clause[i].vars=malloc(t2*sizeof(int)) ;
            check_malloc(formula->clause[i].vars) ;
            for(j=0 ; j<t2; j++) {
                fscanf(in,"%d",&formula->clause[i].vars[j]);
                if(formula->clause[i].vars[j]>formula->n_variables) {
                    puts("ERROR : wrong number of variable") ;
                    exit(1) ;
                }
            }
        }
        fclose(in) ;
        return formula;
}

void print_arr(int* arr, int n) {
    int i;
    for(i=0 ; i<n ; i++) {
        printf("%d ",arr[i]) ;
    }
    puts("") ;
    return ;

}

void turn_int_tobitarray(int a,int* arr, int n) {

    int i,j,k ;
    for(i=0 ; i<=n ; i++) {
        if((1<<i)&a)arr[i]=1 ;  // in paper i confused and wrote &n and also confused and wrote 2<<
        else arr[i]=0 ;
    }

    return ;

}

int* arr_alloc(int n) {
    int* arr=malloc(sizeof(int)*n) ;
    check_malloc(arr) ;
    return arr;

}

int eval (int arr_value , int formula_val) {
    int s;
    s=arr_value;
    if(formula_val<0) {
        if(s==1)s=0 ;
        else if (s==0) s=1; //i forgot to write else on paper
    }
    return s;
}

int check_sol(int* arr, formula_t* formula) {

    int f=1 ;
    clause_t ct ;
    int i ,j,k ,z ;
    int s;
    for(i=0 ; i<formula->n_clause; i++) {
        ct=formula->clause[i] ;
        s=0 ;
        for(j=0 ;j<ct.n_var; j++) {
            s+=eval(arr[abs(ct.vars[j])],ct.vars[j]) ;
        }
        f=f*s;
        if(!f)return 0 ;
    }
    return 1 ;
}

void print_sol (int *arr, int n) {

    int i ,j ;
    puts("PROBLEM SAT :") ;
    for(i=1 ; i<=n ; i++) {
            printf("x%d is %d \n" ,i,arr[i]) ;
    }
    puts("") ;

}

void solve (formula_t *formula) {

    int flag=0 ;
    int n =formula->n_variables ;

    int i ,j,k ;
    int *arr =arr_alloc(formula->n_variables+1) ;
    for(i=0 ; i<=(1<<(n+1))-1 ;i++) { // in paper 2<<
            turn_int_tobitarray(i,arr,n) ;
        if(check_sol(arr,formula)) {
           flag=1 ;
            break;
        }

    }
    if(flag==1) {print_sol(arr,n) ;}
    else {puts("UNSAT");}

}

void dispose (formula_t* formula) {
    int i ;
    for(i=0 ; i<formula->n_clause ; i++) {
        free(formula->clause[i].vars) ;
    }
    free(formula->clause) ;
    free(formula) ;
    return ;
}
