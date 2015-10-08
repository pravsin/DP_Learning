#include<bits/stdc++.h>
using namespace std;

int mainequal(){
    int t;
    cin>>t;
    while(t--){
        int n ;
        cin>>n;
        vector<int> choco(n);
        int min=100000;
        for (int i = 0; i < n; ++i) {
            cin>>choco[i];
            if(choco[i] < min)
                min = choco[i];
        }
        long ans = 0;
        for (int j = 0; j < n; ++j) {
            int a= choco[j]- min;
            ans +=a/5;
            a%=5;
            ans+=a/2;
            a%=2;
            ans+=a;
        }
        int ans1=0;
        for (int j = 0; j < n; ++j) {
            int a= choco[j];
            ans1 +=a/5;
            a%=5;
            ans1+=a/2;
            a%=2;
            ans1+=a;
        }
        cout<<((ans>ans1)?ans1:ans)<<"\n";
    }
    return 0;
}