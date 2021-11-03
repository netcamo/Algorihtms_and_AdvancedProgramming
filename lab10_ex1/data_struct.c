#include "data_struct.h"

int readData (FILE *fp,data_t *data)
{
  int retValue;
  int register_number ;
  char name[MAXC] ;
  char surname[MAXC] ;
  char date[MAXC] ;
  char course [MAXC] ;
  int year ;

  //data

  retValue = fscanf (fp, "%d %s %s %s %s %d", &register_number,surname,name,date,course,&year);
  //printf("%d %s %s %s %s %d",register_number ,surname ,name ,date, course ,year) ;
   data->code=register_number ;
   data->year=year ;
   data->date=strdup(date) ;
   data->course=strdup(course) ;
   strcat(surname," ") ;
   strcat(surname ,name) ;
   data->name=strdup(surname) ;
  return (retValue);
}


void writeData (FILE *fp,data_t data)
{
  fprintf(fp, "%d %s  %s %s %d\n", data.code ,data.name, data.date , data.course ,data.year);

  return;
}


int compare_name (data_t d1,data_t d2)
{
  if (strcmp(d1.name,d2.name)<0) {
    return (-1);
  } else {
    if (strcmp(d1.name,d2.name)==0) {
      return (0);
    } else {
      return (1);
    }
  }
}


int compare_reg_num (data_t d1,data_t d2)
{
  if (d1.code-d2.code<0) {
    return (-1);
  } else {
    if (d1.code-d2.code==0) {
      return (0);
    } else {
      return (1);
    }
  }
}


