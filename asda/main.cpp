#include <iostream>
using namespace std;
int main()
{
    long long n,m,i,j,maksi=1,t=1;
    long long maks=-9223372036854775806;


    cin>>n>>m;

    long long a[n][m];

    for(i=0; i<n; i++)
    {
        t=1;
        for(j=0; j<m; j++)
        {
            cin>>a[i][j];
            t=t*a[i][j];

        }
        if(t>=maks) {maksi=i+1;maks=t;}

    }
    cout<<maksi;

    return 0;
}
