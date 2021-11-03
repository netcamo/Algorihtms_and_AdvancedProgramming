
#include "visitors_bst.h"


int main()
{
    museums_t *museums=load_file("museums.txt");
    char s[3000] ;
    while(1) {
        gets(s) ;
        if (strcmp(s,"stop")==0) {
            close_program(museums) ;
        }
        else if(check_space(s)==0) {
            search_print(museums ,s) ;
        }
        else {
            make_appointment (museums,s) ;
        }
    }

    return 0;
}
