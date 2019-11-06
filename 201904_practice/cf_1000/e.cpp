#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
const int maxn=3e5+7;
vector<int> G[maxn],ng[maxn];
int dfn[maxn],low[maxn],bel[maxn];
int n,m;
int ti,scc;
stack<int> st;
void dfs(int u,int fa)
{
	dfn[u]=low[u]=++ti;
	st.push(u);
	for(auto v:G[u])
	{
		if(v==fa) continue;
		if(!dfn[v])
		{
			dfs(v,u);
			low[u]=min(low[u],low[v]);
		}
		else if(!bel[v])
			low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u])
	{
		scc++;
		while(1)
		{
			int t=st.top();st.pop();
			bel[t]=scc;
			if(u==t) break;
		}
	}
}
void DCC()
{
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			dfs(i,-1);
	for(int u=1;u<=n;u++)
	{
		for(auto& v:G[u])
		{
			if(bel[u]!=bel[v])
				ng[bel[u]].push_back(bel[v]);
		}
	}
}
typedef pair<int,int> PII;
PII dfsans(int u,int fa=-1)
{
	PII ret=make_pair(0,u);
	for(auto& v:ng[u])
	{
		if(v==fa) continue;
		PII cur=dfsans(v,u);
		ret=max(ret,make_pair(cur.first+1,cur.second));
	}
	return ret;
}
int solve()
{
	PII u=dfsans(1);
	PII v=dfsans(u.second);
	return v.first;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0,u,v;i<m;i++)
	{
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	DCC();
	printf("%d\n",solve());
}
