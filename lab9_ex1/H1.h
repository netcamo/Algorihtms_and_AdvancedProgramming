#ifndef H1_H_INCLUDED
#define H1_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** f_read(int* R ,int* C) ;
char** alloc2D (int R, int C) ;
void chechnerror(void* p) ;
void print_matrix(char** matrix ,int R , int C) ;

void find_init (char** maze , int R ,int C,int *x ,int *y);
int find_one(char** maze , int R ,int C,int i ,int j );

int find_all(char** maze , int R ,int C,int i ,int j) ;

int find_best(char** maze ,char** maze_best, int R ,int C,int i ,int j, int stepcur, int* stepbest);

#endif // H1_H_INCLUDED
