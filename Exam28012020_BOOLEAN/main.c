
#include "formula.h"


int main()
{

    char s[1000];
    printf("Enter the name of input FILE: \n") ;
    gets(s) ;
    formula_t *formula=load_file(s) ;
    solve(formula) ;
    dispose(formula);


    return 0;
}
