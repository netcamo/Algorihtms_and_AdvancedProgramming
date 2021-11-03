#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data {

char *name ;
char pi[17] ;
char *date ;
int salary ;
struct data* next ;

struct data* previous ;

}data ;

void read_file(data** head, data** tail , char* filename) {
FILE* in = fopen(filename, "r");
data *h ,*t,*tmp ;
char tmpname[52],tmpdate[17] ;

h=NULL ;
t=NULL ;
char s[1000];
data *cur ;

while (fgets(s , 1000 , in)!=NULL) {


cur=malloc(sizeof(data)) ;
sscanf(s ,"%s %s %s %d" ,tmpname, cur->pi , tmpdate ,&cur->salary) ;
//printf("%s %s %s %d\n", tmpname , tmppi , tmpdate ,&tmpsal) ;
cur->name=strdup(tmpname) ;
cur->date=strdup(tmpdate) ;
if (h==NULL &&t==NULL) {
    t=cur ;
    cur->next=NULL ;
    cur->previous=NULL;
    h=cur ;
}
else {
        h->previous=cur ;
    cur->next=h ;
    cur->previous=NULL ;
    h=cur ;

}


}

*head=h ;
*tail=t ;

//puts("SUCCESSFUL reading");
fclose(in) ;
return ;
}

data* find_name (data* head , char* name) {
    data* go ;
    for (go=head; go!=NULL ; go=go->next) {
        if(strcmp(name, go->name)==0) {
            return go;
        }
    }
    return NULL ;

}


void process (data *start , char* path )
{   data *go=start ;
    int i =0 ;
        printf("%s %s %s %d\n" , go->name,go->pi , go->date, go->salary) ;
    for (i ; i<strlen(path) ; i++) {
        if(path[i]=='+'&& go->next!=NULL) {
            go=go->next ;
        }
        else if (path[i]=='-' && go->previous !=NULL){
            go=go->previous ;
        }
        printf("%s %s %s %d\n" , go->name,go->pi , go->date, go->salary) ;
    }

    return ;

}


void destroy (data* head) {
data* go ;

go=head;
while(go!=NULL) {

    head=go ;
    go=go->next ;
        free(head->date) ;
        free(head->name);
        free(head) ;


}



}

int main(int argc , char* argv[])
{

    data* head ;
    data* tail ;
    read_file(&head, &tail , argv[1]) ;
    data *go  ;
    go=find_name(head,argv[2]) ;
    process(go,argv[3]) ;

    destroy(head) ;


    return 0;
}
