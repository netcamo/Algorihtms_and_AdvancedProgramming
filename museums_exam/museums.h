#ifndef MUSEUMS_H_INCLUDED
#define MUSEUMS_H_INCLUDED



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct slot_u{
    int beginning ;
    int ending;
    }slot_t ;
typedef struct reservation_u{
    char *museum_name ;
    int day ;
    slot_t slot ;
    int people ;
    char *reservator_name;
    struct reservation_u* next ;

}reservation_t ;
typedef struct node_u {

    struct node_u* left ;
    struct node_u* right ;
    char* name ;
    int res_number ;
    reservation_t* head  ;

}node_t ;
typedef struct day_u {

    int n_slots ;
    slot_t *slots ;
    int *max_people ;

}day_t ;
typedef struct museum_u {

    char *museum_name ;
    day_t *days ;
    struct museum_u *next ;

} museum_t ;
typedef struct museums_u{


    museum_t *museum ;
    node_t* root ; //visitors



}museums_t ;


int string_to_time (char *s) {
 int a ,b ;
 sscanf(s,"%d.%d",&a,&b) ;
 return a*60+b ;

}
slot_t string_to_slot(char *s) {

    char s1[1000];
    char s2[1000] ;
    int i=0 ;
    for(i=0 ; i<11&& s[i]!='-' ; i++) {
        s1[i]=s[i] ;
    }
    s1[i++]='\0' ;
    int j=0 ;
    for(j=0;i<11 ;i++ , j++) {
       s2[j]=s[i] ;

    }
    s2[j]='\0' ;
    //sscanf(s,"%s-%s",s1,s2) ;


   // printf("%s----->%s ----- %s\n" , s, s1,s2) ;
    slot_t* slot=malloc(sizeof(slot_t)) ;
    slot->beginning=string_to_time(s1) ;
    slot->ending=string_to_time(s2) ;
 //   printf("%d %d --- %s %s \n",slot->beginning ,slot->ending , s1,s2) ;

return *slot ;
}
void print_tree(node_t *root) {

    if(root==NULL)return ;
    print_tree(root->left) ;

    int i ;
    reservation_t* res;
    res=root->head ;
    for(i=0 ; i<root->res_number ; i++) {

        printf("%s  %s %d %d %d %d\n",res->reservator_name ,res->museum_name,res->day,res->slot.beginning,res->slot.ending,res->people);

        res=res->next;
    }

    print_tree(root->right) ;

}
void print_museums_data (museums_t* museums) {
    int i;
    museum_t* museum=museums->museum ;
    while(museum!=NULL) {
        int n =museum->days[0].n_slots;
        printf("%s %d\n", museum->museum_name , museum->days[0].n_slots) ;

        for (i=0 ; i< n ; i++) {
            printf("%d-%d : %d\n",museum->days[0].slots[i].beginning,museum->days[0].slots[i].ending,museum->days[0].max_people[i]) ;
        }

        museum=museum->next ;
    }
    puts("\n\tRESERVATIONS\n") ;
    node_t *root=museums->root ;
    print_tree (root) ;
    puts("\n\tEND OF PRINTING!\n") ;

    return ;

}
int search_on_tree( node_t *root ,char *reservator_name) {

    if(root==NULL) return NULL ;
    if (strcmp(reservator_name ,root->name)==0) {
        return root ;
    }

    if(strcmp(reservator_name ,root->name)<0){
        return search_on_tree(root->right ,reservator_name) ;
    }
    else return search_on_tree(root->left ,reservator_name) ;

}
void print_node (node_t* node) {
    node_t *root=node ;
    int i ;
    reservation_t* res;
    res=root->head ;
    for(i=0 ; i<root->res_number ; i++) {

        printf("%s %d %d %d %d\n",res->museum_name,res->day,res->slot.beginning,res->slot.ending,res->people);

        res=res->next;
    }

}
void search_print (museums_t* museums ,char* name) {

    node_t *node=search_on_tree(museums->root,name) ;
    if(node==NULL) {
        puts("There is no such person !") ;
        return ;
    }
    else {

        print_node(node) ;
        return ;
    }

}
node_t* new_node (reservation_t* reservation) {
    node_t* node =malloc(sizeof ( node_t)) ;
    node->left=NULL ;
    node->right=NULL ;
    node->res_number=1 ;
    node->head=reservation ;
        node->name=strdup(reservation->reservator_name) ;
        return node ;
}
node_t* add_new_node(node_t *root , reservation_t* reservation) {

    if(root==NULL) return new_node(reservation) ;
    else if(strcmp(root->name ,reservation->reservator_name)<0) root->right=add_new_node(root->right,reservation) ;
    else root->left=add_new_node(root->left,reservation) ;

    return root ;

}
void add_to_node (reservation_t* reservation , node_t* node) {

    node->res_number++ ;
    reservation->next=node->head;
    node->head=reservation ;
return ;

}
void add_reservation_to_tree(museums_t* museums ,reservation_t* reservation) {

        node_t *node=search_on_tree( museums->root ,reservation->reservator_name) ;

        if(node!=NULL) {
            add_to_node(reservation,node) ;
            puts("foundone\n") ;
        }
        else {

                museums->root=add_new_node (museums->root ,reservation) ;
               //print_museums_data(museums) ;
            //DONE ;
        }



}
reservation_t* new_reservation (char* s) {

    reservation_t* reservation =malloc(sizeof(reservation_t)) ;
    char ss[1000] ;
    char museum_name[2000] ;
    char reservator_name[1000] ;
    char res_slot[1000] ;
    int i;
    int j ;
    int k ;
    for(i=0 ; s[i]!=','; i++) {
        museum_name[i]=s[i] ;
    }
    museum_name[i++]='\0' ;
    reservation->museum_name=strdup(museum_name);


    i++ ;
    for(j=0;s[i]!=','; i++,j++ ) {
        ss[j]=s[i] ;
    }
    ss[j]='\0' ;
    sscanf(ss,"%d",&reservation->day) ;
    i+=2 ;

     for(j=0;s[i]!=','; i++,j++ ) {
        res_slot[j]=s[i] ;

    }
    res_slot[j]='\0' ;
    i+=2 ;
    reservation->slot=string_to_slot(res_slot) ;


    for(j=0;s[i]!=','; i++,j++ ) {
        ss[j]=s[i] ;
    }
    ss[j]='\0' ;
    i+=2 ;
    sscanf(ss,"%d",&reservation->people) ;

    for(j=0;i<strlen(s); i++,j++ ) {
        reservator_name[j]=s[i] ;
    }
    reservator_name[j]='\0' ;
    reservation->next=NULL ;

    reservation->reservator_name=strdup(reservator_name) ;




return reservation ;
}
int check_availability (reservation_t reservation ,museums_t museums) {

    museum_t *museum =museums.museum ;
    while(museum!=NULL) {
        if (strcmp(reservation.museum_name,museum->museum_name)==0 ) {
              int i ,j ;
              int day=reservation.day ;
              for (i=0 ; i<museum->days[day].n_slots ; i++) {
                if (reservation.slot.beginning==museum->days[day].slots[i].beginning &&reservation.slot.ending==museum->days[day].slots[i].ending){
                    if (reservation.people<=museum->days[day].max_people[i]) {
                        //printf("%d --- " ,museum->days[day].max_people);
                        museum->days[day].max_people[i]-=reservation.people ;
                      //  printf("%d \n " ,museum->days[day].max_people);
                        return 1 ;
                    }
                    puts(" no more place") ;
                    return 0 ;
                }
              }
              puts("did not find such slot") ;
              return 0;



        }
    museum=museum->next;
    }
    puts("didnt find such museum!") ;

    return 0 ;

}
void make_appointment(museums_t* museums , char *s) {
 reservation_t* reservation=new_reservation( s) ;
 if(check_availability(*reservation,*museums) ){
        puts("BOOKED" ) ;

        add_reservation_to_tree (museums ,reservation) ;
        print_museums_data(museums) ;

 }
 else {puts("error booking!") ;
 }

return ;
}
int check_space (char *s) {
int i =0;
for ( i =0 ; i<strlen(s) ; i++) {
    if (s[i]==' ') return 1;
}
return 0;
}
museums_t *museums_init() {

    museums_t *museums=malloc(sizeof(museums_t)) ;
    museums->root=NULL ;
    museums->museum=NULL ;

return museums ;

}
museum_t* new_museum (FILE* in , int n_slots,char *museum_name) {
    int i,j ;
    museum_t *museum=malloc(sizeof(museum_t)) ;
    museum->museum_name=strdup(museum_name) ;
    museum->next=NULL ;


    museum->days=malloc(sizeof(day_t)*365) ;
    for(j=0 ; j<365;j++) {
    museum->days[j].n_slots=n_slots ;
    museum->days[j].max_people=malloc(sizeof(int)*n_slots) ;
    museum->days[j].slots=malloc(sizeof(slot_t)*n_slots) ;
    }


    char s[3000] ;
    char slot[3000] ;
    int maxpeople ;
    for (i=0 ; i<n_slots ; i++) {
        fgets(s, 3000 ,in) ;
        sscanf(s ,"%s %d",slot ,&maxpeople) ;
       // printf("MAX PEOPLE : %d \n",maxpeople) ;
        for (j=0; j<365 ;j++) {
        museum->days[j].slots[i]=string_to_slot(slot) ;
        museum->days[j].max_people[i]=maxpeople ;
        }
    }



    return museum ;
}
museums_t *add_museum (museums_t* museums,museum_t *temp_museum) {

    temp_museum->next=museums->museum ;
    museums->museum=temp_museum ;

    return museums ;
}
museums_t* load_file (char *filename) {
    FILE *in = fopen(filename ,"r") ;
    int i ,j ;
    museums_t *museums =museums_init() ;
    museum_t *temp_museum ;
    char s[3000] ;
    char ss[3000] ;
    int temp;
    while (fgets(s ,3000,in )) {
        sscanf(s, "%s %d",ss ,&temp )  ;
        temp_museum=new_museum(in ,temp ,ss) ;
        museums=add_museum(museums,temp_museum) ;
    }
    fclose(in) ;
    return museums;

}
void free_node (node_t* root) {
    if(root==NULL) return ;
    free_node(root->left) ;
    free_node(root->right) ;
    int i =0 ;
     free(root->name) ;
     reservation_t *head ,*temp;
     head=root->head ;
     for (i=0 ; i<root->res_number ; i++) {
        free(head->museum_name);
        free(head->reservator_name) ;
        temp=head ;

        head=head->next ;
        free(temp) ;
     }
     free(head) ;
    free(root) ;


}
void free_museum (museum_t* museum) {
    if(museum==NULL) return ;
    free_museum(museum->next) ;
    free(museum->museum_name) ;
    int i ;
    for (i=0 ; i<365; i++) {
    day_t day=museum->days[i] ;
        free(day.max_people) ;
        free(day.slots);

    }
    free(museum->days) ;

    free(museum) ;
}
void close_program(museums_t* museums) {

    free_node(museums->root) ;
    free_museum(museums->museum) ;
    free(museums) ;



exit(0) ;

}

#endif // MUSEUMS_H_INCLUDED
