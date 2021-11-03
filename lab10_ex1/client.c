#include "treePublic.h"
//#include "treePrivate.h"
#define OK 1
#define KO 0

int main(void)
{
  struct node *root_name,*root_reg, *tmp;
  data_t d;
  int  end = 0;
  char row[MAXC];
  FILE *fp = NULL;
    root_name=NULL ;
    root_reg=NULL ;
    tmp=NULL ;


  while (!end) {

    fprintf (stdout, "\n\nUser selection\n");
    fprintf (stdout, "\t1) Insert one single node\n\t2) Search a node with Register_number\n\t3) Search a node with name_surname\n");
    fprintf (stdout, "\t4) Print BST on stdout\n\t5) Write BST on file\n\t6) Read BST from file\n");
    fprintf (stdout, "\t8) End\n\t> ");
    scanf ("%1s", row);
    puts("\n\n");

    switch (atoi(row)) {

        case 1 :
            readData(stdin, &d) ;
            writeData(stdout, d) ;
            root_name=insert_name(root_name,d) ;
            root_reg=insert_reg(root_reg ,d) ;
            break;
        case 4 :
            puts("By NAME\n") ;
            writeTree (stdout, root_name, INORDER,"NAME");
            puts("By REG :\n");
            writeTree (stdout, root_reg, INORDER,"REG");
            puts("\nEnd of printing") ;
            break;

        case 6 :


                fp = fopen ("lab10-input.txt", "r");
                if (fp == NULL) {
                  fprintf (stderr, "Error Opening File %s\n", row);
                } else {
                  freeTree (root_name);
                  readTree (fp, &root_name, &root_reg);

                }
             break;

        case 2 :
            puts("") ;
            int z ;
            scanf("%d",&z) ;
            tmp= (node_t*) searchR(root_reg , z) ;
                if(tmp==NULL) {
                    puts("NO such thing!") ;
                 }

            break;
        case 3:

            puts("") ;
            char name[MAXC] ;
            char surname[MAXC] ;
            scanf("%s %s",surname,name) ;

            strcat(surname," ") ;
            strcat(surname,name) ;
            tmp = searchS(root_name, surname) ;
            break ;
        case 5:
            puts("Enter FIlename") ;
            char s[MAXC] ;
            scanf("%s",s) ;
            FILE* in=fopen(s,"w") ;
            writeTree(in,root_name,INORDER,"NAME") ;
            fclose(in) ;
            break;
        default:
            break;

    }
  }

//  freeTree(root);

  return (OK);
}



