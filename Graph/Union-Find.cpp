//U
#include <bits/stdc++.h>
using namespace std;

struct UnionFind{
    int N;
    vector<int> par,rank,siz;
    int cnt=0;
    UnionFind(int n){
        assert(0<=n);
        N=n;
        cnt=n;
        par.resize(N,-1);
        rank.resize(N,0);
        siz.resize(N,1);
    }
    int leader(int x){
        assert(0<=x && x<N);
        if(par[x]==-1){
            return x;
        }else{
            return par[x]=leader(par[x]);
        }
    }
    bool same(int x,int y){
        assert(0<=x && x<N);
        assert(0<=y && y<N);
        return leader(x)==leader(y);
    }
    int merge(int x,int y){
        assert(0<=x && x<N);
        assert(0<=y && y<N);
        int rx=leader(x);
        int ry=leader(y);
        if(rx==ry){
            return rx;
        }
        cnt--;
        if(rank[rx]<rank[ry]){
            swap(rx,ry);
        }
        par[ry]=rx;
        if(rank[rx]==rank[ry]){
            rank[rx]++;
        }
        siz[rx]+=siz[ry];
        return leader(x);
    }
    int size(int x){
        assert(0<=x && x<N);
        return siz[leader(x)];
    }
    int size(){
        return N;
    }
    void insert(){
        rank.push_back(0);
        par.push_back(-1);
        siz.push_back(1);
        N++;
        cnt++;
        return;
    }
    vector<vector<int>> groups(){
        vector<vector<int>> member(N);
        for(int v=0;v<N;v++){
            member[leader(v)].push_back(v);
        }
        vector<vector<int>> res;
        for(int v=0;v<N;v++){
            if(!member[v].empty()){
                res.push_back(member[v]);
            }
        }
        return res;
    }
    int cnt_groups(){
        return cnt;
    }
};
