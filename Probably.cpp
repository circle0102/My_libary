#include<bits/stdc++.h>
#include <random>
using namespace std;
bool prob(double p){
  static mt19937_64 mt64(0);
  uniform_real_distribution<double> uni(0.0, 1.0);
  if(p>=uni(mt64)){
    return true;
  }
  return false;
}

int main(){
    for(int i=0;i<1000;i++){
        cout<<prob(0.01)<<'\n';
    }
}