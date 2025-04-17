#include <bits/stdc++.h>
#include <chrono>
using namespace std;

class Timer{
    chrono::system_clock::time_point start;
    public:
    Timer():start(chrono::system_clock::now()){}
    double count(){
        chrono::duration<double> Time_=chrono::system_clock::now()-start;
        return Time_.count();
    }
    bool isunder(double x){
        return (this -> count())<x;
    }
};

int main(){
    Timer timer;
    long long ans=0;
    for(int i=0;i<1e9;i++){
        ans++;
    }
    cout<<timer.count();
}