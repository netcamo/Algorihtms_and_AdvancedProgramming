#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list {

struct list *next ;
 char surname[22] ;
 float mark ;

}list;

list *read_file (int  *n)  ;
void error() {
puts("memerror") ;
exit(1) ;
}

void write (list *head  ,int n , char *s ) ;
void sort_mark(list* ,int) ;
void sort_sur(list* ,int) ;

int main()
{

    list *head_ptr=NULL;
    int n =0;
    head_ptr=read_file(&n) ;


    sort_mark(head_ptr, n) ;
    write(head_ptr, n , "out_mark.txt") ;



    sort_sur(head_ptr, n) ;
    write(head_ptr , n , "out_sur.txt") ;
    while(head_ptr!=NULL) {
        printf("%s %f\n",head_ptr->surname,head_ptr->mark) ;
        head_ptr=head_ptr->next ;
    }


    return 0;
}

void sort_mark(list *head, int n ) {
    list *go;
    list *tmp=malloc(sizeof(list)) ;
    list *searcher ;
    for (go=head ; go!=NULL ; go=go->next) {

        for(searcher=go ; searcher!=NULL ; searcher=searcher->next) {
            if(searcher->mark > go->mark) {
                tmp->mark=go->mark ;
                strcpy(tmp->surname,go->surname) ;
                go->mark=searcher->mark;
                strcpy(go->surname,searcher->surname) ;
                searcher->mark=tmp->mark;
                strcpy(searcher->surname,tmp->surname) ;
            }

                }

            }




        }







void sort_sur(list *head, int n) {
        list *go;
    list *tmp=malloc(sizeof(list)) ;
    list *searcher ;
    for (go=head ; go!=NULL ; go=go->next) {

        for(searcher=go ; searcher!=NULL ; searcher=searcher->next) {
            if(strcmpi(searcher->surname,go->surname)<0) {
                tmp->mark=go->mark ;
                strcpy(tmp->surname,go->surname) ;
                go->mark=searcher->mark;
                strcpy(go->surname,searcher->surname) ;
                searcher->mark=tmp->mark;
                strcpy(searcher->surname,tmp->surname) ;
            }

                }

            }




}









void write (list *head  ,int n ,char* s) {
FILE* out=fopen(s ,"w") ;
list* tmp ;
tmp=head;
    while (tmp!=NULL) {
        fprintf(out,"%s %f\n" , tmp->surname , tmp->mark) ;
        tmp=tmp->next ;
    }



fclose(out) ;
}




list *read_file (int  *n)  {
    list *head,*cur;
    FILE* in =fopen("input.txt","r") ;
    char s[1000];
    char surname[22] ;
    float mark ;
    head=NULL ;
    while(fgets(s,10000,in)!=NULL) {
        sscanf(s,"%s %f",surname, &mark) ;
        (*n)++  ;
        cur=malloc(sizeof(list)) ;
        if(cur==NULL) error() ;
        cur->mark=mark;
        strcpy(cur->surname,surname) ;
        cur->next =head ;
        head=cur;

    }

    return head ;
    fclose(in) ;
}
