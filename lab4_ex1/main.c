#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
char * word ;
int occurrences ;
}index_t ;
int wo_v[101] ;




int main()
{
    char s[102] ;
    index_t info[101] ;
   // char words[101][22] ;
    char word [20] ;
    FILE* in=fopen("file1","r") ;
    FILE* w_in=fopen("file2","r") ;
    int i=0;
    int n =0 ;
    fscanf(w_in,"%d*c",&n) ;

    for (i=0 ; i<n ; i++) {fscanf(w_in , "%s*c",s) ;

        sscanf(s,"%s",word) ;
        info[i].word=malloc(strlen(s)*sizeof(char)) ;
        strcpy(info[i].word,s) ;

      //  printf("%s  %d\n",info[i].word ,strlen(info[i].word) ) ;
        info[i].occurrences=0 ;

    }
    int word_count=n ;


    while (fscanf(in, "%s" , &s)!=EOF) {
          // printf("%s %d \n",s , strlen(s)) ;
        for (i=0 ; i<word_count ; i++) {
            if (strcmpi(s,info[i].word)==0)
            {  // puts("\nyeah") ;
                info[i].occurrences++ ;
                break ;
            }
        }
    }




    for (i=0 ; i<word_count ; i++) {
        printf("%s has %d occurrence(s) \n", info[i].word,info[i].occurrences) ;
    }


    fclose(w_in) ;
    fclose(in);
    return 0;
}
