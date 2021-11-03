

#include "treePrivate.h"

void countNode (node_t *root, int arr[3]){
        if(root==NULL) return ;
    int c=0;
    if( root->left!=NULL) c++;
    if(root->right!=NULL) c++;
    arr[c]++ ;
    countNode(root->left,arr) ;
    countNode(root->right,arr) ;


return;
}

int height_of_tree(node_t *root) {
    if(root==NULL) return -1 ;
    int l=height_of_tree(root->left);
    int r=height_of_tree(root->right);
    return (l>r ? l : r )+1 ;
}

void countLevel (node_t *root, int *array, int l){
                if(root==NULL) return ;
            array[l]++ ;
            countLevel(root->left,array,l+1) ;
            countLevel(root->right, array,l+1) ;
            return;
}




void countPath (node_t * root, int *np, int *length){

 if (root==NULL) {
    return;
  }
  *length = *length + 1;
  if (root->left==NULL && root->right==NULL) {
    *np = *np + 1;
    return;
  }
  countPath (root->left, np, length);
  countPath (root->right, np, length);


}




int dist(node_t *root , int key) {
    if(root==NULL)return 0 ;
   if(root->val ==key) return 0;
   if(key >root->val){
        return dist(root->right ,key)+1 ;
   }
   else return dist(root->left,key)+1 ;
}
int visit (node_t *root, int key1, int key2){
    node_t *go ;
    go=root ;
    while(go!=NULL && ((go->val<key1 && go->val <key2) || (go->val>key1 && go->val>key2)   ) ){
        if(key1<go->val) go=go->left ;
        else go=go->right ;
    }
    int d =0 ;
    d=dist(go ,key1)+dist(go,key2) ;
    return d;
    }
