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
const int maxn=1e5+7;
int ans=0;
int k;
int vis[50][maxn];
void dfs(int sum,int rem)
{
    if(sum>ans) return;
    if(vis[sum][rem]) return;
    if(!rem&&sum) ans=min(ans,sum);
    vis[sum][rem]=1;
    for(int j=0;j<10;j++)
    {
        if(sum==0&&j==0) continue;
        dfs(sum+j,(rem*10+j)%k);
    }
}
int main()
{
    cin>>k;
    int tmp=k;
    while(tmp)
    {
        ans+=tmp%10;
        tmp/=10;
    }
    dfs(0,0);
    print(ans);
}