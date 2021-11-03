#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct string {
char *str ;
}string;

string* read_input (int n , FILE* in ) ;
void sort_strings (string* strings , int n ) ;
void write_file (FILE* out , int n , string* strings) ;

int main()
{
    char input_name[20],output_name[20] ,s[101];
    printf("input and output filenames : \n") ;
    scanf("%s %s",input_name , output_name) ;
    FILE* in =fopen(input_name, "r") ;
    FILE* out = fopen(output_name,"w") ;
    if (in==NULL||out==NULL) {printf("error opening files!"); exit(1);}
    int n ,i;
    fscanf(in,"%d\n",&n) ;
    string* strings  ;
    strings = read_input(n , in);

    sort_strings(strings , n) ;
    write_file(out , n , strings) ;

            for (i= 0 ; i<n ; i++) {
                free(strings[i].str) ;
            }
            free(strings) ;

fclose(out) ;
    return 0;
}

void write_file (FILE* out , int n , string* strings) {
    int i ;
    fprintf(out,"%d\n",n) ;
    for (i=0 ; i<n ; i++) {
        fprintf(out,"%s\n",strings[i].str);

    }

return ;
}

void sort_strings(string* strings , int n ) {
    int i =0  ;
    int j =0 ;
    string temp ;
   // temp=strings[1];
   // strings[1]=strings[0] ;
    //strings[0]=temp ;



    for (i = 1 ; i <n ; i++) {
      temp =strings[i] ;
      j=i-1 ;
        while(j>=0 &&strcmp(strings[j].str,temp.str)>0) {
            strings[j+1]=strings[j] ;
            strings[j]=temp ;
            j--;
         }
    }

return ;
}

string* read_input (int n , FILE* in ) {
char s[101] ;
int i , j ,k ;
string* strings ;
strings=malloc(sizeof(string)*n) ;
for (i =0 ; i<n &&fgets(s,1000,in)!=NULL ; i++) {
        sscanf(s,"%s",s) ;
        strings[i].str=strdup(s) ;
        //strings[i].str=malloc(sizeof(char)*strlen(s)+1);
        //strcpy(strings[i].str,s) ;
       // printf("strlen of word : strlen of str  %d %d %s\n",strlen(s),strlen(strings[i].str) , s ) ;
    }

fclose(in) ;

return strings ;
}
