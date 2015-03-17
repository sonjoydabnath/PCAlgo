#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

int lcs( int *X, int *Y, int m, int n )
{
    if (m == 0 || n == 0)
        return 0;
    if(X[m-1] == Y[n-1])
        return 1 + lcs(X, Y, m-1, n-1);
    else
        return max(lcs(X, Y, m, n-1), lcs(X, Y, m-1, n));
}


int main()
{
    int n,m,i;
    int a[100],b[100];
    while(cout<<"size of 1st array = ? "&&cin>>n&&n!=0)
    {
        for(i=0; i<n; i++)
            cin>>a[i];
        cout<<"size of 2nd array = ? ";
        cin>>m;
        for(i=0; i<m; i++)
            cin>>b[i];
        cout<<"LCS Of 2 integer array "<<lcs(a,b,n,m)<<endl;
    }
}

