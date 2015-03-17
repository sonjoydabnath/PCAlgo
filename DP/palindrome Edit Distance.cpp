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
char str[1005],str2[1005];
int dp[1005][1005];
int palindrome(int len)
{
    int i,j,cost;
    for(i=0; i<len; i++)
        dp[i][0]=i,dp[0][i]=i;

    for(i=1; i<=len; i++)
        for(j=1; j<=len; j++)
        {
            if(str[i-1]==str2[j-1])
                cost=0;
            else cost=1;
            dp[i][j]=min(dp[i-1][j-1]+cost,min(dp[i-1][j]+1,dp[i][j-1]+1));
        }
    return dp[len][len];
}
int main()
{
    int a,tc,i,j;

    cin>>tc;
    for(int kase=1; kase<=tc; kase++)
    {
        cin>>str;
        int sz=strlen(str);
        for(i=sz-1,j=0; j<sz; i--,j++)
            {
                str2[j]=str[i];
                //cout<<i<<" "<<j<<endl;
            }
        str[j]='\0';
        str2[j]='\0';
        //cout<<str<<endl;
        //cout<<str2<<endl;

        int ans=palindrome(j);
        //ans=-ans%2+ans*2;
        cout<<"Case "<<kase<<": "<<ans/2<<endl;

    }
}
