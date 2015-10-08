#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin>>a[i];
        }
        sort(a.begin(),a.end());
        vector<int> dp(k+10,0);
        for (int i = 1; i <= k; ++i) {
            for (int j = 0; j < a.size(); ++j) {
                if(a[j]>i)continue;
                dp[i]= max(dp[i],a[j]+dp[i-a[j]]);
            }
        }
        cout<<dp[k]<<"\n";
    }
    return 0;
}