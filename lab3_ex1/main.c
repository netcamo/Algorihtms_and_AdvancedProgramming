#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int wo_v[101] ;

int main()
{
    char s[102] ;
    char words[101][22] ;

    FILE* in=fopen("flie1","r") ;
    FILE* w_in=fopen("file2","r") ;
    int i=0;
    while(fgets(s,200,w_in)!=NULL) {
        sscanf(s,"%s",&words[i]) ;
        printf("%s\n",words[i]) ;
        i++;
    }
    int word_count=i ;


    while (fscanf(in, "%s" , &s)!=EOF) {

        for (i=0 ; i<word_count ; i++) {
            if (strcmpi(s,words[i])==0)
            {
                wo_v[i]+=1 ;
                break ;
            }
        }
    }




    for (i=0 ; i<word_count ; i++) {
        printf("%s has %d occurrence(s) \n", words[i],wo_v[i]) ;
    }


    fclose(w_in) ;
    fclose(in);
    return 0;
}
