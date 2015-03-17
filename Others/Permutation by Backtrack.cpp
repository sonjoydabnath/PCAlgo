#include<stdio.h>
#include<string.h>
#include<iostream>
#include<vector>
using namespace std;
bool taken[30]= {0};
int len,cnt=0;
vector< char > result;
void permut(char *str)
{
    if(result.size()==len)
    {
        for(int i=0; i<len; i++)
            cout<<result[i];
        puts("");
    }
    for(int i=0; i<len; i++)
    {
        if(taken[i]==0)
        {
            taken[i]=1;
            result.push_back(str[i]);
            permut(str);
            taken[i]=0;
            result.pop_back();
        }
    }
}
int main()
{
    char str[10];
    int kase;
    cin>>kase;
    getchar();
    while(kase--)
    {
        gets(str);
        len=strlen(str);
        permut(str);
        puts("");
    }
}
