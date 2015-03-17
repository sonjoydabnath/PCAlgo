#include <stdio.h>
#include <iostream>
#include <vector>
#define read(input) freopen(input,"r",stdin)
#define write(output) freopen(output,"w",stdout)

using namespace std;

int k,n;
long tmp;
int s[20];
vector<int> result;
bool taken[20]= {0};

void ksubset(int pos)
{
    if ( result.size()==k)
    {
        for (int i = 0; i < k; i++)
            cout << result[i]<<" ";
        cout << endl;
    }

    for (int i = pos; i < n; i++)
    {
        result.push_back(s[i]);
        ksubset(i+1);
        result.pop_back();
    }
}

int main()
{
    cin >>n>>k;
    //write("nCrgen.txt");
    for (int i = 0; i < n; i++)
        cin >> s[i];
    ksubset(0);
    return 0;
}
/*
puts("app possible subsets:");
k=n;
while(k)
{
    ksubset(0);
    k--;
}
return 0;
*/


