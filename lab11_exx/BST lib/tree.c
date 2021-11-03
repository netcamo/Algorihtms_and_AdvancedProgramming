#include "treePrivate.h"

#define FIND 0

static node_t *myAlloc (void);

data_t getData (node_t *node)
{
  return (node->val);
}

node_t *createEmptyTree (void)
{
  return (NULL);
}


node_t *searchR (node_t *rp,  data_t data  )
{
  if (rp==NULL || compare(rp->val, data)==0)
    return (rp);

  if (compare(data, rp->val) < 0)
    return (searchR (rp->left, data));
  else
    return (searchR (rp->right, data));
}

node_t *insert (node_t *rp,  data_t data  )
{
  node_t *p;


  /* Empty Tree: Found Position */
  if (rp == NULL) {
    p = myAlloc();

    p->val.credit_passed=data.credit_passed;
    p->val.credit_loaded=data.credit_loaded;
    p->val.lastname=strdup(data.lastname);
    p->val.register_number=strdup(data.register_number);

    p->left = p->right = NULL;
    return (p);
  }

  /* Duplicated Element */
  if (compare(data, rp->val) == 0) {
    return (rp);
  }

  if (compare(data, rp->val) < 0) {
    /* Insert on the left */
    rp->left = insert (rp->left, data);
  } else {
    /* Insert on the right */
    rp->right = insert (rp->right, data);
  }

  return (rp);
}


node_t *readTree (FILE *fp)
{
  node_t *rp;
  data_t d;

  rp = createEmptyTree ();

  while (readData (fp, &d) != EOF) {
    rp = insert (rp, d);
  }

  return (rp);
}

void freeTree (node_t *rp)
{
  free(rp->val.lastname) ;
  free(rp->val.register_number) ;
  if (rp == NULL) {
    return;
  }

  freeTree (rp->left);
  freeTree (rp->right);
  free (rp);

  return;
}

void writeTree (FILE *fp,node_t *rp,int modo)
{
  if (rp == NULL) {
    return;
  }

  if (modo == PREORDER) {
    writeData (fp, rp->val);
  }

  writeTree (fp, rp->left, modo);

  if (modo == INORDER) {
    writeData(fp, rp->val);
  }

  writeTree (fp, rp->right, modo);

  if (modo == POSTORDER) {
    writeData(fp, rp->val);
  }

  return;
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

 void bst2hash (node_t *rp,ST st ) {

    if(rp==NULL) return ;

    bst2hash(rp->left,st) ;

    node_t* tmp ;
    data_t data;
    tmp=rp ;
    data=rp->val;
    Item item;
    struct item it;
    item=ITEMset(data.register_number,data.lastname,data.credit_passed,data.credit_passed);
    //it.lastname=strdup(rp->val.lastname) ;
    //it.register_number=strdup(rp->val.register_number);
    //it.credit_loaded=rp->val.credit_loaded;
    //it.credit_passed=rp->val.credit_passed;
    //item=&it ;
    STinsert(st,item) ;




    bst2hash (rp->right, st);


return ;

}




int listAndBST (link list, node_t *rp)
 {

    link go =list ;
        node_t *an;
    while(go!=NULL) {

        data_t temp ;
        temp.credit_loaded=go->item->credit_loaded ;
        temp.credit_passed=go->item->credit_passed;
        temp.lastname=strdup(go->item->lastname) ;
        temp.register_number=strdup(go->item->register_number) ;
        an  = searchR(rp,temp) ;
        if(an==NULL) {puts("error");}
        else {
            temp=getData(an) ;
            writeData(stdout,temp) ;
        }


        go=go->next;
    }




 }
