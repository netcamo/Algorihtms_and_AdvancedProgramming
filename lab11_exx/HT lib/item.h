#ifndef _DATO_INCLUDED
#define _DATO_INCLUDED

#define MAXST 10

typedef struct item* Item;
typedef char *Key;

struct item {

char *register_number ;
char *lastname;
int  credit_loaded;
int  credit_passed ;


 };

Item ITEMscan(FILE*);
void ITEMshow(FILE*,Item data);
int ITEMcheckvoid(Item data);
Item ITEMsetvoid();
Key KEYscan();
int KEYcompare(Key k1, Key k2);
Key KEYget(Item data);
#endif

