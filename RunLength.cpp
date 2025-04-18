//U
#include <bits/stdc++.h>
using namespace std;

template<typename v,typename val>
vector<pair<val,long long>> RunLength(v &vec,val tmp){
    vector<pair<val,long long>> ret;
    if((int)vec.size()==0){
        return ret;
    }
    ret.push_back(make_pair(vec[0],1));
    for(int i=1;i<(int)vec.size();i++){
        if(vec[i]==ret.back().first){
            ret.back().second++;
        }else{
            ret.push_back(make_pair(vec[i],1));
        }
    }
    return ret;
}

int main(){
    int N;
    cin>>N;
    vector<char> vec(N);
    for(int i=0;i<N;i++){
        cin>>vec[i];
    }
    vector<pair<char,long long>> ans=RunLength(vec,'a');
    for(auto pcl:ans){
        cout<<pcl.first<<" "<<pcl.second<<"\n";
    }
}   
