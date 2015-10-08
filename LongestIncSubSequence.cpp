#include<bits/stdc++.h>
using namespace std;

void LongestIncSubSeq(vector<int> arr){
    /*if you want only the length of LIS
    int n = (int) arr.size();
    set<int> s; // for LDS use set<int, greater<int>> s;
    set<int>::iterator k;
    for (int i=0;i<n;i++)
    {
        if (s.insert(arr[i]).second)
        {
           k = s.find(arr[i]);
           k++;
           if (k!=s.end())
              s.erase(k);
        }
    }
    cout<< s.size();
     */
    int n = (int) arr.size();
    map<int,int> m;                     // For LDS use map<int,int,greater<int> > m;
    vector<int> pre(n,-1),res;
    map<int,int>::iterator k,l;
    for (int i = 0; i < n; ++i) {
        if(m.insert(make_pair(arr[i],i)).second){
            k = m.find(arr[i]);
            l = k;
            k++;
            if(l == m.begin()){
                pre[i]=-1;
            }
            else{
                l--;
                pre[i]= l->second;
            }
            if(k!=m.end())
                m.erase(k);
        }
    }
    k = m.end();
    k--;
    int j = k->second;
    while(j!=-1){
        res.push_back(arr[j]);
        j = pre[j];
    }
    reverse(res.begin(),res.end());
    //return res;
    for (int i1 = 0; i1 < res.size(); ++i1) {
        cout<<res[i1]<<" ";
    }
}

int mainliss() {

    vector<int> arr{-7, 9, 10, 2, 3, 8, 8, 1};
    LongestIncSubSeq(arr);
    return 0;
}
