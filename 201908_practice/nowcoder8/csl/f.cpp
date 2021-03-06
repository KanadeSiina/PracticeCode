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
const int maxn = 1000 + 7;
const int INF = 0x3f3f3f3f;
struct Edge
{
    int from, to, cap, flow;
};
struct Dinic
{
    int n, m, s, t;
    vector<Edge> edges;
    vector<int> G[maxn];
    bool vis[maxn];
    int d[maxn];
    int cur[maxn];

    void AddEdge(int from, int to, int cap, int c = 0)
    {
        edges.push_back(Edge{from, to, cap, 0});
        edges.push_back(Edge{to, from, c, 0});
        m = edges.size();
        G[from].push_back(m - 2);
        G[to].push_back(m - 1);
    }

    bool BFS()
    {
        memset(vis, 0, sizeof(vis));
        queue<int> q;
        q.push(s);
        d[s] = 0;
        vis[s] = 1;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int i = 0; i < G[u].size(); i++)
            {
                Edge &e = edges[G[u][i]];
                if (!vis[e.to] && e.cap > e.flow)
                {
                    vis[e.to] = 1;
                    d[e.to] = d[u] + 1;
                    q.push(e.to);
                }
            }
        }
        return vis[t];
    }
    int DFS(int u, int dist)
    {
        if (u == t || dist == 0)
            return dist;
        int flow = 0, f;
        for (int &i = cur[u]; i < G[u].size(); i++)
        {
            Edge &e = edges[G[u][i]];
            if (d[u] + 1 == d[e.to] && (f = DFS(e.to, min(dist, e.cap - e.flow))) > 0)
            {
                e.flow += f;
                edges[G[u][i] ^ 1].flow -= f;
                flow += f;
                dist -= f;
                if (!dist)
                    break;
            }
        }
        return flow;
    }
    int Maxflow(int s, int t)
    {
        this->s = s;
        this->t = t;
        int flow = 0;
        while (BFS())
        {
            memset(cur, 0, sizeof(cur));
            flow += DFS(s, INF);
        }
        return flow;
    }
};
char maze[35][35];
char newmaze[35][35];
int score[35];
int n;
void getscore()
{
	for(int i=0;i<n;i++)
	{
		score[i]=0;
		for(int j=0;j<n;j++)
		{
			if(newmaze[i][j]=='1') score[i]+=2;
			else if(newmaze[i][j]=='d') score[i]++;
		}
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%s",maze[i]);
	vector<int> ans;
	for(int i=0;i<n;i++)
	{
		for(int ii=0;ii<n;ii++)
		{
			for(int jj=0;jj<n;jj++)
				newmaze[ii][jj]=maze[ii][jj];
		}
		for(int j=0;j<n;j++)
		{
			if(newmaze[i][j]=='.') 
			{
				newmaze[i][j]='1';
				newmaze[j][i]='0';
			}
		}
		getscore();
		bool ok=1;
		for(int j=0;j<n;j++)
		{
			if(score[j]>score[i])
				ok=0;
		}
		if(!ok) continue;
		Dinic F;
		int S=n+n*n+1,T=S+1;
		for(int j=0;j<n;j++)
			F.AddEdge(j,T,score[i]-score[j]);
		int tot=0;
		for(int ii=0;ii<n;ii++)
		{
			for(int jj=0;jj<ii;jj++)
			{
				if(newmaze[ii][jj]=='.')
				{
					F.AddEdge(S,n+ii*n+jj,2);
					tot+=2;
					F.AddEdge(n+ii*n+jj,ii,INF);
					F.AddEdge(n+ii*n+jj,jj,INF);
				}
			}
		}
		if(F.Maxflow(S,T)==tot) ans.push_back(i);
	}
	for(auto u:ans) printf("%d ",u+1);
	puts("");

}
