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
int maze[2005][2005];
int cur[2005][2005];
int main()
{
	int n;
	while(cin>>n)
	{
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&maze[i][j]);
	vector<int> ref;
	ref.push_back(0);
	for(int i=1,tmp;i<=n;i++)
	{
		scanf("%d",&tmp);
		ref.push_back(tmp);
	}
	bool ok=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j) continue;
			cur[i][j]=maze[i][j]^1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			if(cur[ref[i]][ref[j]]!=maze[i][j]) ok=0;
	}
	if(ok) puts("Accepted");
	else puts("Wrong Answer");
	}

}
