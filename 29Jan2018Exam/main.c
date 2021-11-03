
#include "temp_work.h"


int main()
{

    cdb_t *cdb ;
    cdb=load_file("input.txt") ;
    print_everything(cdb);
    solve (cdb) ;




    return 0;
}
