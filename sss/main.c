#include <stdio.h>
#include <stdlib.h>
#include<string.h>


int **mall2(int R);
int findsquare(int  n, int** m, int k, int sum, int *used);
int check(int  n, int** m, int sum);
int check_line( int** m, int sum, int r, int c, int  n);

int main(int argc, char *argv[])
{
    if (argc!=3)
    {
        printf("Command error!");
        exit(1);
    }

    int x=atoi(argv[1]);
    FILE *fout;
    fout=fopen(argv[2], "w");
    int **mat;
    int *used;
    int i, j;
    used=(int *)malloc((x*x+1)*sizeof(int));
    if(used==NULL)
    {
        printf("ERROR ALLOC");
        exit(1);
    }
    for(i=0; i<=x*x; i++)
        used[i]=0;
    mat=mall2(x);

    int sum;
    sum=x*((x*x)+1)/2;
    int r=findsquare(x, mat, 0, sum, used);
    printf("risultato : %d", r);
    if(r==1)
    {

        printf("Matrix found!\n");
        for(i=0; i<x; i++)
        {
            for(j=0; j<x; j++)
            {
                printf("%d  ", mat[i][j]);
            }
            printf(" \n ");
        }
    }
    else
    {
        printf("\nMatrix not found\n");
    }
puts("   ") ;
for(i=0; i<x; i++)
        {
            for(j=0; j<x; j++)
            {
                printf("%d  ", mat[i][j]);
            }
            printf(" \n ");
        }
    free(used);
    for(i=0; i<x; i++)
    {
        free(mat[i]);
    }
    free(mat);
    fclose(fout);
    return 0;
}


int **mall2(int R)
{
    int **m;

    int i,j;
    m=(int**)malloc(R*sizeof(int*));
    if(m==NULL)
    {
        fprintf(stderr, "ERROR ALLOCATING 1!\n");
        exit(EXIT_FAILURE);
    }
    for( i=0; i<R; i++)
    {
        m[i]=(int*)malloc(R*sizeof(int));
        if(m[i]==NULL)
        {
            fprintf(stderr, "ERROR ALLOCATING 2!\n");
            exit(EXIT_FAILURE);
        }
        for(j=0 ; j<R; j++){
            m[i][j]=-1 ;
        }

    }
    return m;
}

int findsquare(int  n, int** m, int k, int sum, int *used)
{

    int i, j, val;
    //printf(" %d\n", k);
    if( k==n*n)
    {

        return check( m, sum, n);
    }

    i=k/n;
    j=k%n;
    for(val=1; val<=n*n;  val++ )
    {

        if(used[val]==0)
        {
            m[i][j]=val;
            //printf("r: %d   c: %d   %d\n", i, j, val);

            if(check_line(m, sum, i, j, n)==0)
            {
                continue;
            }
            used[val]=1;

            if(findsquare(n, m, k+1, sum, used))
            {
                return 1;
            }
            used[val]=0;
        }
    }

    return 0;
}




int check(int  n, int** m, int sum)
{
    int s, i, j;
    puts(" ") ;

    for(i=0; i<n; i++)
    {
        s=0;
        for(j=0; j<n; j++)
        {
            s+=m[i][j];
        }
        if(s!=sum)
        {
            return 0;
        }
    }

    for(j=0; j<n; j++)
    {
        s=0;
        for(i=0; i<n; i++)
        {
            s+=m[i][j];

        }
        if(s!=sum)
        {
            return 0;
        }
    }
    s=0;
    for(i=0; i<n; i++)
    {
        s+=m[i][i];
    }
    if(s!=sum)
    {
        return 0;
    }

    s=0;
    for(i=0; i<n; i++)
    {
        s+=m[i][n-1-i];
    }

    if(s!=sum)
    {
        return 0;
    }

    return 1;
}

int check_line( int** m, int sum, int r, int c, int  n)
{
    int i, x;

    x=0;
    for(i=0; i<=c; i++)
    {
        x+=m[r][i];

    }
    if(c<n-1)
    {
        if(x>sum)
        {

            return 0;
        }
    }
    else
    {
        if(x!=sum)
        {
            return 0;
            printf("b-m\n");
        }
    }

    x=0;
    for(i=0; i<=r; i++)
    {
        x+=m[i][c];
    }
    if(r<n-1)
    {
        if(x>sum)
        {
            return 0;
        }
    }
    else
    {

        if(x!=sum)
        {
            return 0;
        }
    }

    return 1;
}
