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
int lcs[101][101];
int LCS(int *A,int *B,int m,int n)
{
        int i,j;
        m++;
        n++;
        for(i = 0; i < m; i++)
            lcs[i][0] = 0;
        for(j = 0; j < n; j++)
            lcs[0][j] = 0;

        for(i = 1; i < m; i++)
        {
            for(j = 1; j < n; j++)
            {
                if(A[i-1] == B[j-1])
                    lcs[i][j] = lcs[i-1][j-1]+1;
                else if(lcs[i][j-1]>lcs[i-1][j])
                    lcs[i][j] = lcs[i][j-1];
                else
                    lcs[i][j] = lcs[i-1][j];
            }
        }
        return lcs[m-1][n-1];
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
        cout<<"LCS Of 2 integer array "<<LCS(a,b,n,m)<<endl;
        //cout<<"LCS Of 2 integer array "<<lcsITERET(a,b,n,m)<<endl;
    }
}
