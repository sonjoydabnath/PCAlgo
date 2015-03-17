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
int dp[100][100];
int lcs( char *X, char *Y, int m, int n )
{
    if (m == 0 || n == 0)
        return 0;
    if(dp[m][n]!=-1)return dp[m][n];
    if(X[m-1] == Y[n-1])
        return dp[m][n]=1 + lcs(X, Y, m-1, n-1);
    else
        return dp[m][n]=max(lcs(X, Y, m, n-1), lcs(X, Y, m-1, n));
}

void printLCS(char* X,char* Y,int i,int j)          ///this function print the LCS string
{
    if (i==0 || j==0)
        return;
    if (X[i-1]==Y[j-1])
    {
        printLCS(X,Y,i-1,j-1);
        cout<<X[i-1];
    }
    /*else if (dp[i][j]==dp[i-1][j])
        printLCS(i-1,j);
    else
        printLCS(i,j-1);*/

        else if(dp[i][j-1]>dp[i-1][j])
            printLCS(X,Y,i,j-1);
        else printLCS(X,Y,i-1,j);
}

int main()
{
    int len1,len2,i;
    char a[100],b[100];
    memset(dp,-1,sizeof dp);
    while(gets(a))
    {
        len1=strlen(a);
        gets(b);
        len2=strlen(b);
        cout<<"LCS Of 2 string "<<lcs(a,b,len1,len2)<<endl;
        printLCS(a,b,len1,len2);                ///call for print the LCS seriese.
        puts("");
    }
}
