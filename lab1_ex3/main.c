#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(int argc, char* argv[])
{
    FILE* fin =fopen(argv[2] ,"r") ;
    FILE* fout= fopen (argv[4],"w") ;

    char s[102] ;
    char s1[100] ;
    char s2[100] ;
    int i , j,k ;
    strcpy(s1,argv[1]) ;
    strcpy(s2,argv[3]) ;
     while (fgets(s,102 ,fin)!=NULL) {
        for (i=0 ; i<strlen(s) ; i++) {
            if (s[i]!=s1[0]){fprintf(fout,"%c",s[i]);}
            else {
                int match=1 ;

                for (j=i , k=0 ; j<strlen(s) && k<strlen(s1) ; j++, k++)  {
                    if (s[j]!=s1[k]) {
                        match=0 ;
                        break;
                    }

                }
                if (k<strlen(s1)) match=0 ;

                if (match==0) fprintf(fout,"%c",s[i]);
                else {
                    fprintf(fout,"%s",s2) ;
                    i=i+strlen(s1)-1 ;
                }


            }


        }




    }






    fclose(fin);
    fclose(fout) ;

    return  0 ;
}
