#include <bits/stdc++.h>
using namespace std;

long long findNoOfCoins(long long sum,const vector<int> &coins){
    vector<int> minCoins(sum+1,INT_MAX-10);
    vector<int> coinDem(sum+1,-1);
    minCoins[0]=0;
    coinDem[0]=0;
    for (int i = 1; i <= sum; ++i) {
        for (int j = 0; j < coins.size(); ++j) {
            if(coins[j]<= i && minCoins[i-coins[j]]+1 < minCoins[i]) {
                minCoins[i] = minCoins[i - coins[j]] + 1;
                coinDem[i]= coins[j];
            }
        }
    }
    int s = sum;
    while(s){
        cout<<coinDem[s]<<" ";
        s-=coinDem[s];
    }
    cout<<"\n";
    return minCoins[sum];
}


int main1() {
    vector<int> coins{1,3,5};
    long long sum =11;
    cout<<findNoOfCoins(sum, coins);
    return 0;
}