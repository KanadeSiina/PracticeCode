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
string s,t;
const int maxn=1e6+7;
int cnt[maxn];
int n,k;
string solve(string x)
{
	if(k==1) return "";
	string ret;
	vector<char> st;
	for(int i=0;i<n;i++)
	{
		if(!st.empty()&&st.back()==x[i])
		{
			cnt[st.size()-1]++;
			if(cnt[st.size()-1]==k) st.pop_back();
		}
		else{
			st.push_back(x[i]);
			cnt[st.size()-1]=1;
		}
	}
	for(int i=0;i<st.size();i++)
	{
		for(int j=0;j<cnt[i];j++)
			ret+=st[i];
	}
	return ret;
}
int main()
{
	cin>>n>>k;
	cin>>s>>t;
	if(solve(s)==solve(t))
		puts("Yes");
	else puts("No");

}