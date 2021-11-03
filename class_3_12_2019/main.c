#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef  struct  let_num
{
    char c ;
    int  num ;
} let_num ;

void unificator(char* s,let_num letters[10 ],int* let_count)
{
    int let_countt=*let_count ;

    int i =0 ;
    int go=0;
    int flag=0 ;
    for (i=0 ; i<strlen(s) ; i++)
    {
        flag=0 ;
        for (go=0; go<let_countt ; go++)
        {
            if (letters[go].c==s[i])
            {
                flag=1 ;
                break ;
            }
        }
        if (flag==0)
        {
            letters[let_countt].c=s[i] ;
            let_countt++ ;
        }

    }

    *let_count =let_countt;
    return ;
}

int convert ( char *s, let_num letters[10], int let_count)
{

    int n =strlen(s) ;
    int sum=0;
    int go,i,j ;
    for (i=0; i<n ; i++)
    {

        for (go=0; go<let_count; go++)
        {
            if (s[i]==letters[go].c)
                break ;
        }
        sum=sum*10+letters[go].num;


    }
    return sum ;

}

int check_sol (char* s1, char *s2,char *s3, let_num letters[10], int let_count)
{

    int a1,a2, a3 ;
    int i, j, go ;
    a1=convert(s1, letters,let_count) ;
    a2=convert(s2, letters,let_count) ;
    a3=convert(s3, letters,let_count) ;

    puts("------------CHECK----------") ;
    printf("%d %d %d\n", a1,a2,a3) ;
    for(i=0 ; i<let_count ; i++)
    {
        printf("%c - %d  :  ",letters[i].c, letters[i].num) ;
    }
    puts("----------ENDCHECK-------") ;

    if(a1+a2==a3)
    {



        printf("%d + %d = %d \n",a1,a2,a3) ;

        return 1 ;
    }


    else
        return 0 ;





}

void test (char* s1, char *s2, char *s3,let_num letters[10], int let_count)
{


    int i =0 ;
    int d ;
    for (i=0 ; i<let_count ; i++)
    {
        printf("which one %c is ?\n", letters[i].c) ;
        scanf("%d",&d) ;
        letters[i].num=d;
    }
    if( check_sol(s1,s2,s3,letters,let_count) )
    {
        printf("Solution is correct!\n") ;
        return ;
    }
    printf("Solution is not correct!\n") ;
    return ;


}


int solve  (char *s1, char *s2, char *s3, let_num letters[10], int let_count, int array[11], int k)
{

    if (k==let_count)
    {
        puts("flag") ;
        if( check_sol(s1,s2,s3,letters, let_count))
        {

            puts("Tapdim solution :") ;
            return 1;
        }
        else
            return 0 ;
    }

    int i ;
    for ( i=9;  i>=0; i--)
    {
        if(array[i]==0)
        {
            array[i]=1;
            letters[k].num=i ;
            if ( solve (s1, s2, s3,letters,let_count,array,k+1 ) )
                return 1 ;
            array[i]=0 ;
        }
    }


    return 0;

}


int main ( int argc, char* argv[])
{


    let_num letters[10] ;
    int let_count=0 ;
    int i,go ;
    char s1[11],s2[11],s3[11] ;
    int array[11] ;
    for (i=0 ; i<11; i++)
    {
        array[i]=0 ;
    }
    scanf("%s %s %s",s1,s2,s3) ;
    unificator(s1, letters,&let_count);
    unificator(s2, letters,&let_count) ;
    unificator(s3,letters,&let_count) ;
    printf ("1) test Solution :\n2) Find Solution\n ?") ;
    int option ;
    scanf("%d",&option) ;
    switch (option)
    {
    case (1) :
        test (s1, s2,s3, letters,let_count) ;

        break ;
    case (2) :

        solve(s1,s2,s3,letters,let_count,array,0);
        break ;
    default:
        break ;

    }

}






