#include "treePublic.h"

#define OK 1
#define KO 0

int
main (
  void
   )
{
  node_t *root, *tmp;
  data_t d;
  int i ;
  int retValue, end = 0;
  char row[MAXC];
  FILE *fp = NULL;

  root = NULL;
  root = createEmptyTree();
  int* count_child_array[3]={0,0,0} ;

  while (!end) {

    fprintf (stdout, "User selection\n");
    fprintf (stdout, "\t1) Insert one single node\n\t2) Cancel one single node\n\t3) Search a node\n");
    fprintf (stdout, "\t4) Print BST on stdout\n\t5) Write BST on file\n\t6) Read BST from file\n");
    fprintf (stdout, "\t7) Compute min and max\n\t8) End\n\t9) find children array\n\t10) Calculate level array\n\t");
    fprintf (stdout, "11) CountPath\n\t12) CountPath between 2 keys\n\t");
    scanf ("%s", row);

    switch (atoi(row)) {

      case 1:
        fprintf (stdout, "data: ");
	retValue = readData (stdin, &d);
        if (retValue==0) {
          fprintf (stderr, "Input erro.\n");
          exit (0);
        }
	root = insert (root, d);
	break;

      case 2:
        fprintf (stdout, "data: ");
	retValue = readData (stdin, &d);
        if (retValue==0) {
          fprintf (stderr, "Input erro.\n");
          exit (0);
        }
	root = delete (root, d);
	break;

      case 3:
        fprintf (stdout, "data: ");
	retValue = readData (stdin, &d);
        if (retValue==0) {
          fprintf (stderr, "Input error.\n");
          exit (0);
        }

	tmp = searchI (root, d);
	if (tmp != NULL) {
	  fprintf (stdout, "Iterative Search: Found -> ");
          writeData (stdout, getData(tmp));
	} else {
	  fprintf (stdout, "Iterative Search: Not Found\n");
        }
	tmp = searchR (root, d);
	if (tmp  != NULL) {
	  fprintf (stdout, "Recursive Search: Found -> ");
          writeData (stdout, getData(tmp));
	} else {
	  fprintf (stdout, "Recursive Search: Not Found\n");
        }
	break;

      case 4:
	writeTree (stdout, root, INORDER);
	break;

      case 5:
	fprintf (stdout, "File Name: ");
	scanf ("%s", row);

        if (strcmp (row, "stdout") == 0) {
          fp = stdout;
        } else {
   	  fp = fopen (row, "w");
        }

        if (fp == NULL) {
         fprintf (stderr, "Error Opening File %s\n", row);
         break;
	}

	writeTree (fp, root, PREORDER);

        if (strcmp (row, "stdout") != 0) {
	  fclose(fp);
	}
	break;

      case 6:
	fprintf (stdout, "File Name: ");
	scanf ("%s", row);

	fp = fopen (row, "r");
	if (fp == NULL) {
	  fprintf (stderr, "Error Opening File %s\n", row);
	} else {
	  freeTree (root);
	  root = readTree (fp);
	}
	break;

      case 7:
        fprintf (stdout, "Tree minimum iterative: ");
        tmp = treeMinI (root);
        writeData (stdout, getData(tmp));
        fprintf (stdout, "Tree minimum recursive: ");
        tmp = treeMinR (root);
        writeData (stdout, getData(tmp));
        fprintf (stdout, "Tree maximum iterative: ");
        tmp = treeMaxI (root);
        writeData (stdout, getData(tmp));
        fprintf (stdout, "Tree maximum recursive: ");
        tmp = treeMaxR (root);
        writeData (stdout, getData(tmp));
	break;

      case 8:
	end = 1;
	break;
      case 9:
          count_child_array[0]=0;
          count_child_array[1]=0;
          count_child_array[2]=0 ;
            countNode(root ,count_child_array) ;
             i =0;
            for(i=0 ; i<3; i++) {
                printf(" %d ",count_child_array[i]) ;
            }
            puts(" ") ;
        break ;

      case 10:
        puts("") ;
        int height ;
        height=height_of_tree(root) ;
        //printf("%d\n",height) ;
        int* height_arr=malloc(sizeof(int)*(height+1)) ;
         i=0 ;
        for(i=0; i<height+1 ; i++) {
            height_arr[i]=0 ;
        }
        countLevel(root ,height_arr, 0) ;
        puts("----------Height Array!---------") ;
        for(i=0 ; i<height+1 ; i++) {
            printf("%d ",height_arr[i]) ;
        }
        puts("") ;

        free(height_arr) ;
        break ;

      case 11:
          puts("");
        int np=0 ;
        int length=0 ;

        countPath(root ,&np , &length) ;

            printf("NUmber of Paths : %d , Length of paths : %d\n",np, length ) ;
        break ;
      case 12:
                puts("") ;
                int key1,key2 ;
            scanf("%d %d",&key1,&key2) ;
            if(key1>key2) {
                int temp ;
                temp=key1 ;
                key1=key2 ;
                key2=temp ;
            }
            int d =visit(root ,key1,key2) ;
            printf("Distance between %d and %d is : ---   %d\n" , key1, key2 , d);
        break;



      default:
	fprintf (stderr, "Unknown Option.\n");
	break;
    }
  }

  freeTree(root);

  return (OK);
}



