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
int ans[2005][2005];
int main()
{
	int T,kas=0;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		memset(ans,0,sizeof(ans));
		printf("Case #%d: ",++kas);
		int tot=n*(n-1)/2;
		if(tot%2!=0) {puts("No");}
		else {
			puts("Yes");
			if(n%4==0)
			{
				for(int i=1;i<=n/4;i++)
				{
					for(int j=n/4+1;j<=n/2;j++)
						ans[i][j]=ans[j][i]=1;
					for(int j=i+1;j<=n/4;j++)
						ans[i][j]=ans[j][i]=1;
					for(int j=n/2+1;j<=n/4*3;j++)
						ans[i][j]=ans[j][i]=1;
				}
				for(int i=n/4+1;i<=n/2;i++)
				{
					for(int j=n/4*3+1;j<=n;j++)
						ans[i][j]=ans[j][i]=1;
					for(int j=i+1;j<=n/2;j++)
						ans[i][j]=ans[j][i]=1;
				}
			}
			else{
				for(int i=1;i<=n/4;i++)
				{
					for(int j=n/4+1;j<=n/2;j++)
						ans[i][j]=ans[j][i]=1;
					for(int j=i+1;j<=n/4;j++)
						ans[i][j]=ans[j][i]=1;
					for(int j=n/2+1;j<=n/4*3;j++)
						ans[i][j]=ans[j][i]=1;
				}
				for(int i=n/4+1;i<=n/2;i++)
				{
					for(int j=n/4*3+1;j<=n;j++)
						ans[i][j]=ans[j][i]=1;
					for(int j=i+1;j<=n/2;j++)
						ans[i][j]=ans[j][i]=1;
				}
				for(int i=1;i<=n/2;i++)
					ans[n][i]=ans[i][n]=1;
			}
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{//if (ans[i][j])cout << i <<" " << j << endl;
					printf("%d",ans[i][j]);
				}
				puts("");
			}
			/*
			for(int i=1;i<=n/4;i++)
				printf("%d ",n/4*3+i);
			for(int i=1;i<=n/4;i++)
				printf("%d ",n/2+i);
			for(int i=1;i<=n/4;i++)
				printf("%d ",i);
			for(int i=1;i<=n/4;i++)
				printf("%d%c",i+n/4,(i==n/4&&n%4==0)?'\n':' ');
			if(n%4==1) printf("%d\n",n);
			else puts("");
			*/
			vector<int> ou;
			for (int i = 1; i <= n / 4; i++) ou.push_back(n / 4 *  3 + i);
			for (int i = 1; i <= n / 4; i++) ou.push_back(n / 2 + i);
			for (int i = 1; i <= n / 4; i++) ou.push_back(i);
			for (int i = 1; i <= n / 4; i++) ou.push_back(n/4 + i);
			if (n % 4 == 1) ou.push_back(n);
			for (int i = 0; i < n; i++) printf("%d%c", ou[i], (i == n - 1) ? '\n' : ' ');
		}
	}
}
