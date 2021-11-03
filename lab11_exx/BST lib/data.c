#include "data.h"


int readData (FILE *fp,data_t *data  )
{
    char reg_number[11] ;
    char last_name[MAXC] ;
    int  credit_loaded ;
    int credit_passed ;

  if(fscanf(fp,"%s %s %d %d",reg_number,last_name,&credit_loaded,&credit_passed)==4) {
  data->credit_loaded=credit_loaded ;
  data->credit_passed=credit_passed;
  data->lastname=strdup(last_name) ;
  data->register_number=strdup(reg_number) ;
   //int retValue;
return 1 ;
  }
  //retValue = fscanf (fp, "%d", data);

  return 0;
}


void writeData (FILE *fp,data_t data)
{
  fprintf(fp, "%s %s %d %d\n", data.register_number,data.lastname,data.credit_loaded,data.credit_passed);

  return;
}


int compare ( data_t d1,  data_t d2  ){

    char s1[10] ,s2[10] ;
    strcpy(s1,d1.register_number) ;
    strcpy(s2,d2.register_number) ;
    int flag =0 ;
    if(strlen(s1)!=strlen(s2))  {
        if(strlen(s1)>strlen(s2))
            return (1) ;
        else return (-1) ;
    }
    else {
        int i ,j ;
        for (i=0 ; i<strlen(s1)&&flag==0 ; i++) {
            flag=s1[i]-s2[i] ;
        }
        if (flag<0) flag=-1 ;
        else if (flag>0)flag=1 ;
        return flag ;
    }

}
