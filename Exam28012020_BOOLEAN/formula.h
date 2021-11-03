#ifndef FORMULA_H_INCLUDED
#define FORMULA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct formula_u{

    int n_clause;
    int n_variables ;
    struct clause_u *clause ;

}formula_t;

typedef struct clause_u{

    int n_var;
    int* vars;

}clause_t;

void print_arr(int* arr, int n);
int* arr_alloc(int n);
void check_malloc (void *ptr) ;
void    print_formula(formula_t* formula);


formula_t* load_file(char *filename);
void turn_int_tobitarray(int a,int* arr, int n);
int eval (int arr_value , int formula_val);
int check_sol(int* arr, formula_t* formula) ;
void print_sol (int *arr, int n);
void solve (formula_t *formula);
void dispose (formula_t* formula);


#endif // FORMULA_H_INCLUDED
