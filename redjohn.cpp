#include<bits/stdc++.h>
using namespace std;

vector<long long> dp(41,0);
vector<bool> primes;

void  calculateWays() {
    dp[0]=dp[1]=dp[2]=dp[3]=1;
    for (int i = 4; i < 41; ++i) {
        dp[i]= dp[i-1]+dp[i-4];
    }
}

void seive(){
    long long maxx= dp[40]+10;
    primes.resize(maxx,true);
    for (int i = 2; i*i <maxx; ++i) {
        if(primes[i]){
            for (int j = i*i; j < maxx;j+=i) {
                primes[j]=false;
            }
        }
    }
}

int mainredjohn(){
    int t;
    cin>>t;
    calculateWays();
    seive();
    while(t--){
        int n ;cin>>n;
        int count=0;
        for (int i = 2; i <= dp[n]; ++i) {
            if(primes[i])
                count++;
        }
        cout<<count<<"\n";
    }
    return 0;
}