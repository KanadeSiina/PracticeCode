#include<bits/stdc++.h>
using namespace std;
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
typedef long long ll;
typedef pair<int,int> PII;
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
const int INF=0x3f3f3f3f;

const int maxn=1e5+7;
int nxt[maxn];
bool vis[maxn];
PII a[maxn],b[maxn];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++) 
	{
		cin>>a[i].first;
		a[i].second=i;
	}
	for(int i=0;i<n;i++) 
	{
		cin>>b[i].first;
		b[i].second=i;
	}
	sort(a,a+n);
	sort(b,b+n);
	int ok=1;
	for(int i=0;i<n;i++)
	{
		if(b[i].first<a[i].first) 
		{
			ok=0;
			break;
		}
		if(i&&b[i-1].first>=a[i].first) ok=2;
	}
	if(ok)
	{
		int cc=0;
		int cur=0;
		for(int i=0;i<n;i++)
			nxt[a[i].second]=b[i].second;
		while(!vis[cur])
		{
			vis[cur]=1;
			cc++;
			cur=nxt[cur];
		}
		if(cc<=n-1) cout<<"Yes\n";
		else if(cc==n&&ok==2) cout<<"Yes\n";
		else cout<<"No\n";
	}
	else{
		cout<<"No\n";
	}
}
