//U
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
template<class T> 
int search_min(vector<T> &vec, bool(*check)(T)){
    int N=(int)vec.size();
    int ok=N;
    int ng=-1;
    while(abs(ok-ng)>1){
        int mid=(ok+ng)/2;
        if(check(vec[mid])){
            ok=mid;
        }else{
            ng=mid;
        }
    }
    return ok;
}
template<class T>
int search_max(vector<T> &vec,bool(*check)(T)){
    int ok=-1;
    int ng=(int)vec.size();
    while(abs(ok-ng)>1){
        int mid=(ok+mid)/2;
        if(check(mid)){
            ok=mid;
        }else{
            ng=mid;
        }
    }
    return ok;
}
//以下半開区間[l,r)についての二分探索
ll search_min(ll l,ll r,bool(*check)(ll)){
    ll ok=r;
    ll ng=l-1;
    while(abs(ok-ng)>1){
        ll mid=ok/2+ng/2;
        if(check(mid)){
            ok=mid;
        }else{
            ng=mid;
        }
    }
    return ok;
}
ll search_max(ll l,ll r,bool(*check)(ll)){
    ll ok=l-1;
    ll ng=r;
    while(abs(ok-ng)){
        ll mid=ok/2+ng/2;
        if(check(mid)){
            ok=mid;
        }else{
            ng=mid;
        }
    }
    return ok;
}
int comp;
bool check(int ai){
    if(comp<=ai){
        return true;
    }
    return false;
}
int main(){
    int N;
    cin>>N>>comp;
    vector<int> A(N);
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    cout<<search_min(A,check);
}
