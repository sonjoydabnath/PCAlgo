

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
#define ULL unsigned long long
using namespace std;
ULL calc(ULL a,int n,int m)
{
    if(n==1)
        return a;
    if(n%2==0)
        return calc(a*a%m,n/2,m);
    else
        return (a*calc(a*a%m,n/2,m))%m;
}
int main()
{
    int a,n,m;
    while(cin>>a>>n>>m)
    cout<<calc(a,n,m)<<endl;
}

