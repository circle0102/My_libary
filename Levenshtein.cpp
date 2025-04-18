//U
#include <bits/stdc++.h>
using namespace std;

int LP(string &s,string &t){
    int j=1,k=1;
    vector<vector<int>> dp((int)s.size()+5,vector<int>((int)t.size()+5));
    for(j=1;j<=(int)s.size();j++){
        dp[j][0]=j;
    }
    for(k=1;k<=(int)t.size();k++){
        dp[0][k]=k;
    }
    for(j=1;j<=(int)s.size();j++){
        for(k=1;k<=(int)t.size();k++){
            int m=min(dp[j-1][k]+1,dp[j][k-1]+1);
            if(s[j-1]==t[k-1]){
                m=min(m,dp[j-1][k-1]);
                dp[j][k]=m;
            }else{
                m=min(m,dp[j-1][k-1]+1);
                dp[j][k]=m;
            }
        }
    }
    return dp[s.size()][t.size()];
}

int main(){
    string s,t;
    cin>>s>>t;
    cout<<LP(s,t);
}
