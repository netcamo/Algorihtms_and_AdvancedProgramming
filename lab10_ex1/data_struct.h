#ifndef DATA_STRUCT_H_INCLUDED
#define DATA_STRUCT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXC 20

struct data {
char *name ;
char *date;
char *course;
int year ;
int code;

};
typedef struct data data_t;

int readData (FILE *, data_t *);
void writeData (FILE *, data_t);
int compare_name (data_t, data_t);
int compare_reg_num (data_t, data_t);


#endif // DATA_STRUCT_H_INCLUDED
