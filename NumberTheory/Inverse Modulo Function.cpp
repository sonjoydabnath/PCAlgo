// inverse modulo function


ll F(ll N,ll P,ll mod)
{
    if(P==0)
        return 1;

    ll ret=F(N,P/2,mod);

    if((P&1)==0)
        return ((ret%mod)*(ret%mod))%mod;

    else
        return ((N%mod)*(((ret%mod)*(ret%mod))%mod))%mod;

}

ll inverse_modulo(ll n,ll mod)
{
    ll p=mod-2;
    return F(n,p,mod);

}
