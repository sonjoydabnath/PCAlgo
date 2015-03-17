#include <iostream>
#include <cmath>
using namespace std;

int phi_f(int n)
{
    int result = n;
    if (n == 1||n==0)
        return 0;
    if (n % 2 == 0) {
        while (n % 2 == 0)
            n /= 2;
        result -= result / 2;
    }
    for (int i = 3, sq = sqrt(n); i <= sq; i += 2) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

#define MAX_N 5000005
int phi[MAX_N];
void sievePhi () {
    phi [1] = 0;
    for (int i = 2; i < MAX_N; ++i)
        if (phi [i] == 0) {
            phi [i] = i - 1;
            for (int j = 2 * i; j < MAX_N; j += i) {
                if (phi [j] == 0) phi [j] = j;
                phi [j] = phi [j] / i * (i - 1);
            }
        }
}


int main()
{
    int num;
    sievePhi();
    while(cin>>num) {
        cout<<phi_f(num)<<endl;
        cout<<phi[(num)]<<endl;
    }
}

