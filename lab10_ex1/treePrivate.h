#ifndef _TREE_PRIVATE_INCLUDED
#define _TREE_PRIVATE_INCLUDED

#include "treePublic.h"

struct node {
  data_t val;
  struct node *left_name;
  struct node *right_name;
  struct node *left_reg;
  struct node *right_reg;

};

#endif

