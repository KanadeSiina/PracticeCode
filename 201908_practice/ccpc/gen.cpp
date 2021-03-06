#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
#ifndef ONLINE_JUDGE
#define dbg(x...) do{cout << "\033[32;1m" << #x << "->" ; err(x);} while(0)
void err(){cout << "\033[39;0m" << endl;}
template<template<typename...> class T,typename t,typename... A>
void err(T<t> a,A... x){for (auto v:a) cout << v << ' '; err(x...);}
template<typename T,typename... A>
void err(T a,A... x){cout << a << ' '; err(x...);}
#else
#define dbg(...)
#endif
const int mod=998244353;
const int INF=0x3f3f3f3f;
ll quick(ll a,ll b)
{
	ll ret=1;
	while(b)
	{
		if(b&1)
			ret=ret*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ret;
}
ll inv(ll a){return quick(a,mod-2);}
int main()
{
	srand(time(NULL));
	const int mx=10000000;
	int T=3;
	cout<<T<<endl;
	while(T--)
	{
		int n=100000,q=100000;
		cout<<n<<" "<<q<<endl;
		for(int i=1;i<=n;i++)
			cout<<rand()%mx+1<<" ";
		cout<<endl;
		while(q--)
		{
			int l=rand()%n+1,r=rand()%n+1;
			if(l>r)swap(l,r);
			cout<<l<<" "<<r<<endl;
		}
	}
}
