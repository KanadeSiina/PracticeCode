#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#ifndef ONLINE_JUDGE
#define dbg(x...) do{cout << "\033[33;1m" << #x << "->" ; err(x);} while(0)
void err(){cout << "\033[39;0m" << endl;}
template<template<typename...> class T,typename t,typename... A>
void err(T<t> a,A... x){for (auto v:a) cout << v << ' '; err(x...);}
template<typename T,typename... A>
void err(T a,A... x){cout << a << ' '; err(x...);}
#else
#define dbg(...)
#endif
priority_queue<int> q;
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0,tmp;i<n;i++)
	{
		scanf("%d",&tmp);
		q.push(tmp);
	}
	queue<int> qq;
	for(int i=0,tmp;i<n;i++)
	{
		scanf("%d",&tmp);
		qq.push(tmp);
	}
	:wq

}
