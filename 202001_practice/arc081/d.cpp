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
const int mod=1e9+7;
int main()
{
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    int pre=-1;
    ll ans=1;
    for(int i=0;i<n;i++)
    {
        if(s[i]==t[i])
        {
            if(pre==-1) ans*=3;
            else if(pre==0)
                ans=ans*2%mod;
            pre=0;
        }
        else{
            if(pre==-1) ans*=6;
            else if(pre==0) ans=(ans*2)%mod;
            else ans=ans*3%mod;
            i++;
            pre=1;
        }
    }
    print(ans);
}