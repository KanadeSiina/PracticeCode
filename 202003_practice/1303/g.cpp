#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define dbg(x...) do { cout << "\033[32;1m " << #x << " -> "; err(x); } while (0)
void err() { cout << "\033[39;0m" << endl; }
template<template<typename...> class T, typename t, typename... A>
void err(T<t> a, A... x) { for (auto v: a) cout << v << ' '; err(x...); }
template<typename T, typename... A>
void err(T a, A... x) { cout << a << ' '; err(x...); }
#else
#define dbg(...)
#endif
typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
template<class T> using vc=vector<T>;
template<class T> using vvc=vc<vc<T>>;
template<class T> void mkuni(vector<T>&v)
{
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
}
ll rand_int(ll l, ll r) //[l, r]
{
    static mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
    return uniform_int_distribution<ll>(l, r)(gen);
}
template<class T>
void print(T x,int suc=1)
{
    cout<<x;
    if(suc==1) cout<<'\n';
    else cout<<' ';
}
template<class T>
void print(const vector<T>&v,int suc=1)
{
    for(int i=0;i<v.size();i++)
    print(v[i],i==(int)(v.size())-1?suc:2);
}
const int maxn=150000+7;
vi G[maxn];
ll sum[maxn];
int dep[maxn];
map<int,ll> dp[maxn];
vi leaf[maxn];
int a[maxn];
void dfs(int u,ll pre=0,int fa=-1,int d=0)
{
    pre+=a[u];
    sum[u]=pre;
    dep[u]=d;
    for(auto v:G[u])if(v!=fa)
        dfs(v,pre,u,d+1);
}
ll ans=0;
void solve(int u,int fa=0)
{
    for(auto v:G[u]) if(v!=fa)
    {
        dfs(v,u);
        for(auto x:leaf[u])
        {
            ll ss=sum[x]-sum[fa];
            for(auto y:dp[v])
            {

            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=1,u,v;i<n;i++)
    {
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i=1;i<=n;i++) cin>>a[i];
    dfs(1);
    solve(1);
    print(ans);
}