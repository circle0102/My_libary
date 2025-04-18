//U
#include <bits/stdc++.h>
using namespace std;

template<typename T> struct sum_vec{
    vector<T> data;
    vector<T> sum;
    int N;
    sum_vec(const vector<T> &vec){
        int N=vec.size();
        data.resize(N);
        sum.resize(N+1,0);
        for(int i=0;i<N;i++){
            data[i]=vec[i];
            sum[i+1]=sum[i]+data[i];
        }
    }
    sum_vec(int n){
        N=n;
        data.resize(N,0);
        sum.resize(N,0);
    }
    sum_vec(){
        N=0;
    }
    void cal(){
        sum[0]=0;
        for(int i=0;i<N;i++){
            sum[i+1]=data[i]+sum[i];
        }
        return;
    }
    T cul_sum(int l,int r){
        return sum[r]-sum[l];
    }
    void push_back(T x){
        data.push_back(x);
        T b=sum.back();
        sum.push_back(b+x);
        N++;
    }
    void pop_back(){
        assert(1<=(int)data.size());
        data.pop_back();
        sum.pop_back();
    }
};

int main(){
    
}
