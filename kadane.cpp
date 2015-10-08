#include<bits/stdc++.h>
using namespace std;
void maxSumArr(vector<int> arr){
    int n = (int) arr.size();
    int max_end,max_so;
    max_end= max_so= arr[0];
    for (int i = 1; i <n; ++i) {
        max_end= max(arr[i],max_end+arr[i]);
        max_so= max(max_end,max_so);

    }
    cout<<max_so;
}

int mainkadane(){
    int t;
    cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin>>arr[i];
        }
        maxSumArr(arr);
    }
}