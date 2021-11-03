#include "treePrivate.h"

#define FIND 0

static node_t *myAlloc (void);


data_t getData (node_t *node)
{
  return (node->val);
}
node_t *insert_reg (node_t *rp,data_t data)
{
  node_t *p;

  /* Empty Tree: Found Position */
  if (rp == NULL) {
    p = myAlloc();
    p->val = data;
    p->left_reg = p->right_reg = NULL;
    return (p);
  }

  /* Duplicated Element */
  if (compare_reg_num(data, rp->val) == 0) {
    return (rp);
  }

  if (compare_reg_num(data, rp->val) < 0) {
    /* Insert on the left */
    rp->left_reg = insert_reg(rp->left_reg, data);
  } else {
    /* Insert on the right */
    rp->right_reg = insert_reg(rp->right_reg, data);
  }

  return (rp);
}
node_t *insert_name (node_t *rp,data_t data)
{
  node_t *p;

  /* Empty Tree: Found Position */
  if (rp == NULL) {
    p = myAlloc();
    p->val = data;
    p->left_name = p->right_name = NULL;
    return (p);
  }

  /* Duplicated Element */
  if (compare_name(data, rp->val) == 0) {
    return (rp);
  }

  if (compare_name(data, rp->val) < 0) {
    /* Insert on the left */
    rp->left_name = insert_name(rp->left_name, data);
  } else {
    /* Insert on the right */
    rp->right_name = insert_name(rp->right_name, data);
  }

  return (rp);
}
static node_t *myAlloc (void)
{
  node_t *p;

  p = (node_t *)malloc(sizeof(node_t));
  if (p == NULL) {
    printf ("Allocation Error.\n");
    exit (1);
  }

  return (p);
}

void writeTree (FILE *fp,node_t *rp,int modo, char* s)
{
  if (rp == NULL) {
    return;
  }

    if(strcmp(s,"REG")==0)
        {

  if (modo == PREORDER) {
    writeData (fp, rp->val);
  }

  writeTree (fp, rp->left_reg, modo,s);

  if (modo == INORDER) {
    writeData(fp, rp->val);
  }

  writeTree (fp, rp->right_reg, modo,s);

  if (modo == POSTORDER) {
    writeData(fp, rp->val);
  }
    }
     else if(strcmp(s,"NAME")==0)
        {

  if (modo == PREORDER) {
    writeData (fp, rp->val);
  }

  writeTree (fp, rp->left_name, modo,s);

  if (modo == INORDER) {
    writeData(fp, rp->val);
  }

  writeTree (fp, rp->right_name, modo,s);

  if (modo == POSTORDER) {
    writeData(fp, rp->val);
  }
    }

  return;
}


void freeTree (node_t *rp)
{
  if (rp == NULL) {
    return;
  }

  freeTree (rp->left_name);
  freeTree (rp->right_name);
    data_t d ;
    d=rp->val ;
    free(d.course);
    free(d.date);
    free(d.name);
  free (rp);

  return;
}
void readTree (FILE *fp , node_t** root_name , node_t** root_reg  )
{

  data_t d;
    *root_name=NULL;
    *root_reg=NULL ;


  while (readData (fp, &d) != EOF) {
    *root_name = insert_name(*root_name,d) ;

    *root_reg= insert_reg(*root_reg,d) ;
  }
return ;
}



node_t *searchR (  node_t *rp,  int data  )
{
  if (rp==NULL || rp->val.code-data==0)
    {
            if(rp==NULL)  return rp ;
            else {
                writeData(stdout ,rp->val) ;
                return ;
            }
    }

  if (data-rp->val.code < 0)
    return (searchR (rp->left_reg, data));
  else
    return (searchR (rp->right_reg, data));
}



node_t *searchS (  node_t *rp,  char *data  )
{
    //writeData(stdout ,rp->val) ;
   // puts("---") ;
  if (rp==NULL || strcmp(rp->val.name,data)==0)
    {
        if(rp==NULL)  { puts("No such thing!") ;
                return rp ; }
            else {
                writeData(stdout ,rp->val) ;
                return rp;
            }

    }

  if (strcmp(rp->val.name,data) < 0)
    return (searchS (rp->right_name, data));
  else
    return (searchS (rp->left_name, data));
}


