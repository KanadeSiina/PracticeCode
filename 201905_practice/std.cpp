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
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		ll tar;
		cin>>n>>tar;
		if(n%2==1)
		{
			if(tar%2==0)
				cout<<"NO"<<endl;
			else cout<<"YES"<<endl;
		}
		else{
			tar%=n+1;
			if(tar==n||tar%2==1) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
	}
}