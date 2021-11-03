#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct product {

    char* product_name;
    int price ;
    struct product* next ;
}product;


typedef struct producer{

    char* id ;
    char* producer_name;
    struct   producer* next ;
    product* prod;


}producer;


producer* read_producer (char* fin) {
producer* head=NULL ;
producer* cur ;
FILE* in=fopen(fin,"r") ;
char s[10000] ;
char id[1000], name[1000] ;
while (fgets(s,1000,in)!=NULL) {
    sscanf(s,"%s %s\n" ,name,id) ;
    cur=malloc(sizeof(producer)) ;
    cur->id=strdup(id) ;
    cur->producer_name=strdup(name) ;
    cur->prod=NULL ;
    cur->next=head ;
    head=cur ;


}
fclose(in) ;
return head ;
}


void read_product(producer** head , char* fin) {
    FILE* in = fopen(fin , "r") ;
    char s[1000] ;
    int price;
    char name[10000];
    char produc_er[1000] ;
    product* go_p ;
    producer* go=*head ;
    while(fgets(s,1000,in)!=NULL) {
            go=*head ;
        sscanf(s,"%s %s %d\n",produc_er , name ,&price)  ;
            //printf("%s %s %d\n",produc_er , name ,price) ;
        while(strcmp(go->id , produc_er)!=0) {
            go=go->next ;
        }

        go_p=malloc(sizeof(product)) ;
        go_p->price=price ;
        go_p->product_name=strdup(name) ;
        go_p->next=go->prod ;
        go->prod=go_p ;


    }



    fclose(in) ;


}

int main(int argc, char* argv[])
{

    producer* producer_head=read_producer(argv[1]),*go;
    go=producer_head ;
    product* go_p ;
    read_product(&producer_head ,argv[2]) ;
    while (go!=NULL) {
        go_p=go->prod;
       printf("%s : ---------------------\n",go->producer_name) ;
        while(go_p!=NULL) {
            printf("%s %d\n",go_p->product_name , go_p->price) ;
            go_p=go_p->next;
        }
        puts("---------\n-----------\n") ;

        go=go->next ;
    }


    return 0;
}
