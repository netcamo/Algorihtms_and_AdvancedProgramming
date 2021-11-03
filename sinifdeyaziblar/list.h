#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct list_t{
    char *surname;
    char *name;
struct list_t* next ;
}list_t ;

list_t* new_list () {

list_t* a ;
a=NULL ;
return a ;

}


void destroy_node(list_t* t) {

free(t->name) ;
free(t->surname);
free(t) ;

}

void print_list(list_t *head) {

list_t* go=head ;
while(go!=NULL) {
    printf("%s %s\n",go->surname,go->name) ;
go=go->next ;
}

return ;

}

int list_insert_in_order (list_t **headP , char *surname, char *name ) {

    list_t* head=*headP ;
    list_t* temp=malloc(sizeof(list_t)) ;

    temp->name=strdup(name) ;
    temp->surname=strdup(surname) ;
    temp->next=NULL ;

    if(head==NULL) { // list is empty
        *headP=temp ;
        return 1 ;
    }
    if(strcmp(surname ,head->surname)<0|| (strcmp(surname, head->surname)==0 && strcmp(name ,head->name)<0)){
        temp->next=head ;
        *headP=temp ;
        return 1 ;
    }
    list_t* go=head;

    while(go->next!=NULL&& (strcmp(surname ,go->next->surname)>0 || (strcmp(surname,go->next->surname)==0 && strcmp(name,go->next->name)>0))) {
      go=go->next;

    }
    temp->next=go->next ;
    go->next=temp ;
     if (strcmp(surname,go->surname)==0 &&strcmp(name,go->name)==0)
    {
        return 3 ;
    }


}



#endif // LIST_H_INCLUDED
