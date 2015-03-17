#include<stdio.h>
#include<math.h>
#define max 1000
char p[max];
void sieve()
{
    long i,j,c=0,x=0;
    for(i=2; i<max; i++)
        p[i]=1;
    for(i=2; i<=sqrt(max); )
    {
        for(j=i+i; j<=max; j+=i)
            p[j]=0;
        i++;
        for( ; !p[i]; i++);
    }
    for(i=0; i<=max; i++)//if(p[i])x++; //This 2 lines for checking the number of primes between 0 & 10000000.
        if(p[i])printf("%d ",i);

}

void sieve2()
{
    int i, j, sqrtN;
    //int i,j,k;
    //primes = (char*) malloc((n+1)*sizeof(char));
    for(i = 0; i<=N; i++)
        primes[i] = 1;
    primes[0]=0;
    primes[1] = 0;
    sqrtN = sqrt(N);
    for(i = 2; i<=sqrtN; i++)
        if(primes[i])
            for(j=i*i; j<=N; j+=i)
                primes[j] = 0;

}

int main()
{
    sieve();
    return 0;
}

