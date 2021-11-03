#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "item.h"


Item ITEMscan(FILE* fp ) {

    Item tmp = (Item) malloc(sizeof(struct item));
    char reg_number[11] ;
    char last_name[102] ;
    int  credit_loaded ;
    int credit_passed ;
    if(fscanf(fp,"%s %s %d %d",reg_number,last_name,&credit_loaded,&credit_passed)==4) {
          tmp->credit_loaded=credit_loaded ;
          tmp->credit_passed=credit_passed;
          tmp->lastname=strdup(last_name) ;
          tmp->register_number=strdup(reg_number) ;
    return tmp ;

    }
    else return  NULL;
}


Item ITEMset (char *key,char *name,
  int ncl,
  int ncp
  )
{
  Item tmp = (Item) malloc(sizeof(struct item));
  if (tmp == NULL) {
    return ITEMsetvoid();
  } else {
    tmp->register_number = strdup(key);
    tmp->lastname = strdup(name);
    tmp->credit_loaded = ncl;
    tmp->credit_passed = ncp;
  }
  return tmp;
}


void ITEMshow(FILE* fp,Item data) {
 fprintf(fp, "%s %s %d %d\n", data->register_number,data->lastname,data->credit_loaded,data->credit_passed);

}

int ITEMcheckvoid(Item data) {
  Key k1, k2="";
  k1 = KEYget(data);
  if (KEYcompare(k1,k2)==0)
    return 1;
  else
    return 0;
}

Item ITEMsetvoid() {
  char name[111]="";
  Item tmp = (Item) malloc(sizeof(struct item));
  if (tmp != NULL) {
    tmp->register_number = strdup(name);
    tmp->lastname = strdup(name);
    tmp->credit_loaded=-1;
    tmp->credit_passed=-1;
  }
  return tmp;
}

Key KEYscan() {
  char name[MAXST];
  Key k;
  scanf("%s", name);
  k = strdup(name);
  return k;
}

int  KEYcompare(Key k1, Key k2) {


    char s1[10] ,s2[10] ;
    strcpy(s1,k1) ;
    strcpy(s2,k2) ;
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

Key KEYget(Item data) {
  return data->register_number;
}
