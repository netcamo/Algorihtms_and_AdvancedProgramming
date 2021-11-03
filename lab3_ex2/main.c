#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


typedef struct rectangle {
    char identifier[5] ;
    float x[2] ;
    float y[2] ;
    float perimeter ;
    float area ;
    int k;
}rectangle ;

int main(int argc ,char* argv[])
{
    FILE* input=fopen(argv[1], "r") ;
    FILE* out_area=fopen(argv[2],"w") ;

    FILE* out_perimeter=fopen(argv[3],"w") ;

    int rectangle_count=0 ;
    char s[200] ;
    char temp_name[5] ;
    float temp_x ,temp_y ;
    rectangle rectangles[101] ;
     int i=0 ,k;
    while (fgets(s,200,input)!=NULL ) {
        int written=0 ;

        if(sscanf(s , "%s %f %f" ,&temp_name ,&temp_x , &temp_y)!=EOF){

            i=0 ;
        for (i=0 ; i<rectangle_count ; i++) {

            if (strcmp(rectangles[i].identifier,temp_name)==0 ) {
            written=1 ;
            k=rectangles[i].k++ ;
            rectangles[i].x[k]=temp_x ;
            rectangles[i].y[k]=temp_y ;
            k++;
            break;
            }

        }



        if (written==0) {
                i=rectangle_count;
                rectangles[rectangle_count].k=0 ;
                k=rectangles[rectangle_count].k++ ;
            rectangles[rectangle_count].x[k]=temp_x ;
            rectangles[rectangle_count].y[k]=temp_y ;
            k++;
            strcpy(rectangles[rectangle_count].identifier,temp_name) ;
            rectangle_count++ ;
        }



      //  printf("%s %f %f %f %f %d\n" ,rectangles[i].identifier,rectangles[i].x[0],rectangles[i].x[1],rectangles[i].y[0],rectangles[i].y[1],rectangles[i].k);
 }

    }

float en,uzun ;

for (i=0 ; i<rectangle_count ; i++) {
    en=fabs(rectangles[i].x[0]-rectangles[i].x[1]);
    uzun=fabs(rectangles[i].y[0]-rectangles[i].y[1] );
    rectangles[i].perimeter=2*(en+uzun) ;
    rectangles[i].area=en*uzun ;
}



    rectangle temp ;

    int j=0 ;

for(i=0 ; i<rectangle_count ; i ++) {
    for(j=0 ; j<rectangle_count-1 ; j++) {
        if (rectangles[j].area<rectangles[j+1].area) {
            temp=rectangles[j];
            rectangles[j]=rectangles[j+1] ;
            rectangles[j+1]=temp ;
        }

    }
}

for (i=0 ; i<rectangle_count ; i++) {
    fprintf(out_area ,"%s\n",rectangles[i].identifier) ;
}


for(i=0 ; i<rectangle_count ; i ++) {
    for(j=0 ; j<rectangle_count-1 ; j++) {
        if (rectangles[j].perimeter<rectangles[j+1].perimeter) {
            temp=rectangles[j];
            rectangles[j]=rectangles[j+1] ;
            rectangles[j+1]=temp ;
        }

    }
}

for (i=0 ; i<rectangle_count ; i++) {
    fprintf(out_perimeter ,"%s\n",rectangles[i].identifier) ;
}

    fclose(input) ;
    fclose(out_area) ;
    fclose(out_perimeter) ;
    return 0;
}
