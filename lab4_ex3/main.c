#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct cyclist{

char name[31] ;
int identifier ;
int lap_c ;
float *laps ;
float avg ;
}cyclist;


cyclist* read_file (FILE *in , int* z) {
if (in==NULL) {puts("error"); exit(1);}

cyclist* cyclists ;
fscanf(in, "%d*c" , z) ;
int n=*z;
int i=0 ,j;
cyclists=malloc(n*sizeof(cyclist)) ;
int lap_c ;
for (i =0 ; i<n ; i++) {

    fscanf(in ,"%s %d %d*c",cyclists[i].name ,&(cyclists[i].identifier),&(cyclists[i].lap_c) ) ;
    cyclists[i].laps=malloc(cyclists[i].lap_c*sizeof(float)) ;
    lap_c = cyclists[i].lap_c ;
    float sum=0;
    for (j=0 ; j<lap_c ; j++) {
        fscanf(in , "%f",&(cyclists[i].laps[j])) ;
        sum+=cyclists[i].laps[j] ;
    }
    cyclists[i].avg=(sum/((float)cyclists[i].lap_c)) ;



}



fclose(in) ;

return cyclists ;

}
cyclist find_best (cyclist* cyclists , int n) {

    int i =0 ,j;
    int k =0 ;
    for (i =1 ; i<n ;  i ++) {
        if (cyclists[i].avg<= cyclists[k].avg) k=i ;
    }


return cyclists[k] ;

}



int main()
{

    FILE *in =fopen("input.txt", "r") ;
    int n ;

    cyclist* cyclists=read_file(in,&n) ;
    int i , j , k ;
    cyclist best = find_best (cyclists, n) ;
      /*  printf("%s %d %d \n",best.name,best.identifier,best.lap_c) ;
        for (j=0 ; j<best.lap_c ; j ++) {
            printf("%f " ,best.laps[j] );
        }*/
 /*   for (i=0 ; i<n ; i++) {
        printf("%d : %s %d %d \n",i ,cyclists[i].name,cyclists[i].identifier,cyclists[i].lap_c) ;
        for (j=0 ; j<cyclists[i].lap_c ; j ++) {
            printf("%f " ,cyclists[i].laps[j] );

        }
    }
*/
    char s[100] ;
    m:
    while (1) {
        printf("command? ") ;
        scanf("%s",s) ;
        if(strcmp(s,"list")==0) {

                printf("NUmber of Athletes : %d\n",n) ;

            for (i=0 ; i<n ; i++) {
        printf("%d : Name :%s #id :%d #Laps: %d \n",i ,cyclists[i].name,cyclists[i].identifier,cyclists[i].lap_c) ;

     }
        }


        else if (strcmp(s,"details")==0) {
            scanf("%s",s) ;
            int flag=0 ;
            for (i=0 ; i<n ; i++) {

                if (strcmpi(cyclists[i].name,s)==0) {
                    printf("Name: %s #ID: %d \n Times : " , cyclists[i].name, cyclists[i].identifier);
                    for (j=0 ; j< cyclists[i].lap_c;j++) {
                        printf("%f",cyclists[i].laps[j]) ;
                    }
                    puts("") ;
                    flag=1 ;
                    break ;
                }

            }
            if (flag==0) {
                printf("error : there is no cyclist by this name! try again!\n") ;
                goto m;
            }
        }
        else if (strcmp(s,"best")==0) {

            printf("Name: %s #ID: %d #Laps: %d \n",best.name,best.identifier,best.lap_c) ;
        for (j=0 ; j<best.lap_c ; j ++) {
            printf("%f " ,best.laps[j] );

        }
        printf(" \n Avg: %f" , best.avg) ;
        puts("") ;


    }
     else if (strcmp(s,"stop")==0) {

            puts("Program ended!") ;
         break ;
    }
    }


        for (i =0 ; i<n ; i++) {
            free(cyclists[i].laps);
        }
        free (cyclists );
    return 0;
}
