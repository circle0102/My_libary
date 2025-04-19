//U
#include <bits/stdc++.h>
using namespace std;

struct modint{
    using ll=long long;
    ll mod=998244353;
    ll num=0;
    modint(){
        mod=998244353;
        num=0;
    }
    modint(ll n){
        num=n;
        mod=998244353;
    }
    modint(ll n,ll m){
        mod=m;
        num=n;
    }
    operator long long(){
        return num;
    }
    void operator=(ll n){
        num=n;
    }
    void operator+=(ll add){
        num+=add;
    }
    void operator-=(ll sub){
        num-=sub;
    }
    void operator*=(ll tim){
        num*=tim%mod;
        num%=mod;
    }
    bool operator==(ll other){
        return num==other%mod;
    }
    bool operator!=(ll other){
        return num!=other%mod;
    }
    bool operator<(ll other){
        return num<other;
    }
    
};

int main(){
    
}
