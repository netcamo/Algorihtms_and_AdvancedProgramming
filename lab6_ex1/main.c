#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct word_list{
struct word_list *next ;
char* word;
int freq ;

}word_list;

word_list* read_file () ;
void write_file(word_list *head) {
    word_list *go ;
    FILE* out=fopen("output.txt","w") ;

    for(go=head; go!=NULL ; go=go->next) {
        fprintf(out,"%s %d\n" , go->word , go->freq) ;
    }

    fclose(out) ;
return ;
}

int main()
{
    word_list* words ;

    words =read_file () ;

    write_file(words) ;

    return 0;
}

word_list* read_file () {

    FILE* in=fopen("input.txt" ,"r");

    char s[1000] ;
    word_list * head ;
    head=NULL;
    word_list *go ;
    while(fscanf(in ,"%s" , s)!=EOF) {
        //puts("sada") ;

       for (go=head ;go!=NULL && strcmpi(go->word,s)!=0 ; go=go->next){}
     //  go=head ;
       // while(go!=NULL && strcmpi (go->word,s)!=0) {
        //    go=go->next ;
       // }
        //puts("yes") ;
        if (go==NULL) {
            go=malloc(sizeof(word_list)) ;
            //if (go==NULL) {printf("error"); exit(1);}
            go->next=head ;
            go->word=strdup(s) ;
            go->freq=1;
            head=go ;
        }
        else {
              //  printf("%s %s \n",go->word , s) ;

            go->freq++ ;
        }

    }



return head ;

fclose(in) ;
}
