
#include <stdio.h>
#include <stdlib.h>

#define DX 20
#define DY 30

const int MAXX[] = {10, 10, 15, DX};
const int MAXY[] = {15, 20, 25, DY};

/* structure declaration */
typedef struct {
  int x;
  int y;
} pack_t;

/* function prototypes */
pack_t *loadPackage(int *);
void mark(int [][DY], int, int, int, int, int);
int place_recur(int [][DY], int, int, pack_t *, int, int);
int check(int [][DY], int, int, int, int, int, int);
void printSolution(int [][DY], int, int);
FILE *util_fopen(char *name, char *mode);
void *util_malloc(int size);

/*
 *  main program
 */
int main(void)
{
  int truck[DX][DY], i, num, ok=0;
  pack_t *packages;

  /* load the input file and initialize the truck */
  packages = loadPackage(&num);
  mark(truck, 0, 0, DX, DY, 0);

  /* look for the solution, if any */
  for (i=0; i<4 && !ok; i++) {
    ok = place_recur(truck, MAXX[i], MAXY[i], packages, num, 0);
    if (ok) {
      printf("The %c-type truck must be used:\n", 'A'+i);
      printSolution(truck, MAXX[i], MAXY[i]);
    }
  }
  if (!ok) {
    printf("No available truck can be used!\n");
  }

  free(packages);
  return EXIT_SUCCESS;
}

/*
 *  load the package file contents
 */
pack_t *loadPackage(int *num)
{
   pack_t *packages;
   char name[20];
   FILE *fp;
   int i;

   printf("Input file name: ");
   scanf("%s", name);
   fp = util_fopen(name, "r");

   fscanf(fp, "%d", num);
   packages= (pack_t *)util_malloc((*num) * sizeof(pack_t));
   for (i=0; i<*num; i++) {
     fscanf(fp, "%dx%d", &packages[i].x, &packages[i].y);
   }
   fclose(fp);
   return packages;
}

/*
 * mark some positions of the truck with a given id
 */
void mark(int truck[][DY], int x, int y, int dimX, int dimY, int id)
{
  int i, j;

  for (i=x; i<x+dimX; i++) {
    for (j=y; j<y+dimY; j++) {
      truck[i][j] = id;
    }
  }
}

/*
 *  place the set of packages into the truck, recursive function
 */
int place_recur(int truck[][DY], int maxX, int maxY,
                pack_t *packages, int num, int id)
{
  int i, j, x, y;

  if (id == num) {
    return 1;
  }

  for (i=0; i<maxX; i++) {
    for (j=0; j<maxY; j++) {
      x = packages[id].x;
      y = packages[id].y;
      if (check(truck, maxX, maxY, i, j, x, y)) {
        mark(truck, i, j, x, y, id+1);
        if (place_recur(truck, maxX, maxY, packages, num, id+1)) {
          return 1;
        }
        mark(truck, i, j, x, y, 0);
      }

      if (check(truck, maxX, maxY, i, j, y, x)) {
        mark(truck, i, j, y, x, id+1);
        if (place_recur(truck, maxX, maxY, packages, num, id+1)) {
          return 1;
        }
        mark(truck, i, j, y, x, 0);
      }
    }
  }

  return 0;
}

/*
 * check whether a given package can be placed in a given position
 */
int check(int truck[][DY], int maxX, int maxY, int x, int y, int dimX, int dimY)
{
  int i, j;

  if (x+dimX>maxX || y+dimY>maxY) {
    return 0;
  }

  for (i=x; i<x+dimX; i++) {
    for (j=y; j<y+dimY; j++) {
      if (truck[i][j] != 0) {
        return 0;
      }
    }
  }

  return 1;
}

/*
 *  print the final disposition on screen
 */
void printSolution(int truck[][DY], int maxX, int maxY)
{
  int i, j;

  for (i=0; i<maxX; i++) {
    for (j=0; j<maxY; j++) {
      if (truck[i][j] == 0) {
        /* just for a better printing */
        printf(".");
      } else {
        printf("%d", truck[i][j]);
      }
    }
    printf("\n");
  }
}

/*
 *  fopen (with check) utility function
 */
FILE *util_fopen(char *name, char *mode)
{
  FILE *fp=fopen(name, mode);
  if (fp == NULL) {
    printf("Error opening file %s.\n", name);
    exit(EXIT_FAILURE);
  }
  return fp;
}

/*
 *  malloc (with check) utility function
 */
void *util_malloc(int size)
{
  void *ptr=malloc(size);
  if (ptr == NULL) {
    printf("Memory allocation error.\n");
    exit(EXIT_FAILURE);
  }
  return ptr;
}
