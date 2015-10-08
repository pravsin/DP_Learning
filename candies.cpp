#include<bits/stdc++.h>
using namespace std;

long  noCandies(vector<int> rating ){
    long n = rating.size();
    vector<int> candy1(n,0);
    candy1[0]=1;
    for (int i = 1; i < n; ++i) {
        if(rating[i]>rating[i-1])
            candy1[i]=candy1[i-1]+1;
        else
            candy1[i]=1;
    }
    reverse(rating.begin(),rating.end());
    vector<int> candy2(n,0);
    candy2[0]=1;
    for (int i = 1; i < n; ++i) {
        if(rating[i]>rating[i-1])
            candy2[i]=candy2[i-1]+1;
        else
            candy2[i]=1;
    }

    long sum =0;
    for (int j = 0; j < n; ++j) {
        sum+=max(candy1[j],candy2[n-j-1]);
    }
    return sum;
}

int maincandies(){
    int n;
    cin>>n;
    vector<int> rating(n);
    for (int i = 0; i < n; ++i) {
        cin>>rating[i];
    }
    cout<<noCandies(rating);
    return 0;
}
