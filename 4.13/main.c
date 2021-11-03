#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list {

struct list *next_mark ;
struct list *next_name ;
 char surname[22] ;
 float mark ;

}list;
list *insert_mark (list* new_el ,list *head_mark ) ;

list *insert_name (list* new_el ,list *head_name ) ;
void read_file (list** head_name ,list** head_mark ,int  *n)  ;
void error() {
puts("memerror") ;
exit(1) ;
}

int main()
{

    list *head_ptr=NULL;
    int n =0;

    list *head_name=head_ptr,*head_mark=head_ptr ;
    read_file(&head_name ,&head_mark ,&n) ;

    list* go ;
    go=head_name ;
    while(go!=NULL) {
        printf("%s %f\n" , go->surname , go->mark) ;
        go=go->next_name;
    }


    return 0;
}



list *insert_mark (list* new_el ,list *head_mark )
{

    if(head_mark==NULL || new_el->mark>head_mark->mark) {
        new_el->next_mark=head_mark ;
        return new_el ;
    }
    list* head=head_mark ;
    list *go ;
    list *go_next ;
    go=head;
    go_next=go->next_mark ;
    while(go_next!=NULL && go_next->mark >new_el->mark) {

        go=go_next ;
        go_next=go_next->next_mark ;


    }
    go->next_mark=new_el;
    new_el->next_mark=go_next ;

    return head ;
}


list *insert_name (list* new_el ,list *head_name ) {
    list *head=head_name ;
    if (head==NULL||strcmpi(new_el->surname,head->surname)>0){
        new_el->next_name=head ;
        return new_el ;
    }

     list *go ;
    list *go_next ;
    go=head;
    go_next=go->next_name;
    while(go_next!=NULL && strcmpi(go_next->surname ,new_el->surname)>0) {

        go=go_next ;
        go_next=go_next->next_name ;


    }
    go->next_name=new_el;
    new_el->next_name=go_next ;

    return head ;


}





void read_file (list** head_name,list** head_mark , int  *n)  {
    list *head,*cur;
    list *tmp ;
    FILE* in =fopen("input.txt","r") ;
    char s[1000];
    char surname[22] ;
    float mark ;
    head=NULL ;
    while(fgets(s,10000,in)!=NULL) {
        sscanf(s,"%s %f",surname, &mark) ;
        (*n)++  ;
        tmp=malloc(sizeof(list)) ;
        if(tmp==NULL) error() ;
        tmp->mark=mark;
        strcpy(tmp->surname,surname) ;
        *head_mark =insert_mark( tmp,*head_mark );
        *head_name=insert_name( tmp,*head_name) ;
    }

    fclose(in) ;
}
