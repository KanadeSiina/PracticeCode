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
int main()
{
	int n;
	string s;
	cin>>n>>s;
	int mi=0;
	int cur=0;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='-') cur--;
		else cur++;
		mi=min(mi,cur);
	}
	cout<<cur-mi<<endl;
}
