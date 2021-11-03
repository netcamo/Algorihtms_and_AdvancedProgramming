#ifndef _DATA_INCLUDED
#define _DATA_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXC 100

typedef struct data_s data_t;

struct data_s {

char *register_number ;
char *lastname;
int  credit_loaded;
int  credit_passed ;


};


int readData (FILE *, data_t *);
void writeData (FILE *, data_t);
int compare (data_t, data_t);

#endif
