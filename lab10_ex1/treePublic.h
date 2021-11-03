#ifndef _TREE_PUBLIC_INCLUDED
#define _TREE_PUBLIC_INCLUDED

#include "data_struct.h"

#define PREORDER  -1
#define INORDER    0
#define POSTORDER  1

typedef struct node node_t;

data_t getData (node_t *);
void readTree (FILE *fp , node_t** root_name , node_t** root_reg  );
node_t *insert_reg (node_t *rp,data_t data);
node_t *insert_name (node_t *rp,data_t data);
void writeTree(FILE *, node_t *, int,char*);
void freeTree(node_t *);

node_t *searchS (  node_t *rp,  char *data  );

node_t *searchR (  node_t *rp,  int data  );




#endif

