#include<iostream>
#include<fstream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<vector>

using namespace std;

int n;

int mis(vector<bool> f, int i)
{
    //if (i > n)
    //return 0;
    /*else*/
    if (i == n)
    {
        for(int j = 0; j < n; j += 1)
            cout << f[j] << " ";
        cout << endl;
        return 1;
    }

    f[i] = true;
    int a = mis(f, i + 1);

    f[i] = false;
    int b = mis(f, i + 1);

    return a + b;
}

int main()
{
    while(cin>>n)
    {
        vector<bool> f(n);
        int m = mis(f, 0);
        cout << "Total: " << m << endl;
    }
}
