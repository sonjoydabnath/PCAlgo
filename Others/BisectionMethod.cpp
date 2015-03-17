/* Bismillahir Rahmanir Rahim */
/*Coder: Ahmad Faiyaz*/

/* Bisection Method */

#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;
double EPS = .0001;

double f(double x)
{
    return x*x; //y= x^2
}

bool equal (double a,double b)
{
    if(abs(a-b) > EPS)
    return false;
    else
    return true;
}

double bisection(double lo,double hi,double val)
{
    while(abs(hi-lo) > EPS) // যদি লিমিট দুটির মধ্যে difference খুবি ছোট না হয় তাহলে লুপ চলবে
    {
        double mid= (hi+lo)/2; //মধ্যমা নির্ধারণ
        double y= f(mid);
        bool isequal= equal(y,val); //  y এর মান আর আমরা যেই মান এর বর্গমূল চাচ্ছি তা সমান কিনা দেখছি।
        if(isequal){
            return mid;
        }
        if(y > val) //y এর মান বেশি হইসে  ,আমরা যেই মান দিয়ে check করছি তার থেকে
        {
            hi=mid;
        }
        else
        {
            lo=mid;
        }
    }
}

using namespace std;
int main()
{
    cout<<"Square Root by the bisection: "<<bisection(0,16,9)<<endl;
    cout<<"Square Root by the sqrt() method in c++: "<<sqrt(9)<<endl;
    return 0;
}
