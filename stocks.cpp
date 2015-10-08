#include<bits/stdc++.h>
using namespace std;

int mainstocks(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> shares(n);
        for (int i = 0; i < n; ++i) {
            cin>>shares[i];
        }
        long long profit=0,maxp=shares[n-1];
        for (int j = n-1; j >=0; --j) {
            if(shares[j]> maxp)
                maxp= shares[j];
            else if(shares[j]<= maxp)
                profit+=maxp-shares[j];
        }
        cout<<profit<<"\n";
    }
}