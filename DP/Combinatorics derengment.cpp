#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
long long dp[100];
long long dereng(int n)
{
    if(n==1)return dp[n]=0;
    if(n==2)return dp[n]=1;
    if(dp[n]==-1)
    return dp[n]=(n-1)*dereng(n-1)+(n-1)*dereng(n-2);
    else return dp[n];
}
int main()
{
    int n;
    memset(dp,-1,sizeof dp);
    while(cin>>n)
    {

        cout<<dereng(n)<<endl;
        cout<<dp[n]<<endl;
    }
}
